/*************************************************************************
                           Ensemble  -  Modélise un ensemble d'entiers
                             -------------------
    début                : 17/10/16
    copyright            : (C) 2016 par ...
    e-mail               :
*************************************************************************/

//---------- Interface du module <Ensemble> (fichier Ensemble.h) -------------------

#ifndef TP_C_ENSEMBLE_H
#define TP_C_ENSEMBLE_H

#define CARD_MAX 5


#include <iostream>

using namespace std;

enum crduEstInclus {
    NON_INCLUSION,
    INCLUSION_LARGE,
    INCLUSION_STRICTE
};

enum crduAjouter {
    DEJA_PRESENT,
    PLEIN,
    AJOUTE
};



class Ensemble
{
public:
    Ensemble(unsigned int cardMax = CARD_MAX);

    Ensemble(int t[], unsigned int nbElements);

    virtual ~Ensemble();

    void Afficher(void);

    bool EstEgal(const Ensemble &unEnsemble) const;

//    crduEstInclus EstInclus (const Ensemble & unEnsemble) const;
//
    crduAjouter Ajouter (int aAjouter);
//
//    unsigned int Ajuster (int delta);
//
//    bool Retirer (int element);
//
//    unsigned int Retirer (const Ensemble & unEnsemble);
//
//
//    int Reunir (const Ensemble & unEnsemble);
//
//    unsigned int Intersection (const Ensemble & unEnsemble);

private:
    int cardMax;
    int currentCard;
    int *elements;

    void bubbleSort();
};

#endif //TP_C_ENSEMBLE_H
