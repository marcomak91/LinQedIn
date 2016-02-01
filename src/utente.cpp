#include"utente.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"
#include"rete.h"

// class Utente

Utente::Utente(Username u, Profilo p)
    : un(u), pf(p), rete(new Rete) {}

Utente::~Utente()
{
    delete rete;
}

Profilo* Utente::getProfilo()
{
    return &pf;
}
Rete* Utente::getRete()
{
    return rete;
}

Username* Utente::getUsername()
{
    return &un;
}

// class SearchFunctor

Utente::SearchFunctor::SearchFunctor(int x)
    : tipoUtente(x) {}

void Utente::SearchFunctor::operator() (Utente* ut,  vector<string>& v) const
{
    switch(tipoUtente)
    {
    case 1:
    {
        v.push_back("Basic");
        v.push_back(ut->getProfilo()->getNome());
        v.push_back(ut->getProfilo()->getCognome());
        v.push_back(ut->getProfilo()->getDataNascita());
        v.push_back(ut->getProfilo()->getLuogoNascita());
        v.push_back(ut->getProfilo()->getIndirizzo());
        v.push_back(ut->getProfilo()->getCitta());
        v.push_back(ut->getProfilo()->getProvincia());
    }
    case 2:
    {
        v.push_back("Business");
        v.push_back(ut->getProfilo()->getNome());
        v.push_back(ut->getProfilo()->getCognome());
        v.push_back(ut->getProfilo()->getDataNascita());
        v.push_back(ut->getProfilo()->getLuogoNascita());
        v.push_back(ut->getProfilo()->getIndirizzo());
        v.push_back(ut->getProfilo()->getCitta());
        v.push_back(ut->getProfilo()->getProvincia());
        v.push_back(ut->getProfilo()->getTelefono());
        v.push_back(ut->getProfilo()->getEmail());
        v.push_back(ut->getProfilo()->getTitoloStudio());

    }
    case 3:
    {
        v.push_back("Executive");
        v.push_back(ut->getProfilo()->getNome());
        v.push_back(ut->getProfilo()->getCognome());
        v.push_back(ut->getProfilo()->getDataNascita());
        v.push_back(ut->getProfilo()->getLuogoNascita());
        v.push_back(ut->getProfilo()->getIndirizzo());
        v.push_back(ut->getProfilo()->getCitta());
        v.push_back(ut->getProfilo()->getProvincia());
        v.push_back(ut->getProfilo()->getTelefono());
        v.push_back(ut->getProfilo()->getEmail());
        v.push_back(ut->getProfilo()->getTitoloStudio());
        v.push_back(ut->getProfilo()->getLingue());
        v.push_back(ut->getProfilo()->getEsperienzeLavorative());
    }
    default:
    {
        v.push_back("Basic");
        v.push_back(ut->getProfilo()->getNome());
        v.push_back(ut->getProfilo()->getCognome());
        v.push_back(ut->getProfilo()->getDataNascita());
        v.push_back(ut->getProfilo()->getLuogoNascita());
        v.push_back(ut->getProfilo()->getIndirizzo());
        v.push_back(ut->getProfilo()->getCitta());
        v.push_back(ut->getProfilo()->getProvincia());
    }
    }
}
