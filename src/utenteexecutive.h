#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include"utente.h"

class UtenteExecutive: public Utente
{
public:
    UtenteExecutive(Username, Profilo);    
    virtual vector<string> userSearch(const DB&, string); // overriding: ricerca per un utente Executive, funtore di tipo 3
};

#endif // UTENTEEXECUTIVE_H
