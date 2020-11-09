#ifndef BOUTON_H
#define BOUTON_H

#include "ElementActivable.h"
#include "Cercle.h"

class Bouton : public Cercle , public ElementActivable
{
    public:
        Bouton();
        Bouton(Cercle,bool);
        Bouton(const Bouton&);
        virtual ~Bouton();

        Bouton& operator=(const Bouton&);
        bool operator==(const Bouton&);
        bool operator==(const ElementGraphique&);

        void afficher() const;

    protected:

    private:
};

#endif // BOUTON_H
