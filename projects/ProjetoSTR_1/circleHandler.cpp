#include "circleHandler.h"
#include <time.h>
#include <math.h>

using std::pair;
using std::pow;
using std::cout;
using std::endl;

pair<int, int> gen_new_position(int seed, unsigned max_x, unsigned max_y) {
    srand ( seed );
    pair<int, int> prov;
    int n;
    /* generate secret number between 1 and 10: */
    prov.first = rand() % max_y + 1;
    prov.second = rand() % max_x + 1;

    cout << prov.first << " " << prov.second << endl;

    return prov;
}

void circleHandler::killObject(unsigned i) {
    if (i < this->n_objects) {
        this->objects[i].position = pair<int, int>(0, 0);
        this->objects[i].timeLive = 0.0;
        this->objects[i].isAlive = false;
    }
}

circleHandler::circleHandler(unsigned n_objects, int seed, float time_step)
{
    if (n_objects > 0) {
        this->objects = new object[n_objects];

        for (unsigned i=0; i<n_objects; i++) {
            this->objects[i].position = pair<int, int>(0, 0);
            this->objects[i].timeLive = 0.0;
            this->objects[i].isAlive = false;
        }

        this->n_objects = n_objects;
        this->seed = seed;
        this->time_step = time_step;
    }
    else {
        this->n_objects = 0;
        this->objects = nullptr;
        this->seed = seed;
        this->time_step = time_step;
    }
}

circleHandler::~circleHandler()
{
    if (this->n_objects > 0) {
        this->n_objects = 0;
        delete this->objects;
    }
}

bool circleHandler::intersectionWithSomeObj(pair<int, int> pos, unsigned id) {
    pair<int, int> prov_pos;
    int x_distance, y_distance;
    for (unsigned i=0; i<this->n_objects; i++) {
        if (i != id)
          prov_pos = this->getPosition(i);
          x_distance = abs(prov_pos.first - pos.first);
          y_distance = abs(prov_pos.second - pos.second);
          if ( x_distance <= 10 || y_distance <= 10 ) return true;
    }

    return false;
}

void circleHandler::initObject(unsigned i, unsigned win_width, unsigned win_height) {
    pair<int, int> prov_pos;
    if (i < this->n_objects) {
        this->objects[i].isAlive = true;
        srand ( (unsigned) time(NULL));
        prov_pos = gen_new_position(this->seed * (i + rand()), win_width, win_height);

        /*
        while(intersectionWithSomeObj(prov_pos, i)) {
          prov_pos = gen_new_position(this->seed, win_width, win_height);
          cout << "new position (" << prov_pos.first << ", " << prov_pos.second << ") " << endl;
        }
        */

        this->objects[i].position = prov_pos;
    }
}

unsigned circleHandler::run()
{
    unsigned killed_objecs(0);
    if (this->n_objects == 0) return 0;
    for (unsigned i=0; i<this->n_objects; i++) {
        if (this->objects[i].isAlive) {
            if (this->objects[i].timeLive >= 3.0) {
                killObject(i);
                killed_objecs += 1;
            }
            else {
                this->objects[i].timeLive += this->time_step;
            }
        }
    }
    return killed_objecs;
}
