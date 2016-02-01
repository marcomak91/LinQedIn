#ifndef UTENTE_H
#define UTENTE_H

#include<string>
#include<vector>
#include"profilo.h"
#include"username.h"
#include"db.h"

using std::vector;
using std::string;

class Rete;
class DB;

class Utente // base astratta
{
private:
    Username un;
    Profilo pf;
    Rete* rete;
public:
    Utente(Username, Profilo);
    virtual ~Utente();
    Profilo* getProfilo();
    Rete* getRete();
    Username* getUsername();
    virtual vector<string> userSearch(const DB&, string) =0; // ricerca polimorfa, virtuale pura

protected:
    class SearchFunctor // classe annidata di funtori di ricerca
    {
    public:
        int tipoUtente;
        SearchFunctor(int =0);
        void operator() (Utente*, vector<string>&) const;
    };
};


#endif // UTENTE_H
