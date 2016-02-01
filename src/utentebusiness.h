#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include"utente.h"

class UtenteBusiness: public Utente
{
public:
    UtenteBusiness(Username, Profilo);
    virtual vector<string> userSearch(const DB&, string); // overriding: ricerca per un utente Business, funtore di tipo 2

};

#endif // UTENTEBUSINESS_H
