#include<QFile>
#include<QDomDocument>
#include<QMessageBox>
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"
#include"profilo.h"
#include"db.h"
#include"rete.h"

DB::DB() {}

DB::~DB()
{
    for(vector<Utente*>::iterator it=db.begin(); it!=db.end(); it++)
    {
        delete *it;
    }
}

const vector<Utente*>* DB::getDb() const
{
    return &db;
}

void DB::inserisci(Utente* u)
{
    db.push_back(u);
}

void DB::elimina(Utente* u)
{
    bool eliminato=false;
    for(vector<Utente*>::iterator it=db.begin(); it!=db.end() && !eliminato; it++)
    {
        if(u->getUsername()->login==(*it)->getUsername()->login)
        {
            delete *it; // elimino oggetto puntato per evitare garbage
            db.erase(it);
            eliminato=true;
        }
    }
}

Utente* DB::trovaUsername(string u) const
{
    for(vector<Utente*>::const_iterator it=db.begin(); it!=db.end(); it++)
    {
        if(u==(*it)->getUsername()->login)
            return *it;
    }
    return 0;
}

Utente* DB::trovaNomeCognome(string n, string s) const
{
    for(vector<Utente*>::const_iterator it=db.begin(); it!=db.end(); it++)
    {
        if(!QString::compare(QString::fromStdString(n),QString::fromStdString((*it)->getProfilo()->getNome()),Qt::CaseInsensitive) && !QString::compare(QString::fromStdString(s),QString::fromStdString((*it)->getProfilo()->getCognome()), Qt::CaseInsensitive))
            return *it;
    }
    return 0;
}

void DB::salva() const
{
    QFile* file = new QFile("database.xml"); // se file esiste lo provo ad aprire (sola scrittura e di tipo testuale (con "a capo" \n))
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox err;
            err.setText("ERRORE APERTURA FILE");
            err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            err.exec();
        }
        else
        {
            QXmlStreamWriter* sw = new QXmlStreamWriter; // creo un XmlStreamWrite (sistema di scrittura per file xml)
            sw->setAutoFormatting(true); // abilito la formattazione automatica in modo da avere un xml indentato e spaziato da righe
            sw->setDevice(file); // gli passo il file xml in cui scrivere
            sw->writeStartDocument(); // scrivo l'intestazione del file xml
            sw->writeStartElement("utenti"); // scrivo il tag radice <utenti>
            for(vector<Utente*>::const_iterator it = db.begin(); it != db.end(); it++) // scorro il database e salvo ogni Utente nel file
            {
                UtenteBasic* uba=dynamic_cast<UtenteBasic*>(*it);
                if(uba)
                {
                    QString amici=uba->getRete()->getAmici(db);
                    sw->writeStartElement("utente"); // scrivo il tag <utente> che identifica ogni utente
                    sw->writeTextElement("nome", QString::fromStdString(uba->getProfilo()->getNome()));
                    sw->writeTextElement("cognome", QString::fromStdString(uba->getProfilo()->getCognome()));
                    sw->writeTextElement("dataNascita", QString::fromStdString(uba->getProfilo()->getDataNascita()));
                    sw->writeTextElement("luogoNascita", QString::fromStdString(uba->getProfilo()->getLuogoNascita()));
                    sw->writeTextElement("indirizzo", QString::fromStdString(uba->getProfilo()->getIndirizzo()));
                    sw->writeTextElement("citta", QString::fromStdString(uba->getProfilo()->getCitta()));
                    sw->writeTextElement("provincia", QString::fromStdString(uba->getProfilo()->getProvincia()));
                    sw->writeTextElement("telefono", QString::fromStdString(uba->getProfilo()->getTelefono()));
                    sw->writeTextElement("email", QString::fromStdString(uba->getProfilo()->getEmail()));
                    sw->writeTextElement("titoloStudio", QString::fromStdString(uba->getProfilo()->getTitoloStudio()));
                    sw->writeTextElement("lingue", QString::fromStdString(uba->getProfilo()->getLingue()));
                    sw->writeTextElement("esperienzeLavorative", QString::fromStdString(uba->getProfilo()->getEsperienzeLavorative()));
                    sw->writeTextElement("amici", amici);
                    sw->writeTextElement("username", QString::fromStdString(uba->getUsername()->login));
                    sw->writeTextElement("password", QString::fromStdString(uba->getUsername()->getPassword()));
                    sw->writeTextElement("tipoUtente", QString::fromStdString("Basic"));
                    sw->writeEndElement(); // tag di chiusura </utente>
                }
                else
                {
                    UtenteBusiness* ubu=dynamic_cast<UtenteBusiness*>(*it);
                    if(ubu)
                    {
                        QString amici=ubu->getRete()->getAmici(db);
                        sw->writeStartElement("utente"); // scrivo il tag <utente> che identifica ogni utente
                        sw->writeTextElement("nome", QString::fromStdString(ubu->getProfilo()->getNome()));
                        sw->writeTextElement("cognome", QString::fromStdString(ubu->getProfilo()->getCognome()));
                        sw->writeTextElement("dataNascita", QString::fromStdString(ubu->getProfilo()->getDataNascita()));
                        sw->writeTextElement("luogoNascita", QString::fromStdString(ubu->getProfilo()->getLuogoNascita()));
                        sw->writeTextElement("indirizzo", QString::fromStdString(ubu->getProfilo()->getIndirizzo()));
                        sw->writeTextElement("citta", QString::fromStdString(ubu->getProfilo()->getCitta()));
                        sw->writeTextElement("provincia", QString::fromStdString(ubu->getProfilo()->getProvincia()));
                        sw->writeTextElement("telefono", QString::fromStdString(ubu->getProfilo()->getTelefono()));
                        sw->writeTextElement("email", QString::fromStdString(ubu->getProfilo()->getEmail()));
                        sw->writeTextElement("titoloStudio", QString::fromStdString(ubu->getProfilo()->getTitoloStudio()));
                        sw->writeTextElement("lingue", QString::fromStdString(ubu->getProfilo()->getLingue()));
                        sw->writeTextElement("esperienzeLavorative", QString::fromStdString(ubu->getProfilo()->getEsperienzeLavorative()));
                        sw->writeTextElement("amici", amici);
                        sw->writeTextElement("username", QString::fromStdString(ubu->getUsername()->login));
                        sw->writeTextElement("password", QString::fromStdString(ubu->getUsername()->getPassword()));
                        sw->writeTextElement("tipoUtente", QString::fromStdString("Business"));
                        sw->writeEndElement(); // tag di chiusura </utente>
                    }
                    else
                    {
                        UtenteExecutive* uex=dynamic_cast<UtenteExecutive*>(*it);
                        if(uex)
                        {
                            QString amici=uex->getRete()->getAmici(db);
                            sw->writeStartElement("utente");// scrivo il tag <utente> che identifica ogni utente
                            sw->writeTextElement("nome", QString::fromStdString(uex->getProfilo()->getNome()));
                            sw->writeTextElement("cognome", QString::fromStdString(uex->getProfilo()->getCognome()));
                            sw->writeTextElement("dataNascita", QString::fromStdString(uex->getProfilo()->getDataNascita()));
                            sw->writeTextElement("luogoNascita", QString::fromStdString(uex->getProfilo()->getLuogoNascita()));
                            sw->writeTextElement("indirizzo", QString::fromStdString(uex->getProfilo()->getIndirizzo()));
                            sw->writeTextElement("citta", QString::fromStdString(uex->getProfilo()->getCitta()));
                            sw->writeTextElement("provincia", QString::fromStdString(uex->getProfilo()->getProvincia()));
                            sw->writeTextElement("telefono", QString::fromStdString(uex->getProfilo()->getTelefono()));
                            sw->writeTextElement("email", QString::fromStdString(uex->getProfilo()->getEmail()));
                            sw->writeTextElement("titoloStudio", QString::fromStdString(uex->getProfilo()->getTitoloStudio()));
                            sw->writeTextElement("lingue", QString::fromStdString(uex->getProfilo()->getLingue()));
                            sw->writeTextElement("esperienzeLavorative", QString::fromStdString(uex->getProfilo()->getEsperienzeLavorative()));
                            sw->writeTextElement("amici", amici);
                            sw->writeTextElement("username", QString::fromStdString(uex->getUsername()->login));
                            sw->writeTextElement("password", QString::fromStdString(uex->getUsername()->getPassword()));
                            sw->writeTextElement("tipoUtente", QString::fromStdString("Executive"));
                            sw->writeEndElement(); // tag di chiusura </utente>
                        }
                    }
                }
            }
            sw->writeEndElement(); // chiudo il tag radice </utenti>
            sw->writeEndDocument(); // chiudo il documento
            file->close(); // chiudo il file
        }
}

void DB::carica()
{
    QFile* file = new QFile("database.xml");
    if(file->exists())
    {
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text)) // se file esiste lo provo ad aprire (sola lettura e di tipo testuale con "a capo" \n)
        {
            QMessageBox err;
            err.setText("ERRORE APERTURA FILE");
            err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
            err.exec();
        }
        else
        {
            QDomDocument doc; // creo il file xml
            if(!doc.setContent(file)) // provo a fare il parser del file caricato, se non va allora ritorno
            {
                return;
            }
            QDomElement docElem = doc.documentElement(); // salvo la radice del documento
            QDomNodeList nodi = docElem.elementsByTagName("utente"); // creo una lista dei nodi utenti identificati dal tag <utente>
            for(int i=0; i<nodi.count(); i++) // scorro la lista nodo <utente> per nodo <utente>
            {
                QDomElement elem = nodi.at(i).toElement(); // salvo l'elemento contenuto nel nodo <utente>, in posizione i, in un oggetto xml
                QDomNode nodo = elem.firstChild(); // mi sposto sul primo figlio
                QString n, c, dn, ln, in, ct, p, t, e, ts, l, el, u, psw, tu; // creo le variabili per l'oggetto Utente
                while (!nodo.isNull()) // scorro tutti i tag del nodo <utente> e salvo quelli che mi interessano nelle rispettive variabili
                {
                    QDomElement elemento = nodo.toElement();
                    QString nomeTag = elemento.tagName();
                    if(nomeTag=="nome")
                    {
                        n=elemento.text();
                    }
                    else if(nomeTag=="cognome")
                    {
                        c=elemento.text();
                    }
                    else if(nomeTag=="dataNascita")
                    {
                        dn=elemento.text();
                    }
                    else if(nomeTag=="luogoNascita")
                    {
                        ln=elemento.text();
                    }
                    else if(nomeTag=="indirizzo")
                    {
                        in=elemento.text();
                    }
                    else if(nomeTag=="citta")
                    {
                        ct=elemento.text();
                    }
                    else if(nomeTag=="provincia")
                    {
                        p=elemento.text();
                    }
                    else if(nomeTag=="telefono")
                    {
                        t=elemento.text();
                    }
                    else if(nomeTag=="email")
                    {
                        e=elemento.text();
                    }
                    else if(nomeTag=="titoloStudio")
                    {
                        ts=elemento.text();
                    }
                    else if(nomeTag=="lingue")
                    {
                        l=elemento.text();
                    }
                    else if(nomeTag=="esperienzeLavorative")
                    {
                        el=elemento.text();
                    }
                    else if(nomeTag=="username")
                    {
                        u=elemento.text();
                    }
                    else if(nomeTag=="password")
                    {
                        psw=elemento.text();
                    }
                    else if(nomeTag=="tipoUtente")
                    {
                        tu=elemento.text();
                    }
                    nodo=nodo.nextSibling(); // mi sposto sul tag successivo
                }
                Utente* ut = 0; // puntatore polimorfo
                Profilo prof(n.toStdString(), c.toStdString(), dn.toStdString(), ln.toStdString(), in.toStdString(), ct.toStdString(), p.toStdString(), t.toStdString(), e.toStdString(), ts.toStdString());
                Username us(u.toStdString(), psw.toStdString());
                // creo l'oggetto Utente in base al tipoUtente
                if(tu == "Basic")
                {
                    ut=new UtenteBasic(us, prof);
                }
                else if( tu == "Business")
                {
                    ut=new UtenteBusiness(us, prof);
                }
                else // tu == "Executive"
                {
                    ut=new UtenteExecutive(us, prof);
                }
                // carico esperienze e lingue separatamente, poichè non fanno parte del costruttore di Profilo
                if(l.size()!=0)
                   ut->getProfilo()->setLingue(l.toStdString());
                if(el.size()!=0)
                   ut->getProfilo()->setEsperienzeLavorative(el.toStdString());
                inserisci(ut); // inserisco nel db l'Utente
            }
            caricaRete(); // non posso caricare anche la rete insieme agli altri elementi poichè all'inizio non ho tutti gli utenti nel DB che appunto carico man mano nel ciclo for precedente
            file->close(); // chiudo il file database.xml
        }
    }
}

void DB::caricaRete()
{
    QFile* file = new QFile("database.xml");
        if(file->exists())
        {
            if(!file->open(QIODevice::ReadOnly | QIODevice::Text)) // se file esiste lo provo ad aprire (sola lettura e di tipo testuale con "a capo" \n)
            {
                QMessageBox err;
                err.setText("ERRORE APERTURA FILE");
                err.setStyleSheet("QMessageBox{background-color:rgb(57, 57, 57);;}QPushButton{width:85;height:27;background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0.507177 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 127, 255));font: bold 16pt \"Kinnari\";color: rgb(255, 170, 0);border-width: 2px;border-color:rgb(255, 85, 0);border-style: solid;border-radius: 7;}QPushButton:hover{background-color:qlineargradient(spread:pad, x1:0.474, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.507177 rgba(255, 170, 0, 255)); color: rgb(0, 0, 0);}QPushButton:hover:!pressed{background-color:qlineargradient(spread:pad, x1:0.244, y1:1, x2:0.837, y2:0.227273, stop:0 rgba(255, 255, 127, 255), stop:0.507177 rgba(0, 0, 0, 255));color: rgb(255, 170, 0);}QLabel{font: bold 14pt \"Kinnari\";color:rgb(255, 170, 0)}");
                err.exec();
            }
            else
            {
                QDomDocument doc; // creo il file xml
                if(!doc.setContent(file)) //provo a fare il parser del file caricato, se non va allora ritorno
                {
                    return;
                }
                QDomElement docElem = doc.documentElement(); // salvo la radice del documento
                QDomNodeList nodi = docElem.elementsByTagName("utente"); // creo una lista dei nodi utenti identificati dal tag <utente>
                for(int i=0; i<nodi.count(); i++) // scorro la lista nodo <utente> per nodo <utente>
                {
                    QDomElement elem = nodi.at(i).toElement(); // salvo l'elemento contenuto nel nodo <utente>, in posizione i, in un oggetto xml
                    QDomNode nodo = elem.firstChild(); // mi sposto sul primo figlio
                    QString a, u; // creo le variabili per l'oggetto Utente
                    QRegExp re("[,]"); // espressione regolare per il parsing della QString
                    while (!nodo.isNull()) // scorro tutti i tag del nodo <utente> e salvo quelli che mi interessano nelle rispettive variabili
                    {
                        QDomElement elemento = nodo.toElement();
                        QString tagName = elemento.tagName();
                        if(tagName=="amici")
                        {
                            a=elemento.text();
                        }
                        else if(tagName=="username")
                        {
                            u=elemento.text();
                        }
                        nodo=nodo.nextSibling(); // mi sposto sul tag successivo
                    }
                    // carico lista amici dell'utente
                    QStringList list=a.split(re, QString::SkipEmptyParts); // creo una lista separando gli amici in base alla virgola
                    QList<string> amici;
                    for(int i=0; i<list.size(); i++)
                    {
                        amici.append(list.at(i).toStdString());
                    }
                    Utente* daAggiungere;
                    for(int i=0; i<amici.size(); i++)
                    {
                        daAggiungere=trovaUsername(amici.at(i));
                        trovaUsername(u.toStdString())->getRete()->aggiungi(daAggiungere);
                    }
                }
            }
            file->close();
        }
}
