//
// Created by marca on 17/10/2016.
//

#include "Ensemble.h"
Ensemble ::Ensemble(unsigned int cardMax) {
    collection = new int [cardMax];
}



Ensemble::Ensemble(int *t, unsigned int nbElements)
{

}

Ensemble::~Ensemble()
{
    delete[] collection;
}