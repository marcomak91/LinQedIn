#include"interfacciaprofiloutente.h"
#include"ui_interfacciaprofiloutente.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"

InterfacciaProfiloUtente::InterfacciaProfiloUtente(Utente* u, QWidget *parent) :
    QWidget(parent), ui(new Ui::InterfacciaProfiloUtente), ut(u)
{
    ui->setupUi(this);
    caricaProfilo();
    QString nomeUtente=QString::fromStdString(ut->getUsername()->login);
    ui->TitoloLabel->setText("Profilo di "+nomeUtente);
}

InterfacciaProfiloUtente::~InterfacciaProfiloUtente()
{
    delete ui;
}

void InterfacciaProfiloUtente::on_ChiudiButton_clicked()
{
    this->close();
}

void InterfacciaProfiloUtente::caricaProfilo()
{
    ui->NomeTextLabel->setText(QString::fromStdString(ut->getProfilo()->getNome()));
    ui->CognomeTextLabel->setText(QString::fromStdString(ut->getProfilo()->getCognome()));
    ui->DataNascitaTextLabel->setText(QString::fromStdString(ut->getProfilo()->getDataNascita()));
    ui->LuogoNascitaTextLabel->setText(QString::fromStdString(ut->getProfilo()->getLuogoNascita()));
    ui->IndirizzoTextLabel->setText(QString::fromStdString(ut->getProfilo()->getIndirizzo()));
    ui->CittaTextLabel->setText(QString::fromStdString(ut->getProfilo()->getCitta()));
    ui->ProvinciaTextLabel->setText(QString::fromStdString(ut->getProfilo()->getProvincia()));
    ui->TitoloStudioTextLabel->setText(QString::fromStdString(ut->getProfilo()->getTitoloStudio()));
    ui->TelefonoTextLabel->setText(QString::fromStdString(ut->getProfilo()->getTelefono()));
    ui->EmailTextLabel->setText(QString::fromStdString(ut->getProfilo()->getEmail()));
    ui->LingueTextBrowser->setText(QString::fromStdString(ut->getProfilo()->getLingue()));
    ui->EsperienzeLavorativeTextBrowser->setText(QString::fromStdString(ut->getProfilo()->getEsperienzeLavorative()));
    string tu;
    const UtenteBasic* uba = dynamic_cast<const UtenteBasic*>(ut);
    if(uba)
    {
        tu="Basic";
    }
    else
    {
        const UtenteBusiness* ubu = dynamic_cast<const UtenteBusiness*>(ut);
        if(ubu)
        {
            tu="Business";
        }
        else
        {
            const UtenteExecutive* uex = dynamic_cast<const UtenteExecutive*>(ut);
            if(uex)
            {
                tu="Executive";
            }
        }
    }
    ui->TipoUtenteTextLabel->setText(QString::fromStdString(tu));
}
