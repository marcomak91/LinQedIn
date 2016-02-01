#ifndef INTERFACCIAMODIFICAPROFILO_H
#define INTERFACCIAMODIFICAPROFILO_H

#include<QWidget>
#include"linqedinclient.h"

namespace Ui
{
class InterfacciaModificaProfilo;
}

class InterfacciaModificaProfilo : public QWidget
{
    Q_OBJECT

public:
    explicit InterfacciaModificaProfilo(LinQedInClient*, QWidget *parent = 0);
    ~InterfacciaModificaProfilo();

private slots:
    void on_ConfermaModificheButton_clicked();
    void on_AnnullaButton_clicked();

private:
    Ui::InterfacciaModificaProfilo *ui;
    LinQedInClient* clientM;
    void caricaProfilo();
    void modificaProfilo();
};

#endif // INTERFACCIAMODIFICAPROFILO_H
