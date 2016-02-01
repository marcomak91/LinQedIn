#ifndef PROFILO_H
#define PROFILO_H

#include<string>

using std::string;

class Profilo
{
private:
    string nome;
    string cognome;
    string dataNascita;
    string luogoNascita;
    string indirizzo;
    string citta;
    string provincia;
    string telefono;
    string email;
    string titoloStudio;
    string lingue;
    string esperienzeLavorative;
public:
    Profilo(string, string, string, string , string , string, string, string, string, string);
    void setNome(string);
    void setCognome(string);
    void setDataNascita(string);
    void setLuogoNascita(string);
    void setIndirizzo(string);
    void setCitta(string);
    void setProvincia(string);
    void setTelefono(string);
    void setEmail(string);
    void setTitoloStudio(string);
    void setLingue(string);
    void setEsperienzeLavorative(string);
    string getNome() const;
    string getCognome() const;
    string getDataNascita() const;
    string getLuogoNascita() const;
    string getIndirizzo() const;
    string getCitta() const;
    string getProvincia() const;
    string getTelefono() const;
    string getEmail() const;
    string getTitoloStudio() const;
    string getLingue() const;
    string getEsperienzeLavorative() const;
};

#endif // PROFILO_H
