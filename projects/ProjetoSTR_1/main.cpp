#include "mainwindow.h"

#include <QApplication>
#include <QPainter>
#include <sys/time.h>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;

  w.setWindowTitle("Jogo Reação temporal !");
  w.show();

  return a.exec();
}
