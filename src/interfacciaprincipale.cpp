#include<QString>
#include<QMessageBox>
#include<QDesktopWidget>
#include"interfacciaprincipale.h"
#include"ui_interfacciaprincipale.h"
#include"interfacciaregistrazione.h"
#include"interfacciautente.h"
#include"interfacciaadmin.h"
#include"linqedinadmin.h"
#include"linqedinclient.h"

InterfacciaPrincipale::InterfacciaPrincipale(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::InterfacciaPrincipale)
{
    ui->setupUi(this);
}

InterfacciaPrincipale::~InterfacciaPrincipale()
{
    delete ui;
}

void InterfacciaPrincipale::on_LoginButton_clicked()
{
    creaUtente();
}

void InterfacciaPrincipale::on_AdminButton_clicked()
{
    creaAdmin();
}

void InterfacciaPrincipale::creaUtente()
{
    QString user=ui->UsernameLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString pass=ui->PasswordLineEdit->text();
    if(!user.size() && !pass.size())
    {
        QMessageBox err;
        err.setText("Nessun Username, Password inseriti");
        err.setStyleSheet("QMessageBox{background-color:rgb(113, 113, 113);}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else if(!user.size())
    {
        QMessageBox err;
        err.setText("Inserisci anche l'Username per effettuare il login");
        err.setStyleSheet("QMessageBox{background-color:rgb(113, 113, 113);}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else if(!pass.size())
    {
        QMessageBox err;
        err.setText("Inserisci anche la Password per effettuare il login");
        err.setStyleSheet("QMessageBox{background-color:rgb(113, 113, 113);}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else
    {
        Username usern(user.toStdString(), pass.toStdString());
        LinQedInClient* lC=new LinQedInClient(usern);
        if(lC->getUtente()!=0)
        {
            if(pass.toStdString()!=lC->getUtente()->getUsername()->getPassword())
            {
                QMessageBox err;
                err.setText("La password inserita non è corretta");
                err.setStyleSheet("QMessageBox{background-color:rgb(113, 113, 113);}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                err.exec();
            }
            else
            {
                InterfacciaUtente* iu=new InterfacciaUtente(lC);
                iu->move(QApplication::desktop()->screen()->rect().center() - iu->rect().center());
                iu->show();
            }
        }
        else
        {
            QMessageBox err;
            err.setText("Non esiste un Utente con l'Username inserito");
            err.setStyleSheet("QMessageBox{background-color:rgb(113, 113, 113);}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            err.exec();
        }
    }
}

void InterfacciaPrincipale::creaAdmin()
{
    LinQedInAdmin* lA=new LinQedInAdmin();
    InterfacciaAdmin* ia=new InterfacciaAdmin(lA);
    ia->move(QApplication::desktop()->screen()->rect().center() - ia->rect().center());
    ia->show();
}

