#include "ElementActivable.h"

#include <iostream>

using namespace std;

ElementActivable::ElementActivable():
    m_isActivated(false)
{
    //ctor
}

ElementActivable::ElementActivable(bool a):
    m_isActivated(a)
{
    //ctor
}

ElementActivable::ElementActivable(const ElementActivable& ea):
    m_isActivated(ea.isActivated())
{
    //ctor
}

ElementActivable::~ElementActivable()
{
    //dtor
}
bool ElementActivable::isActivated() const
{
    return m_isActivated;
}
void ElementActivable::SetisActivated(bool val)
{
    m_isActivated = val;
}
void ElementActivable::afficher()
{
    cout << "je suis un Element Activable ";
    if (this->isActivated())
        cout << "actif" << endl;
    else
        cout << "inactif" << endl;
}

ElementActivable& ElementActivable::operator=(const ElementActivable& ea)
{
    if(&ea != this){
        this->SetisActivated(ea.isActivated());
    }
    return *this;
}
bool ElementActivable::operator==(const ElementActivable& ea)
{
    return (this->isActivated() == ea.isActivated());
}
