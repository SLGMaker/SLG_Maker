#include <QApplication>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "MagicTowerScene.h"
#include "SLGCGameUnit.h"
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    MagicTowerScene scene;
    return app.exec();
}
