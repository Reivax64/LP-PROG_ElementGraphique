#ifndef ELEMENTGRAPHIQUE_H
#define ELEMENTGRAPHIQUE_H

#include "Point.h"

class ElementGraphique
{
    public:
        ElementGraphique();
        ElementGraphique(Point);
        ElementGraphique(Point, int);
        ElementGraphique(const ElementGraphique &);
        virtual ~ElementGraphique();

        virtual ElementGraphique& operator=(const ElementGraphique&);
        virtual bool operator==(const ElementGraphique&) const;
        virtual bool operator<(const ElementGraphique&) const;

        void placer(Point);
        Point position() const;
        static int epaisseurTrait();
        static void definirEpaisseurTrait(int);
        virtual double perimetre() const = 0;
        virtual void afficher() const;

    protected:

    private:
        static int m_epaisseur;
        Point m_point;

};

#endif // ELEMENTGRAPHIQUE_H
