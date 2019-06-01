#include "serveur_jeux.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serveur_jeux w;
    w.show();

    return a.exec();
}
