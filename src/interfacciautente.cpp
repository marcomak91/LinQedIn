#include<QMessageBox>
#include<QDesktopWidget>
#include"interfacciautente.h"
#include"ui_interfacciautente.h"
#include"interfacciaprofiloutente.h"
#include"interfacciaprofiloamico.h"
#include"interfacciamodificaprofilo.h"
#include"rete.h"

InterfacciaUtente::InterfacciaUtente(LinQedInClient* lC, QWidget *parent) :
    QWidget(parent), ui(new Ui::InterfacciaUtente), client(lC)
{
    ui->setupUi(this);
    QString nomeUtente=QString::fromStdString(client->getUtente()->getUsername()->login);
    ui->BenvenutoLabel->setText("Benvenuto "+nomeUtente);
}

InterfacciaUtente::~InterfacciaUtente()
{
    delete ui;
}

void InterfacciaUtente::on_VisualizzaProfiloButton_clicked()
{
    InterfacciaProfiloUtente* pu=new InterfacciaProfiloUtente(client->getUtente());
    pu->move(QApplication::desktop()->screen()->rect().center() - pu->rect().center());
    pu->show();
}

void InterfacciaUtente::on_ModificaProfiloButton_clicked()
{
    ui->Table->setRowCount(0); // pulisce la tabella
    InterfacciaModificaProfilo* mp=new InterfacciaModificaProfilo(client);
    mp->move(QApplication::desktop()->screen()->rect().center() - mp->rect().center());
    mp->show();
}

void InterfacciaUtente::on_AggiungiAmicoButton_clicked()
{
    aggiungiAmico();
}

void InterfacciaUtente::on_EliminaAmicoButton_clicked()
{
    eliminaAmico();
}

void InterfacciaUtente::on_CercaButton_clicked()
{
    cerca();
}
void InterfacciaUtente::on_VisualizzaAmiciButton_clicked()
{
    visualizzaAmici();
}

void InterfacciaUtente::on_VisualizzaUtentiIscrittiButton_clicked()
{
    visualizzaUtentiIscritti();
}

void InterfacciaUtente::on_LogoutButton_clicked()
{
    this->close();
    delete client;
}

void InterfacciaUtente::cerca()
{
    QString username=ui->CercaLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    if(!username.size())
    {
        QMessageBox err;
        err.setText("Nessun Username inserito");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else
    {
        if(username.toStdString()!=client->getUtente()->getUsername()->login)
        {
            vector<string> profilo=client->cerca(username.toStdString());
            if(profilo.size()!=0)
            {
               InterfacciaProfiloAmico* pa=new InterfacciaProfiloAmico(profilo);
               pa->move(QApplication::desktop()->screen()->rect().center() - pa->rect().center());
               pa->show();
            }
            else
            {
                QMessageBox err;
                err.setText("Non esiste un Utente con l'Username inserito");
                err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                err.exec();
            }
        }
        else
        {
            QMessageBox err;
            err.setText("Utilizza l'apposito pulsante per visualizzare il tuo profilo");
            err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            err.exec();
        }
    }
}

void InterfacciaUtente::aggiungiAmico()
{
    QString username=ui->AggiungiAmicoLineEdit->text().trimmed(); // Qstring senza spazi all'inizo e alla fine
    if(!username.size())
    {
        QMessageBox err;
        err.setText("Nessun Username inserito");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else
    {
        Utente* user=client->trovaUsername(username.toStdString());
        if(user)
        {
            ui->Table->setRowCount(0); // pulisce la tabella
            client->aggiungiAmico(user);
            client->salva();
        }
        else
        {
            QMessageBox err;
            err.setText("Non esiste un Utente con l'Username inserito");
            err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            err.exec();
        }
    }

}

void InterfacciaUtente::eliminaAmico()
{
    QString username=ui->EliminaAmicoLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    if(!username.size())
    {
        QMessageBox err;
        err.setText("Nessun Username inserito");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else
    {
        Utente* user=client->trovaUsername(username.toStdString());
        if(user)
        {
            ui->Table->setRowCount(0); // pulisce la tabella
            client->eliminaAmico(username.toStdString());
            client->salva();
        }
        else
        {
            QMessageBox err;
            err.setText("Non esiste un Utente con l'Username inserito");
            err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            err.exec();
        }
    }
}

void InterfacciaUtente::visualizzaAmici()
{
    ui->Table->setRowCount(0); // pulisce la tabella
    const vector<Utente*>* amici=client->getUtente()->getRete()->getRete();
    if(amici->size()!=0)
    {
       int i=0;
       for(vector<Utente*>::const_iterator it=amici->begin(); it!=amici->end(); it++)
       {
          Utente* user=client->trovaUsername((*it)->getUsername()->login);
          ui->Table->setRowCount(i+1);
          QTableWidgetItem* newItem=new QTableWidgetItem(QString::fromStdString(user->getProfilo()->getNome()));
          ui->Table->setItem(i,0,newItem);
          newItem=new QTableWidgetItem(QString::fromStdString(user->getProfilo()->getCognome()));
          ui->Table->setItem(i,1,newItem);
          newItem=new QTableWidgetItem(QString::fromStdString(user->getUsername()->login));
          ui->Table->setItem(i,2,newItem);
          i++;
       }
    }
    else
    {
        QMessageBox err;
        err.setText("Nessun amico aggiunto");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
}

void InterfacciaUtente::visualizzaUtentiIscritti()
{
    ui->Table->setRowCount(0); // pulisce la tabella
    if(client->getDb()->getDb()->size()>1)
    {
       int i=0;
       for(vector<Utente*>::const_iterator it=client->getDb()->getDb()->begin(); it!=client->getDb()->getDb()->end(); it++)
       {
          Utente* user=client->trovaUsername((*it)->getUsername()->login);
          if(user!=client->getUtente())
          {
              ui->Table->setRowCount(i+1);
              QTableWidgetItem* newItem=new QTableWidgetItem(QString::fromStdString(user->getProfilo()->getNome()));
              ui->Table->setItem(i,0,newItem);
              newItem=new QTableWidgetItem(QString::fromStdString(user->getProfilo()->getCognome()));
              ui->Table->setItem(i,1,newItem);
              newItem=new QTableWidgetItem(QString::fromStdString(user->getUsername()->login));
              ui->Table->setItem(i,2,newItem);
              i++;
          }
       }
    }
    else
    {
        QMessageBox err;
        err.setText("Nessun altro Utente iscritto oltre a te");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
}

