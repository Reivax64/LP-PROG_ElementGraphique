#ifndef CASEACOCHER_H
#define CASEACOCHER_H

#include "ElementActivable.h"
#include "Carre.h"

class CaseACocher : public Carre , public ElementActivable
{
    public:
        CaseACocher();
        CaseACocher(Carre,bool);
        CaseACocher(const CaseACocher&);
        virtual ~CaseACocher();

        CaseACocher& operator= (const CaseACocher&);
        bool operator==(const CaseACocher&);
        bool operator==(const ElementGraphique&);

        void afficher() const;

    protected:

    private:
};

#endif // CASEACOCHER_H
