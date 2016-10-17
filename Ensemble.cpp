//
// Created by marca on 17/10/2016.
//

#include "Ensemble.h"

Ensemble::Ensemble(unsigned int cardMax)
{
    this->elements = new int[cardMax];
    this->cardMax = cardMax;
    this->currentCard = 0;
}

Ensemble::Ensemble(int *t, unsigned int nbElements)
{

    this->elements = new int[nbElements];
    this->cardMax = nbElements;
    this->currentCard = 0;

    for (int i = 0; i < nbElements; i++)
    {
        this->Ajouter(t[i]);
    }
}


void Ensemble::Afficher()
{
    cout << this->currentCard << "\r\n";
    cout << this->cardMax << "\r\n";

    cout << "{";


    if (this->currentCard == 1)
    {
        cout << this->elements[0];

    } else if (this->currentCard > 1)
    {
        for (int i=0; i<currentCard-1; i++){
            cout <<this->elements[i] <<",";
        }
        cout <<this->elements[currentCard-1];

    }

    cout << "}\r\n";

}

bool Ensemble::EstEgal(const Ensemble &unEnsemble) const {
    if(Ensemble->cardMax != unEnsemble.cardMax || Ensemble->currentCard!=unEnsemble.currentCard){
        return false;
    }
    for (int i=0;i<Ensemble.currentCard;i++){
        if (Ensemble->elements[i] != unEnsemble->elements[i]){
            return false;
        }
    }
    return true;
}

Ensemble::~Ensemble()
{
    delete[] this->elements;
}

crduAjouter Ensemble::Ajouter(int aAjouter)
{
    if (cardMax == 0){
        return crduAjouter::PLEIN;
    }
    //on verifie si l'element est present,
    // a  la fin, i est l'index
    int d = currentCard/2;
    int i = d;
    while( d!=0 )
    {
        d =  d/2;
        int n = this->elements[i];
        if(n == aAjouter){
            return crduAjouter::DEJA_PRESENT;
        }else if(aAjouter > n)
        {
            i-= d;
        }else{
            i+= d;
        }
    }
    if(this->cardMax > this->currentCard)
    {
        elements[currentCard]=aAjouter;
        //appel a la fonction de tri
        return crduAjouter::AJOUTE;
    } else{
        //renvoyer plein
        return crduAjouter::PLEIN;
    }
}