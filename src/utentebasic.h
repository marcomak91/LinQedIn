#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include"utente.h"

class UtenteBasic: public Utente
{
public:
    UtenteBasic(Username, Profilo);    
    virtual vector<string> userSearch(const DB&, string); // overriding: ricerca per un utente Basic, funtore di tipo 1
};

#endif // UTENTEBASIC_H
