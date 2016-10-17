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


void Ensemble::bubbleSort()
{
    // From http://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm

    int i, j, flag = 1;    // set flag to 1 to start first pass
    int temp;             // holding variable
    int numLength = this->currentCard;
    for (i = 1; (i <= numLength) && flag; i++)
    {
        flag = 0;
        for (j = 0; j < (numLength - 1); j++)
        {
            if (num[j + 1] > num[j])      // ascending order simply changes to <
            {
                temp = num[j];             // swap elements
                num[j] = num[j + 1];
                num[j + 1] = temp;
                flag = 1;               // indicates that a swap occurred.
            }
        }
    }
    return;   //arrays are passed to functions by address; nothing is returned
}


Ensemble::~Ensemble()
{
    delete[] this->elements;
}