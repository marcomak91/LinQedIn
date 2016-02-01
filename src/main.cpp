#include<QApplication>
#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include<QGridLayout>
#include<QDesktopWidget>
#include"interfacciaprincipale.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    InterfacciaPrincipale w;
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();
    return app.exec();
}

