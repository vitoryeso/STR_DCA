#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include "circleHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using std::pair;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    timeval initTime;
    Ui::MainWindow *ui;
    circleHandler handler;
    int score;
    int n_events;
    float reaction_time_sum;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // MAINWINDOW_H
