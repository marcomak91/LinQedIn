#include"interfacciaprofiloamico.h"
#include"ui_interfacciaprofiloamico.h"

InterfacciaProfiloAmico::InterfacciaProfiloAmico(vector<string> v, QWidget *parent) :
    QWidget(parent), ui(new Ui::InterfacciaProfiloAmico), profilo(v)
{
    ui->setupUi(this);
    caricaProfiloAmico();
}

InterfacciaProfiloAmico::~InterfacciaProfiloAmico()
{
    delete ui;
}

void InterfacciaProfiloAmico::on_ChiudiButton_clicked()
{
    this->close();
}

void InterfacciaProfiloAmico::caricaProfiloAmico()
{
    string tu=profilo[0];
    if(tu=="Basic")
    {
        ui->NomeTextLabel->setText(QString::fromStdString(profilo[1]));
        ui->CognomeTextLabel->setText(QString::fromStdString(profilo[2]));
        ui->DataNascitaTextLabel->setText(QString::fromStdString(profilo[3]));
        ui->LuogoNascitaTextLabel->setText(QString::fromStdString(profilo[4]));
        ui->IndirizzoTextLabel->setText(QString::fromStdString(profilo[5]));
        ui->CittaTextLabel->setText(QString::fromStdString(profilo[6]));
        ui->ProvinciaTextLabel->setText(QString::fromStdString(profilo[7]));
        ui->TitoloStudioTextLabel->setText("??????????");
        ui->TelefonoTextLabel->setText("??????????");
        ui->EmailTextLabel->setText("??????????");
        ui->LingueTextBrowser->setText("??????????");
        ui->EsperienzeLavorativeTextBrowser->setText("??????????");
        ui->AvvisoLabel->setText("--->  Per visualizzare tutti i campi, cambia tipo account in Executive  <---");
    }
    else if(tu=="Business")
    {
        ui->NomeTextLabel->setText(QString::fromStdString(profilo[1]));
        ui->CognomeTextLabel->setText(QString::fromStdString(profilo[2]));
        ui->DataNascitaTextLabel->setText(QString::fromStdString(profilo[3]));
        ui->LuogoNascitaTextLabel->setText(QString::fromStdString(profilo[4]));
        ui->IndirizzoTextLabel->setText(QString::fromStdString(profilo[5]));
        ui->CittaTextLabel->setText(QString::fromStdString(profilo[6]));
        ui->ProvinciaTextLabel->setText(QString::fromStdString(profilo[7]));        
        ui->TelefonoTextLabel->setText(QString::fromStdString(profilo[8]));
        ui->EmailTextLabel->setText(QString::fromStdString(profilo[9]));
        ui->TitoloStudioTextLabel->setText(QString::fromStdString(profilo[10]));
        ui->LingueTextBrowser->setText("??????????");
        ui->EsperienzeLavorativeTextBrowser->setText("??????????");
        ui->AvvisoLabel->setText("--->  Per visualizzare tutti i campi, cambia tipo account in Executive  <---");
    }
    else if(tu=="Executive")
    {
        ui->NomeTextLabel->setText(QString::fromStdString(profilo[1]));
        ui->CognomeTextLabel->setText(QString::fromStdString(profilo[2]));
        ui->DataNascitaTextLabel->setText(QString::fromStdString(profilo[3]));
        ui->LuogoNascitaTextLabel->setText(QString::fromStdString(profilo[4]));
        ui->IndirizzoTextLabel->setText(QString::fromStdString(profilo[5]));
        ui->CittaTextLabel->setText(QString::fromStdString(profilo[6]));
        ui->ProvinciaTextLabel->setText(QString::fromStdString(profilo[7]));
        ui->TelefonoTextLabel->setText(QString::fromStdString(profilo[8]));
        ui->EmailTextLabel->setText(QString::fromStdString(profilo[9]));
        ui->TitoloStudioTextLabel->setText(QString::fromStdString(profilo[10]));
        ui->LingueTextBrowser->setText(QString::fromStdString(profilo[11]));
        ui->EsperienzeLavorativeTextBrowser->setText(QString::fromStdString(profilo[12]));
    }
}
