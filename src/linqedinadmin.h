#ifndef LINQUEDINADMIN_H
#define LINQUEDINADMIN_H

#include<vector>
#include"db.h"

using std::vector;

class LinQedInAdmin
{
private:
    DB* db;
public:
    LinQedInAdmin();
    ~LinQedInAdmin();
    DB* getDb();
    void inserisci(Utente*);
    void elimina(Utente*);
    Utente* trovaUsername(string) const;
    Utente* trovaNomeCognome(string, string) const;
    void cambiaTipoAccount(); // cambia tra Basic, Business, Executive
    void salva() const;
    void carica();
};

#endif // LINQUEDINADMIN_H
