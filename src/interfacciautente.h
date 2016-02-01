#ifndef INTERFACCIAUTENTE_H
#define INTERFACCIAUTENTE_H

#include<QWidget>
#include"linqedinclient.h"

namespace Ui
{
class InterfacciaUtente;
}

class InterfacciaUtente : public QWidget
{
    Q_OBJECT

public:
    explicit InterfacciaUtente(LinQedInClient*, QWidget *parent = 0);
    ~InterfacciaUtente();

private slots:
    void on_VisualizzaProfiloButton_clicked();
    void on_ModificaProfiloButton_clicked();
    void on_AggiungiAmicoButton_clicked();
    void on_EliminaAmicoButton_clicked();
    void on_CercaButton_clicked();
    void on_VisualizzaAmiciButton_clicked();
    void on_VisualizzaUtentiIscrittiButton_clicked();
    void on_LogoutButton_clicked();

private:
    Ui::InterfacciaUtente *ui;
    LinQedInClient* client;
    void cerca();
    void aggiungiAmico();
    void eliminaAmico();
    void visualizzaAmici();
    void visualizzaUtentiIscritti();
};

#endif // INTERFACCIAUTENTE_H
