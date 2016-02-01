#ifndef LINQUENDINCLIENT_H
#define LINQUENDINCLIENT_H

#include<vector>
#include"utente.h"
#include"db.h"

using std::string;
using std::vector;

class LinQedInClient
{
private:
    Utente* u;
    DB* db;
public:
    LinQedInClient(Username);
    ~LinQedInClient();
    Utente* getUtente();
    DB* getDb();
    void aggiungiAmico(Utente*);
    void eliminaAmico(string);
    Utente* trovaUsername(string) const;
    vector<string> cerca(string) const;
    void salva() const;
    void carica();
};

#endif // LINQUENDINCLIENT_H
