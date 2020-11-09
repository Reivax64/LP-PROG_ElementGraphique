#include "Bouton.h"
#include <iostream>

using namespace std;
Bouton::Bouton():
    Cercle(),
    ElementActivable()
{
    //ctor
}
Bouton::Bouton(Cercle c, bool a):
    Cercle(c),
    ElementActivable(a)
{
    //ctor
}
Bouton::Bouton(const Bouton& b):
    Cercle(b),
    ElementActivable(b)
{
    //ctor
}

Bouton::~Bouton()
{
    //dtor
}

Bouton& Bouton::operator=(const Bouton& b)
{
    if(&b != this){
        this->Cercle::operator=(b);
        this->SetisActivated(b.isActivated());
    }
    return *this;
}
bool Bouton::operator==(const Bouton& b)
{
    return(this->Cercle::operator==(b) && this->isActivated() == b.isActivated());
}
bool Bouton::operator==(const ElementGraphique& b)
{
    bool resultat = false;

    if (typeid(*this) == typeid(b)){
        resultat = (*this == static_cast<const Bouton&>(b));
    }

    return resultat;
}

void Bouton::afficher() const
{
    cout << "je suis un bouton ";
    if (this->isActivated())
        cout << "actif et" << endl;
    else
        cout << "inactif et" << endl;

    Cercle::afficher();
}
