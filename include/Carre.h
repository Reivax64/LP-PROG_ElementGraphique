#ifndef CARRE_H
#define CARRE_H

#include "ElementGraphique.h"


class Carre : public ElementGraphique
{
    public:
        Carre();
        Carre(Point,int);
        Carre(Point,int,int);
        Carre(const Carre&);
        virtual ~Carre();

        virtual Carre& operator= (const Carre&);
        virtual bool operator==(const Carre&);
        virtual bool operator==(const ElementGraphique&);

        virtual bool operator<(const ElementGraphique&)const;
        virtual bool operator<(const Carre&)const;

        int cote() const;
        void definirCote(int);
        double perimetre() const;
        virtual void afficher() const;


    protected:

    private:
        int m_cote;
};

#endif // CARRE_H
