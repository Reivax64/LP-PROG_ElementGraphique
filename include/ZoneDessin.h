#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#define TAILLE 10

#include "ElementGraphique.h"
#include <vector>

using namespace std;

class PEG
{
protected:
    ElementGraphique *m_base;
    const ElementGraphique *m_constBase;
public:
    ElementGraphique *getBase()const
    {
        return this->m_base;
    }
    bool operator==(const PEG &opD)const
    {
        return (*(this->m_constBase)) == (*(opD.m_constBase));
    }
    bool operator<(const PEG &opD)const
    {
        return (*(this->m_constBase)) < (*(opD.m_constBase));
    }
    PEG(ElementGraphique *pEG):
        m_base(pEG),
        m_constBase(pEG)
    {}
    PEG(const ElementGraphique *pEG):
        m_base(NULL),
        m_constBase(pEG)
    {}
    PEG(const PEG &ori):
        m_base(ori.m_base),
        m_constBase(ori.m_constBase)
    {}
};

class ZoneDessin
{
public:
    ZoneDessin();
    ZoneDessin(int,int);
    ZoneDessin(const ZoneDessin&);
    virtual ~ZoneDessin();

    ZoneDessin& operator=(const ZoneDessin&);
    bool operator==(const ZoneDessin&);

    void dimensionner(int,int);
    int largeur() const;
    int hauteur() const;
    int ajouterFin(ElementGraphique*);
    bool enlever(int);
    ElementGraphique* element(int) const;
    void afficher() const;
    int nbElements() const;
    int rechercheIndice (const ElementGraphique &) const;
    void trier();



protected:

private:

    int m_largeur;
    int m_hauteur;
    vector<PEG> m_tabElementGraphique;
};



#endif // ZONEDESSIN_H
