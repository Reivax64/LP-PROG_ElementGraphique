#include "CaseACocher.h"

#include <iostream>

using namespace std;

CaseACocher::CaseACocher():
    Carre(),
    ElementActivable()
{
    //ctor
}
CaseACocher::CaseACocher(Carre c,bool a):
    Carre(c),
    ElementActivable(a)
{
    //ctor
}
CaseACocher::CaseACocher(const CaseACocher& cac):
    Carre(cac),
    ElementActivable(cac)
{
    //ctor
}
CaseACocher::~CaseACocher()
{
    //dtor
}

void CaseACocher::afficher() const
{
    cout << "je suis une case a cocher ";
    if (this->isActivated())
        cout << "active et" << endl;
    else
        cout << "inactive et" << endl;

    Carre::afficher();
}

CaseACocher& CaseACocher::operator= (const CaseACocher& cac)
{
     if(&cac != this){
        this->Carre::operator=(cac);
        this->SetisActivated(cac.isActivated());
    }
    return *this;
}
bool CaseACocher::operator==(const CaseACocher& cac)
{
    return(this->Carre::operator==(cac) && this->isActivated() == cac.isActivated());
}
bool CaseACocher::operator==(const ElementGraphique& cac)
{
    bool resultat = false;

    if (typeid(*this) == typeid(cac)){
        resultat = (*this == static_cast<const CaseACocher&>(cac));
    }

    return resultat;
}
