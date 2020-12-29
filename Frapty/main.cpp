#include <QtWidgets>
#include "Viewport.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFrame frame;
    frame.setWindowTitle("Qt SFML");
    frame.resize(400, 400);
    frame.show();

    Viewport t(&frame, QPoint(20, 20), QSize(150,150));

    t.resize(500, 500);

    t.show();

    return a.exec();
}