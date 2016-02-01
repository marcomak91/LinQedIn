#include"utenteexecutive.h"

UtenteExecutive::UtenteExecutive(Username u, Profilo p)
    : Utente(u, p) {}

vector<string> UtenteExecutive::userSearch(const DB& d, string u)
{
    SearchFunctor sf(3);
    vector<string> v;
    for(vector<Utente*>::const_iterator it=d.getDb()->begin(); it!=d.getDb()->end(); it++)
    {
        if((*it)->getUsername()->login==u)
        {
             sf((*it), v);
        }
    }
    return v;
}

