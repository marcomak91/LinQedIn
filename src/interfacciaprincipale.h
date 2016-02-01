#ifndef INTERFACCIAPRINCIPALE_H
#define INTERFACCIAPRINCIPALE_H

#include<QMainWindow>
#include"linqedinadmin.h"

namespace Ui
{
class InterfacciaPrincipale;
}

class InterfacciaPrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterfacciaPrincipale(QWidget *parent = 0);
    ~InterfacciaPrincipale();

private slots:
    void on_LoginButton_clicked();
    void on_AdminButton_clicked();

private:
    Ui::InterfacciaPrincipale *ui;
    void creaUtente();
    void creaAdmin();
};

#endif // INTERFACCIAPRINCIPALE_H
