#ifndef RETE_H
#define RETE_H

#include<vector>
#include"utente.h"
#include"username.h"

using std::vector;

class Rete
{
private:
    vector<Utente*> rete;
public:
    Rete();
    const vector<Utente*>* getRete() const;
    void aggiungi(Utente*);
    void elimina(string);
    QString getAmici(const vector<Utente*>&) const;
    bool controllaAmico(string) const; // controlla se è già amico
};
#endif // RETE_H
