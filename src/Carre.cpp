#include "Carre.h"

#include <iostream>
#include <cstring>


using namespace std;

Carre::Carre():
    ElementGraphique(),
    m_cote(1)
{
}

Carre::Carre(Point p,int cote):
    ElementGraphique(p),
    m_cote(cote)
{
}

Carre::Carre(Point p, int trait, int cote):
    ElementGraphique(p,trait),
    m_cote(cote)
{
}

Carre::Carre(const Carre& c) :
    ElementGraphique(c),
    m_cote(c.cote())
{
}

Carre::~Carre()
{
}

int Carre::cote() const {
    return this->m_cote;
}

void Carre::definirCote(int c){
    this->m_cote = c;
}

double Carre::perimetre() const{
    return (this->cote()*4);
}

void Carre::afficher() const{

    cout << "je suis un Carre de cote " << this->cote() << " et " << endl;
    this->ElementGraphique::afficher();
}

 Carre& Carre::operator= (const Carre& c){
    if(&c != this){
        this->ElementGraphique::operator=(c);
        this->definirCote(c.cote());
    }
    return *this;
 }

 bool Carre::operator==(const Carre& c){
    return(this->ElementGraphique::operator==(c) && this->cote() == c.cote());
}

bool Carre::operator==(const ElementGraphique& c){
    bool resultat = false;

    if (typeid(*this) == typeid(c)){
        resultat = (*this == static_cast<const Carre&>(c));
    }

    return resultat;
}


bool Carre::operator<(const Carre& rightOp) const
{
    if(this->cote() == rightOp.cote())
    {
        return this->ElementGraphique::operator<(rightOp);
    }
    else
    {
        return (this->cote() < rightOp.cote());
    }
}

bool Carre::operator<(const ElementGraphique& rightOp) const
{
    if(typeid(rightOp) == typeid(*this))
    {
        return ((*this) < static_cast<const Carre&>(rightOp));
    }
    else
    {
       return (strcmp(typeid(*this).name(), typeid(rightOp).name()) < 0);
    }
}
