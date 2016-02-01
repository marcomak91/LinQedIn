#include<QMessageBox>
#include"rete.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"

Rete::Rete() {}

const vector<Utente*>* Rete::getRete() const
{
    return &rete;
}

void Rete::aggiungi(Utente* u)
{
    rete.push_back(u);
}

void Rete::elimina(string u)
{
    bool eliminato=false;
    for(vector<Utente*>::iterator it = rete.begin(); it!=rete.end() && !eliminato; it++)
    {
        if((*it)->getUsername()->login==u)
        {
            rete.erase(it);
            QMessageBox msg;
            msg.setText("Utente eliminato");
            msg.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            msg.exec();
            eliminato=true;
        }
    }
    if(!eliminato)
    {
        QMessageBox err;
        err.setText("Utente non presente nella tua rete");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
}

QString Rete::getAmici(const vector<Utente*>& d) const // gli passo per parametro un vettore contenente il DB aggiornato in modo da restituire solo gli utenti esistenti, e non anche quelli che potrebbero essere stati eliminati dal DB

{
    QString amici="";
    for(vector<Utente*>::const_iterator it=rete.begin(); it!=rete.end(); it++)
    {
       for(vector<Utente*>::const_iterator it1=d.begin(); it1!=d.end(); it1++)
       {
           if(*it==*it1) // qui vengono scartati, eventualmente, anche gli utenti eliminati dal DB
           {
               if(amici.size()!=0)
                   amici=amici+","+QString::fromStdString((*it)->getUsername()->login);
               else // è il primo elemento
                   amici=QString::fromStdString((*it)->getUsername()->login);
           }
       }
    }
    return amici;
}

bool Rete::controllaAmico(string l) const
{
    for(vector<Utente*>::const_iterator it=rete.begin(); it!=rete.end(); it++)
    {
        if(l==(*it)->getUsername()->login)
        {
            return true;
        }
    }
    return false;
}
