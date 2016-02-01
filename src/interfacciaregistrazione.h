#ifndef INTERFACCIAREGISTRAZIONE_H
#define INTERFACCIAREGISTRAZIONE_H

#include<QWidget>
#include"linqedinadmin.h"

namespace Ui
{
class InterfacciaRegistrazione;
}

class InterfacciaRegistrazione : public QWidget
{
    Q_OBJECT

public:
    explicit InterfacciaRegistrazione(LinQedInAdmin*, QWidget *parent = 0);
    ~InterfacciaRegistrazione();

private slots:
    void on_RegistratiButton_clicked();
    void on_AnnullaButton_clicked();

private:
    Ui::InterfacciaRegistrazione *ui;
    LinQedInAdmin* adminR;
    void registra();
};

#endif // INTERFACCIAREGISTRAZIONE_H
