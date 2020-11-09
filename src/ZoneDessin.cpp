#include "ZoneDessin.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;
ZoneDessin::ZoneDessin():
    m_largeur(1),
    m_hauteur(1)
{
}

ZoneDessin::ZoneDessin(int l,int h):
    m_largeur(l),
    m_hauteur(h)
{
}

ZoneDessin::ZoneDessin(const ZoneDessin& zs):
    m_largeur(zs.largeur()),
    m_hauteur(zs.hauteur())
{
    for (int i = 0; i < zs.nbElements() ; i++ )
    {
        this->ajouter(zs.element(i));
    }
}

ZoneDessin::~ZoneDessin(){}

void ZoneDessin::dimensionner(int l,int h) {
    this->m_largeur = l;
    this->m_hauteur = h;
}

int ZoneDessin::largeur() const
{
    return this->m_largeur;
}
int ZoneDessin::hauteur() const
{
    return this->m_hauteur;
}

int ZoneDessin::ajouter(ElementGraphique* eg)
{
    this->m_tabElementGraphique.insert(eg);

    return m_tabElementGraphique.size()-1;
}
bool ZoneDessin::enlever(const ElementGraphique& eg)
{
    bool retour;
    int taille = this->m_tabElementGraphique.size();
    this->m_tabElementGraphique.erase(PEG(&eg));

    if(this->m_tabElementGraphique.size() == taille){

        retour = false;
    }else{
        retour = true;
    }



    return retour;
}

void ZoneDessin::afficher() const {


    for (set<PEG>::const_iterator it = this->m_tabElementGraphique.begin(); it != this->m_tabElementGraphique.end() ; it++ )
        {
            //cout << i << ")" << endl;
            it->getBase()->afficher();
        }
}

int ZoneDessin::nbElements() const
{
    return m_tabElementGraphique.size();
}

ZoneDessin& ZoneDessin::operator=(const ZoneDessin& zs){
    if(&zs != this){
        this->dimensionner(zs.largeur(),zs.hauteur());
        for (int i = 0;i < zs.nbElements() ; i++ )
            {
                this->ajouter(zs.element(i));
            }
    }
    return *this;
}

bool ZoneDessin::operator==(const ZoneDessin& zs){
    bool resultat;
    resultat = (this->hauteur() == zs.hauteur() && this->largeur() == zs.largeur() && this->nbElements() == zs.nbElements());

    if(resultat){
        for (int i = 0;i < this->nbElements() ; i++ )
            {
                resultat = (this->element(i) == zs.element(i));
                if(!resultat)
                    break;
            }
    }
    return resultat;
}

int ZoneDessin::rechercheIndice (const ElementGraphique & eg) const
{
    //set<PEG>::const_iterator it = find(this->m_tabElementGraphique.begin(),this->m_tabElementGraphique.end(),PEG(&eg));

    set<PEG>::const_iterator it = this->m_tabElementGraphique.find(PEG(&eg));

    if (it == this->m_tabElementGraphique.end())
    {
        return -1;
    }
    else
    {
        return distance(this->m_tabElementGraphique.begin(),it);
    }


}
