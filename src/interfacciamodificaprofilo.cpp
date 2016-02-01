#include<QMessageBox>
#include"interfacciamodificaprofilo.h"
#include"ui_interfacciamodificaprofilo.h"

InterfacciaModificaProfilo::InterfacciaModificaProfilo(LinQedInClient* c, QWidget *parent) :
    QWidget(parent), ui(new Ui::InterfacciaModificaProfilo), clientM(c)
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
    caricaProfilo();
}

InterfacciaModificaProfilo::~InterfacciaModificaProfilo()
{
    delete ui;
}

void InterfacciaModificaProfilo::on_ConfermaModificheButton_clicked()
{
    modificaProfilo();
}

void InterfacciaModificaProfilo::caricaProfilo()
{
    ui->NomeLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getNome()));
    ui->CognomeLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getCognome()));
    ui->DataNascitaDateEdit->setDate(QDate::fromString(QString::fromStdString(clientM->getUtente()->getProfilo()->getDataNascita()),"dd/MM/yy"));
    ui->LuogoNascitaLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getLuogoNascita()));
    ui->IndirizzoLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getIndirizzo()));
    ui->CittaLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getCitta()));
    ui->ProvinciaLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getProvincia()));
    ui->TitoloStudioLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getTitoloStudio()));
    ui->TelefonoLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getTelefono()));
    ui->EmailLineEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getEmail()));
    ui->EsperienzeLavorativeTextEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getEsperienzeLavorative()));
    ui->LingueTextEdit->setText(QString::fromStdString(clientM->getUtente()->getProfilo()->getLingue()));
}

void InterfacciaModificaProfilo::modificaProfilo()
{
    QString nome=ui->NomeLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString cognome=ui->CognomeLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString dataNascita=ui->DataNascitaDateEdit->text();
    QString luogoNascita=ui->LuogoNascitaLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString indirizzo=ui->IndirizzoLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString citta=ui->CittaLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString provincia=ui->ProvinciaLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString titoloStudio=ui->TitoloStudioLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString telefono=ui->TelefonoLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString email=ui->EmailLineEdit->text().trimmed(); // Qstring senza spazi all'inizio e alla fine;
    QString nuovaPassword=ui->NuovaPasswordLineEdit->text();
    QString confermaPassword=ui->ConfermaPasswordLineEdit->text();
    QString esperienzeLavorative=ui->EsperienzeLavorativeTextEdit->toPlainText();
    QString lingue=ui->LingueTextEdit->toPlainText();
    if(clientM->getDb()->trovaNomeCognome(nome.toStdString(), cognome.toStdString()) && (nome.toStdString()!=clientM->getUtente()->getProfilo()->getNome() || cognome.toStdString()!=clientM->getUtente()->getProfilo()->getCognome())) // se esiste già ed è stato cambiato il Nome o il Cognome o entrambi
    {
        QMessageBox err;
        err.setText("Nome e Cognome già esistente");
        err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
        err.exec();
    }
    else
    {
        if(nome.size()!=0)
            clientM->getUtente()->getProfilo()->setNome(nome.toStdString());
        if(cognome.size()!=0)
            clientM->getUtente()->getProfilo()->setCognome(cognome.toStdString());
        if(dataNascita.size()!=0)
            clientM->getUtente()->getProfilo()->setDataNascita(dataNascita.toStdString());
        if(luogoNascita.size()!=0)
            clientM->getUtente()->getProfilo()->setLuogoNascita(luogoNascita.toStdString());
        if(indirizzo.size()!=0)
            clientM->getUtente()->getProfilo()->setIndirizzo(indirizzo.toStdString());
        if(citta.size()!=0)
            clientM->getUtente()->getProfilo()->setCitta(citta.toStdString());
        if(provincia.size()!=0)
            clientM->getUtente()->getProfilo()->setProvincia(provincia.toStdString());
        if(titoloStudio.size()!=0)
            clientM->getUtente()->getProfilo()->setTitoloStudio(titoloStudio.toStdString());
        if(telefono.size()!=0)
            clientM->getUtente()->getProfilo()->setTelefono(telefono.toStdString());
        if(email.size()!=0)
            clientM->getUtente()->getProfilo()->setEmail(email.toStdString());
        clientM->getUtente()->getProfilo()->setLingue(lingue.toStdString()); // non è un campo obbligatorio quindi può essere anche svuotato
        clientM->getUtente()->getProfilo()->setEsperienzeLavorative(esperienzeLavorative.toStdString()); // non è un campo obbligatorio quindi può essere anche svuotato
        if(nuovaPassword.size()!=0 || confermaPassword.size()!=0)
        {
            if(!nuovaPassword.size())
            {
                QMessageBox err;
                err.setText("Inserisci anche Nuova Password per effettuare la modifica");
                err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                err.exec();
            }
            else if(!confermaPassword.size())
            {
                QMessageBox err;
                err.setText("Inserisci anche Conferma Password per effettuare la modifica");
                err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                err.exec();
            }
            else if(nuovaPassword!=confermaPassword)
            {
                QMessageBox err;
                err.setText("La conferma password non corrisponde, riprova");
                err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                err.exec();
            }
            else
            {
                clientM->getUtente()->getUsername()->setPassword(nuovaPassword.toStdString());
                clientM->salva();
                QMessageBox msg;
                msg.setText("Modifica avvenuta con successo!");
                msg.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                msg.exec();
                this->close();
            }
        }
        else // non voglio modificare la password
        {
            clientM->salva();
            QMessageBox msg;
            msg.setText("Modifica avvenuta con successo!");
            msg.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            msg.exec();
            this->close();
        }
    }
}

void InterfacciaModificaProfilo::on_AnnullaButton_clicked()
{
    QMessageBox msg;
    msg.setText("Nessuna modifica effettuata");
    msg.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
    msg.exec();
    this->close();
}
