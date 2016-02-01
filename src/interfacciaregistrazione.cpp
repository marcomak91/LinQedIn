#include<QMessageBox>
#include"interfacciaregistrazione.h"
#include"ui_interfacciaregistrazione.h"
#include"linqedinclient.h"
#include"utente.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"

InterfacciaRegistrazione::InterfacciaRegistrazione(LinQedInAdmin* ad, QWidget *parent) :
    QWidget(parent), ui(new Ui::InterfacciaRegistrazione), adminR(ad)
{
    ui->setupUi(this);
    QRegExp reLettere("^[ A-Z | a-z ]{35}$");
    QRegExp reNumeri("^[ 0-9]{15}$");
    QRegExpValidator* validatorLettere=new QRegExpValidator(reLettere, 0);
    QRegExpValidator* validatorNumeri=new QRegExpValidator(reNumeri, 0);
    ui->NomeLineEdit->setValidator(validatorLettere);
    ui->CognomeLineEdit->setValidator(validatorLettere);
    ui->LuogoNascitaLineEdit->setValidator(validatorLettere);
    ui->TelefonoLineEdit->setValidator(validatorNumeri);
    ui->CittaLineEdit->setValidator(validatorLettere);
    ui->ProvinciaLineEdit->setValidator(validatorLettere);
}

InterfacciaRegistrazione::~InterfacciaRegistrazione()
{
    delete ui;
}

void InterfacciaRegistrazione::on_RegistratiButton_clicked()
{
    registra();
}

void InterfacciaRegistrazione::on_AnnullaButton_clicked()
{
    QMessageBox msg;
    msg.setText("Registrazione annullata");
    msg.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
    msg.exec();
    this->close();
}

void InterfacciaRegistrazione::registra()
{
    QString nome=ui->NomeLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString cognome=ui->CognomeLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString dataNascita=ui->DataNascitaDateEdit->text();
    QString luogoNascita=ui->LuogoNascitaLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString indirizzo=ui->IndirizzoLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString citta=ui->CittaLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString provincia=ui->ProvinciaLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString titoloStudio=ui->TitoloStudioLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString telefono=ui->TelefonoLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString email=ui->EmailLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString username=ui->UsernameLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine
    QString password=ui->PasswordLineEdit->text();
    QString confermaPassword=ui->ConfermaPasswordLineEdit->text();
    QString esperienzeLavorative=ui->EsperienzeLavorativeTextEdit->toPlainText();
    QString lingue=ui->LingueTextEdit->toPlainText();

    if(!nome.size() || !cognome.size() || !dataNascita.size() || !luogoNascita.size() || !indirizzo.size() || !citta.size() || !provincia.size() || !titoloStudio.size() || !telefono.size() || !email.size() || !username.size() || !password.size() || !confermaPassword.size())
    {
        QMessageBox err;
        err.setText("Manca qualche campo dati obbligatorio!");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else
    {
        if(password!=confermaPassword)
        {
            QMessageBox err;
            err.setText("La Conferma Password non corrisponde");
            err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            err.exec();
        }
        else
        {
            if(!(ui->BasicRadioButton->isChecked()) && !(ui->BusinessRadioButton->isChecked()) && !(ui->ExecutiveRadioButton->isChecked()))
            {
                QMessageBox err;
                err.setText("Non hai scelto il tipo di account!");
                err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                err.exec();
            }
            else
            {
                if(!(adminR->trovaUsername(username.toStdString())) && !(adminR->trovaNomeCognome(nome.toStdString(), cognome.toStdString())))
                {
                    Username user(username.toStdString(), password.toStdString());
                    if(ui->BasicRadioButton->isChecked())
                    {
                        Profilo prof(nome.toStdString(), cognome.toStdString(), dataNascita.toStdString(), luogoNascita.toStdString(), indirizzo.toStdString(), citta.toStdString(), provincia.toStdString(), telefono.toStdString(), email.toStdString(), titoloStudio.toStdString());
                        Utente* ut=new UtenteBasic(user, prof);
                        if(esperienzeLavorative.size()!=0)
                            ut->getProfilo()->setEsperienzeLavorative(esperienzeLavorative.toStdString());
                        if(lingue.size()!=0)
                            ut->getProfilo()->setLingue(lingue.toStdString());
                        adminR->inserisci(ut);
                    }
                    else if(ui->BusinessRadioButton->isChecked())
                    {
                        Profilo prof(nome.toStdString(), cognome.toStdString(), dataNascita.toStdString(), luogoNascita.toStdString(), indirizzo.toStdString(), citta.toStdString(), provincia.toStdString(), telefono.toStdString(), email.toStdString(), titoloStudio.toStdString());
                        Utente* ut=new UtenteBusiness(user, prof);
                        if(esperienzeLavorative.size()!=0)
                            ut->getProfilo()->setEsperienzeLavorative(esperienzeLavorative.toStdString());
                        if(lingue.size()!=0)
                            ut->getProfilo()->setLingue(lingue.toStdString());
                        adminR->inserisci(ut);
                    }
                    else if(ui->ExecutiveRadioButton->isChecked())
                    {
                        Profilo prof(nome.toStdString(), cognome.toStdString(), dataNascita.toStdString(), luogoNascita.toStdString(), indirizzo.toStdString(), citta.toStdString(), provincia.toStdString(), telefono.toStdString(), email.toStdString(), titoloStudio.toStdString());
                        Utente* ut=new UtenteExecutive(user, prof);
                        if(esperienzeLavorative.size()!=0)
                            ut->getProfilo()->setEsperienzeLavorative(esperienzeLavorative.toStdString());
                        if(lingue.size()!=0)
                                 ut->getProfilo()->setLingue(lingue.toStdString());
                        adminR->inserisci(ut);
                    }
                    adminR->salva();
                    QMessageBox msg;
                    msg.setText("Registrazione effettuata");
                    msg.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                    msg.exec();
                    this->close();
                }
                else if(adminR->trovaUsername(username.toStdString()) && adminR->trovaNomeCognome(nome.toStdString(), cognome.toStdString()))
                {
                    QMessageBox err;
                    err.setText("Nome, Cognome e Username già esistente");
                    err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                    err.exec();
                }
                else if(adminR->trovaNomeCognome(nome.toStdString(), cognome.toStdString()))
                {
                    QMessageBox err;
                    err.setText("Nome e Cognome già esistente");
                    err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                    err.exec();
                }
                else if(adminR->trovaUsername(username.toStdString()))
                {
                    QMessageBox err;
                    err.setText("Username già esistente");
                    err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                    err.exec();
                }
            }
        }
    }
}
