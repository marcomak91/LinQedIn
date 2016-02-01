#include"utentebasic.h"

UtenteBasic::UtenteBasic(Username u, Profilo p)
    : Utente(u, p) {}

vector<string> UtenteBasic::userSearch(const DB& d, string u)
{
    SearchFunctor sf(1);
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
