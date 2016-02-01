#ifndef DB_H
#define DB_H

#include<QXmlStreamReader>
#include<QList>
#include<vector>
#include"utente.h"

using std::vector;

class Utente;
class DB
{
private:
    vector<Utente*> db;
public:
    DB();
    ~DB();
    const vector<Utente*>* getDb() const;
    void inserisci(Utente*);
    void elimina(Utente*);
    Utente* trovaUsername(string) const; // trova un Utente tramite Username
    Utente* trovaNomeCognome(string, string) const; // trova un Utente tramite Nome e Cognome
    void salva() const; // salva su file
    void carica();// carica da file
    void caricaRete();
};

#endif // DB_H
