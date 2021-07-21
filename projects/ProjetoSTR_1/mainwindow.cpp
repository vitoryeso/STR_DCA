#include "mainwindow.h"
#include "sys/time.h"
#include "circleHandler.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    gettimeofday(&this->initTime, nullptr);
    ui->setupUi(this);
    startTimer(1);
    this->score = 0;
    this->n_events = 0;
    this->reaction_time_sum = 0.0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event) {
    timeval T;
    gettimeofday(&T, nullptr);

    int time_s = (int) (T.tv_sec - this->initTime.tv_sec);
    int rand_int;

    std::string time_str = "tempo: " + std::to_string(T.tv_sec - this->initTime.tv_sec) + "." + std::to_string(T.tv_usec/10000);

    ui->label->setText(time_str.c_str());
    ui->lcdNumber->display(this->score);
    ui->lcdNumber_2->display(this->reaction_time_sum / this->n_events);

    this->update();

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    std::vector<Qt::GlobalColor> colors { Qt::red, Qt::green, Qt::blue, Qt::yellow };
    QPainter painter(this);
    pair<int, int> position;
    int rand_int;
    std::string time_str;

    for (unsigned i=0; i<handler.n_objects; i++) {
        if (handler.getAlive(i)) {
            position = handler.getPosition(i);
            painter.setBrush(colors[i]);
            painter.drawEllipse(QPoint(position.first, position.second), 20, 20);
        }
        else {
            rand_int = rand() % 10000 + 1;

           // std::cout << "RAND INT: " << rand_int << std::endl;
            if ( rand_int > 9998 ) {
                time_str = "i: " + std::to_string(i) + " rand_int: " + std::to_string(rand_int);
                handler.initObject(i, this->width(), this->height());
            }
        }
    }
    this->n_events += handler.run();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Up: // red
            if (handler.getAlive(0)) {
                this->reaction_time_sum += handler.getTimeLive(0);
                this->score += 1;
                this->n_events += 1;
                handler.killObject(0);
            }
            break;

        case Qt::Key_Down: // green
            if (handler.getAlive(1)) {
                this->reaction_time_sum += handler.getTimeLive(1);
                this->score += 1;
                this->n_events += 1;
                handler.killObject(1);
            }
            break;

        case Qt::Key_Left: // blue
            if (handler.getAlive(2)) {
                this->reaction_time_sum += handler.getTimeLive(2);
                this->score += 1;
                this->n_events += 1;
                handler.killObject(2);
            }
            break;

        case Qt::Key_Right: // yellow
            if (handler.getAlive(3)) {
                this->reaction_time_sum += handler.getTimeLive(3);
                this->score += 1;
                this->n_events += 1;
                handler.killObject(3);
            }
            break;
    }
    std::cout <<  "accumulated time: " << this->reaction_time_sum << std::endl;
    std::cout <<  "circle counts: " << this->n_events << std::endl;
}

