#ifndef CIRCLEHANDLER_H
#define CIRCLEHANDLER_H

#include <iostream>

using std::pair;

/*
 * essa classe vai pegar um conjunto de objetos (com posições e tempos de vida) e gerencialos.
 * quando o tempo for passando, alguns objetos devem receber uma nova posição (caso o tempo de vida seja expirado)
 *
 *
 */

class circleHandler {
private:
    struct object {
        pair<int, int> position;
        float timeLive;
        bool isAlive;
    };
    object *objects;

public:
    int n_objects, seed;
    float time_step;

    circleHandler(unsigned n_objects = 4, int seed = 777, float time_step = 0.002);
    ~circleHandler();

    inline bool getAlive(unsigned i) { return this->objects[i].isAlive; }
    inline pair<int, int> getPosition(unsigned i) { return this->objects[i].position; }
    inline float getTimeLive(unsigned i) { return this->objects[i].timeLive; }

    bool intersectionWithSomeObj(pair<int, int> pos, unsigned id);
    void killObject(unsigned i);
    void initObject(unsigned i, unsigned win_width, unsigned win_height); // tras um objeto a vida
    unsigned run(); // roda o circleHandler por um instante de tempo e retorna o numero de objetos expirados no tempo
};

#endif // CIRCLEHANDLER_H
