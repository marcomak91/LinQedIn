#ifndef INTERFACCIAADMIN_H
#define INTERFACCIAADMIN_H

#include<QWidget>
#include"utente.h"
#include"linqedinadmin.h"

namespace Ui
{
class InterfacciaAdmin;
}

class InterfacciaAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit InterfacciaAdmin(LinQedInAdmin* , QWidget *parent = 0);
    ~InterfacciaAdmin();

private slots:
    void on_InserisciNuovoUtenteButton_clicked();
    void on_EliminaUtenteButton_clicked();
    void on_CambiaTipoAccountButton_clicked();
    void on_CercaButton_clicked();
    void on_VisualizzaUtentiIscrittiButton_clicked();
    void on_ChiudiButton_clicked();

private:
    Ui::InterfacciaAdmin *ui;
    LinQedInAdmin* admin;
    //vector<vector<Utente*>::const_iterator> vettoreIt; //nella ricerca, serve per salvare gli iteratori ai risultati della ricerca
    void eliminaUtente();
    void cambiaTipoAccount();
    void cerca();
    void visualizzaUtentiIscritti();
};

#endif // INTERFACCIAADMIN_H
