#ifndef CERCLE_H
#define CERCLE_H

#include "ElementGraphique.h"


class Cercle : public ElementGraphique
{
    public:
        Cercle();
        Cercle(Point,int);
        Cercle(Point,int,int);
        Cercle(const Cercle&);
        virtual ~Cercle();

        virtual Cercle& operator=(const Cercle&);
        virtual bool operator==(const Cercle&);
        virtual bool operator==(const ElementGraphique&);
        virtual bool operator<(const ElementGraphique&) const;
        virtual bool operator<(const Cercle&)const;

        int rayon() const;
        void definirRayon(int);
        double perimetre() const;
        virtual void afficher() const;


    protected:

    private:
        int m_rayon;
};

#endif // CERCLE_H
