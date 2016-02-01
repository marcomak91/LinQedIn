#include"profilo.h"

Profilo::Profilo(string n, string c, string dn, string ln, string v, string ct, string p, string nt, string e, string ts)
    : nome(n), cognome(c), dataNascita(dn), luogoNascita(ln), indirizzo(v), citta(ct), provincia(p), telefono(nt), email(e), titoloStudio(ts) {}

void Profilo::setNome(string n)
{
    nome=n;
}

void Profilo::setCognome(string c)
{
    cognome=c;
}

void Profilo::setDataNascita(string dn)
{
    dataNascita=dn;
}

void Profilo::setLuogoNascita(string ln)
{
    luogoNascita=ln;
}

void Profilo::setIndirizzo(string v)
{
    indirizzo=v;
}

void Profilo::setCitta(string ct)
{
    citta=ct;
}

void Profilo::setProvincia(string p)
{
    provincia=p;
}

void Profilo::setTelefono(string nt)
{
    telefono=nt;
}

void Profilo::setEmail(string e)
{
    email=e;
}

void Profilo::setTitoloStudio(string ts)
{
    titoloStudio=ts;
}

void Profilo::setLingue(string l)
{
    lingue=l;
}

void Profilo::setEsperienzeLavorative(string el)
{
    esperienzeLavorative=el;
}

string Profilo::getNome() const
{
    return nome;
}

string Profilo::getCognome() const
{
    return cognome;
}

string Profilo::getDataNascita() const
{
    return dataNascita;
}

string Profilo::getLuogoNascita() const
{
    return luogoNascita;
}

string Profilo::getIndirizzo() const
{
    return indirizzo;
}

string Profilo::getCitta() const
{
    return citta;
}

string Profilo::getProvincia() const
{
    return provincia;
}

string Profilo::getTelefono() const
{
    return telefono;
}

string Profilo::getEmail() const
{
    return email;
}

string Profilo::getTitoloStudio() const
{
    return titoloStudio;
}

string Profilo::getLingue() const
{
    return lingue;
}

string Profilo::getEsperienzeLavorative() const
{
    return esperienzeLavorative;
}
