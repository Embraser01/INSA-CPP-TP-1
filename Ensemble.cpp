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
        for (int i = 0; i < currentCard - 1; i++)
        {
            cout << this->elements[i] << ",";
        }
        cout << this->elements[currentCard - 1];

    }

    cout << "}\r\n";

}

crduAjouter Ensemble::Ajouter(int aAjouter)
{
    if (cardMax == 0)
    {
        return PLEIN;
    }
    //on verifie si l'element est present,
    // a  la fin, i est l'index
    for (int i = 0; i < currentCard; i++)
    {
        if (elements[i] == aAjouter)
        {
            return DEJA_PRESENT;
        }
    }
    if (this->cardMax > this->currentCard)
    {
        elements[currentCard] = aAjouter;
        this->currentCard++;
        this->bubbleSort();
        return AJOUTE;
    } else
    {
        //renvoyer plein
        return PLEIN;
    }
}

bool Ensemble::EstEgal(const Ensemble &unEnsemble) const
{
    if (this->currentCard != unEnsemble.currentCard) return false;


    for (int i = 0; i < this->currentCard; i++)
    {
        if (this->elements[i] != unEnsemble.elements[i])
        {
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
            if (elements[j + 1] < elements[j])      // ascending order simply changes to <
            {
                temp = elements[j];             // swap elements
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
                flag = 1;               // indicates that a swap occurred.
            }
        }
    }
    return;   //arrays are passed to functions by address; nothing is returned
}


unsigned int Ensemble::Ajuster(int delta)
{
    if (delta == 0)
    {
        return cardMax;
    }

    int *nouveauEnsemble;
    int nouvelleCard;
    if (delta > 0)
    {
        nouvelleCard = cardMax + delta;
        nouveauEnsemble = new int[cardMax + delta];
    } else
    {
        nouvelleCard = (cardMax + delta > currentCard) ? cardMax + delta : currentCard;
        nouveauEnsemble = new int[nouvelleCard];
    }
    for (int i = 0; i < currentCard; i++)
    {
        nouveauEnsemble[i] = elements[i];
    }
    cardMax = nouvelleCard;
    delete[] elements;// gare aux fuites de memeoire
    elements = nouveauEnsemble;

    return cardMax;
}


crduEstInclus Ensemble::EstInclus(const Ensemble &unEnsemble) const
{
    if (EstEgal(unEnsemble))
    {
        return INCLUSION_LARGE;
    }
    int j = 0;
    for (int i = 0; i < currentCard; i++)
    {
        // Tab triés donc pas de réinitialisation
        for (j; unEnsemble.elements[j] < elements[i]; j++)
        {}
        if (elements[i] != unEnsemble.elements[j])
        {
            return NON_INCLUSION;
        }
    }
    return INCLUSION_STRICTE;
}

bool Ensemble::Retirer(int element)
{
    if (currentCard == 0)
    {
        return false;
    }
    if (elements[0] < element || elements[currentCard - 1] < element)
    {
        return false;
    }
    //maintenant on est sur que element est contenu dans notre ensemble
    int *nouveauEnsemble = new int[currentCard - 1];
    int j = 0;
    for (int i = 0; i < cardMax; i++)
    {
        int n = elements[i];
        if (n != element)
        {
            //on fait une post incrementation, pour modifier la case
            //avant d'avancer le compteur
            nouveauEnsemble[j++] = n;
        }
    }
    delete[] elements;
    elements = nouveauEnsemble;
    currentCard--;
    cardMax = currentCard;
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
            if (elements[j + 1] < elements[j])      // ascending order simply changes to <
            {
                temp = elements[j];             // swap elements
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
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