#include <iostream>

#include "ElementGraphique.h"
#include "Carre.h"
#include "Cercle.h"
#include "Point.h"
#include "ZoneDessin.h"
#include "ElementActivable.h"
#include "Bouton.h"
#include "CaseACocher.h"


using namespace std;

int main()
{
    char rep,rep2;
    string retour;
    bool retourEnlever;
    bool actif;
    int x =0, y=0, trait = 0, cote_rayon = 0, index = 0;
    ElementGraphique* eg;
    Cercle* sphere;
    Carre* cube;
    CaseACocher* cac;
    Bouton* b;

    ZoneDessin zs;

    do
    {
        // system("cls") permet d'enlever ce menu après une réponse.
        system("cls");
        cout << "Nombre d'elements : " << zs.nbElements() << " | Epaisseur trait : " << ElementGraphique::epaisseurTrait() << endl
             << "AJOUT (a) ? ENLEVER (e) ? AFFICHER (s) ? RECHERCHER (r) ? Changer trait (t) ? Trier (z) ? Quitter (q) ?" << endl;
        cin >> rep;
        system("cls");

        switch (rep)
        {
        case 'a':
            if (zs.nbElements() == 10)
            {
                cout << "La zone de dessin est pleine" << endl;
                // La pause permet d'afficher le cout précédent avant de retourner sur le menu principal.
                system("pause");
            }
            else
            {
                cout << "Cercle (1) ? Carre (2) ? Case a cocher (3) ? Bouton (4) ?" << endl;
                cin >> rep2;

                cout << "x : ";
                cin >> x;

                cout << "y : ";
                cin >> y;

                cout << "taille cote/rayon : ";
                cin >> cote_rayon;

                switch (rep2)
                {
                case '1':
                    zs.ajouterFin(new Cercle(Point(x,y), cote_rayon));
                    break;
                case '2':
                    zs.ajouterFin(new Carre(Point(x,y), cote_rayon));
                    break;
                case '3':
                    cout << "active ? : ";
                    cin >> actif;
                    zs.ajouterFin(new CaseACocher(Carre(Point(x,y), cote_rayon), actif));
                    break;
                case '4':
                    cout << "actif ? : ";
                    cin >> actif;
                    zs.ajouterFin(new Bouton(Cercle(Point(x,y), cote_rayon), actif));
                    break;

                default:
                    break;
                }
            }
            break;

        case 'e':
            cout << "index : ";
            cin >> index;
            eg = zs.element(index);
            retourEnlever = zs.enlever(index);
            if (retourEnlever)
            {
                cout << "L'element a ete enleve";
                delete eg;
            }
            else
                cout << "L'element n'a pas pu etre enleve";

            cout << endl << "Retour au menu" << endl;
            system("pause");
            break;
        case 'r':
            cout << "Cercle (1) ? Carre (2) ? Case a cocher (3) ? Bouton (4) ?" << endl;
                cin >> rep2;

                cout << "x : ";
                cin >> x;

                cout << "y : ";
                cin >> y;

                cout << "taille cote/rayon : ";
                cin >> cote_rayon;

                switch (rep2)
                {
                case '1':
                    cout << endl;
                    sphere = new Cercle(Point(x,y),cote_rayon);
                    cout << "Indice : " << zs.rechercheIndice(*sphere) << endl;
                    delete sphere;
                    break;
                case '2':
                    cout << endl;
                    cube = new Carre(Point(x,y),cote_rayon);
                    cout << "Indice : " << zs.rechercheIndice(*cube) << endl;
                    delete cube;
                    break;
                case '3':
                    cout << "active ? : ";
                    cin >> actif;
                    cout << endl;
                    cac = new CaseACocher(Carre(Point(x,y),cote_rayon),actif);
                    cout << "Indice : " << zs.rechercheIndice(*cac) << endl;
                    break;
                case '4':
                    cout << "actif ? : ";
                    cin >> actif;
                    cout << endl;
                    b = new Bouton(Cercle(Point(x,y),cote_rayon),actif);
                    cout << "Indice : " << zs.rechercheIndice(*b) << endl;
                    break;

                default:
                    break;
                }
                system("pause");
            break;

        case 's':
            zs.afficher();
            cout << endl << "Retour au menu"<< endl;
            system("pause");
            break;
        case 't':
            cout << "trait : ";
            cin >> trait;
            cout << endl;
            ElementGraphique::definirEpaisseurTrait(trait);
            break;
        case 'z':
            zs.trier();
            break;

        default:
            break;
        }

    }
    while (rep != 'q');

    while(zs.nbElements() > 0)
    {
        eg = zs.element(0);
        zs.enlever(0);
        delete eg;
    }

    return 0;
}
