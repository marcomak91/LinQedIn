#ifndef INTERFACCIAPROFILOAMICO_H
#define INTERFACCIAPROFILOAMICO_H

#include<QWidget>
#include<vector>

using std::vector;
using std::string;

namespace Ui
{
class InterfacciaProfiloAmico;
}

class InterfacciaProfiloAmico : public QWidget
{
    Q_OBJECT

public:
    explicit InterfacciaProfiloAmico(vector<string>, QWidget *parent = 0);
    ~InterfacciaProfiloAmico();

private slots:
    void on_ChiudiButton_clicked();

private:
    Ui::InterfacciaProfiloAmico *ui;
    vector<string> profilo;
    void caricaProfiloAmico();
};

#endif // INTERFACCIAPROFILOAMICO_H
