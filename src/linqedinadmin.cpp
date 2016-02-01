#include"linqedinadmin.h"

LinQedInAdmin::LinQedInAdmin()
{
    db=new DB();
    db->carica(); // carica il DB e la rete di tutti i contatti
}

LinQedInAdmin::~LinQedInAdmin()
{
    delete db;
}

DB* LinQedInAdmin::getDb()
{
    return db;
}

void LinQedInAdmin::inserisci(Utente* u)
{
    db->inserisci(u);
}

void LinQedInAdmin::elimina(Utente* u)
{
    db->elimina(u);
}

Utente* LinQedInAdmin::trovaUsername(string u) const
{
    return db->trovaUsername(u);
}

Utente* LinQedInAdmin::trovaNomeCognome(string n, string s) const
{
    return db->trovaNomeCognome(n,s);
}

void LinQedInAdmin::salva() const
{
    db->salva();
}

void LinQedInAdmin::carica()
{
    db->carica();
}
