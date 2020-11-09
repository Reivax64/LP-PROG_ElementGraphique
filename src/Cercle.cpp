#include "Cercle.h"

#include <iostream>
#include <cstring>
using namespace std;

Cercle::Cercle():
    ElementGraphique(),
    m_rayon(1)
{
}

Cercle::Cercle(Point p, int r):
    ElementGraphique(p),
    m_rayon(r)
{
}

Cercle::Cercle(Point p, int t, int r):
    ElementGraphique(p,t),
    m_rayon(r)
{
}

Cercle::Cercle(const Cercle& c):
    ElementGraphique(c),
    m_rayon(c.rayon())
{
}

Cercle::~Cercle()
{
    //dtor
}

int Cercle::rayon() const{
    return this->m_rayon;
}

void Cercle::definirRayon(int r){
    this->m_rayon = r;
}

double Cercle::perimetre() const{
    return (2 * 3.14 * this->rayon());
}

void Cercle::afficher() const{

    cout << "je suis un Cercle de rayon " << this->rayon() << " et " <<endl;
    this->ElementGraphique::afficher();

}

Cercle& Cercle::operator=(const Cercle& c){
    if(&c != this){
        this->ElementGraphique::operator=(c);
        this->definirRayon(c.rayon());
    }
    return *this;
}

bool Cercle::operator==(const Cercle& c){
    return(this->ElementGraphique::operator==(c) && this->rayon() == c.rayon());
}

bool Cercle::operator==(const ElementGraphique& c){
    bool resultat = false;

    if (typeid(*this) == typeid(c)){
        resultat = (*this == static_cast<const Cercle&>(c));
    }

    return resultat;
}

bool Cercle::operator<(const Cercle& rightOp) const
{
    if(this->rayon() == rightOp.rayon())
    {
        return this->ElementGraphique::operator<(rightOp);
    }
    else
    {
        return (this->rayon() < rightOp.rayon());
    }
}

bool Cercle::operator<(const ElementGraphique& rightOp) const
{
    if(typeid(rightOp) == typeid(*this))
    {
        return ((*this) < static_cast<const Cercle&>(rightOp));
    }
    else
    {
       return (strcmp(typeid(*this).name(), typeid(rightOp).name()) < 0);
    }
}
