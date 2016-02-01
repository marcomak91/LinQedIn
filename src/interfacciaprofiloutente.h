#ifndef INTERFACCIAPROFILOUTENTE_H
#define INTERFACCIAPROFILOUTENTE_H

#include"utente.h"
#include<QWidget>

namespace Ui
{
class InterfacciaProfiloUtente;
}

class InterfacciaProfiloUtente : public QWidget
{
    Q_OBJECT

public:
    explicit InterfacciaProfiloUtente(Utente*, QWidget *parent = 0);
    ~InterfacciaProfiloUtente();

private slots:
    void on_ChiudiButton_clicked();

private:
    Ui::InterfacciaProfiloUtente *ui;
    Utente* ut;
    void caricaProfilo();
};

#endif // INTERFACCIAPROFILOUTENTE_H
