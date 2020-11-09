#include "ElementGraphique.h"

#include <iostream>

using namespace std;

int ElementGraphique::m_epaisseur = 1;

ElementGraphique::ElementGraphique():
    m_point()
{
}

ElementGraphique::ElementGraphique(Point p) :
    m_point(p)
{
}

ElementGraphique::ElementGraphique(Point p, int et) :
    m_point(p)
{
    this->definirEpaisseurTrait(et);
}

ElementGraphique::ElementGraphique(const ElementGraphique& eg) :
    m_point(eg.position())
{
}

ElementGraphique::~ElementGraphique()
{
}

void ElementGraphique::placer(Point p){
    this->m_point.placer(p.x(),p.y());
}

Point ElementGraphique::position() const{
    return this->m_point;
}

int ElementGraphique::epaisseurTrait(){
    return m_epaisseur;
}

void ElementGraphique::definirEpaisseurTrait(int et){
    m_epaisseur = et;
}

void ElementGraphique::afficher() const{
     cout << "je suis un Element graphique avec pour trait " << this->epaisseurTrait()
          << " placer en " << this->position().x() << " " << position().y()
          << " et mon perimetre est de " << this->perimetre() << endl;
}

ElementGraphique& ElementGraphique::operator=(const ElementGraphique& eg){
    if(&eg != this){
        this->placer(eg.position());
    }
    return *this;
}

bool ElementGraphique::operator==(const ElementGraphique& eg) const{
    return (this->position() == eg.position());
}

bool ElementGraphique::operator<(const ElementGraphique& eg) const{
    if(this->position().x() < eg.position().x())
        return true;
    if(this->position().y() < eg.position().y())
        return true;
    return false;
}


