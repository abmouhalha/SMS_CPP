#include "sms.hpp"
#include <iostream>
#include<string>
#include <cstring>
#include <stack>
#include<algorithm>


string Telephone::getNumero() const 
{
    return number;
}

void Telephone::setNumero(string newNumber)
{
    number = newNumber;
}

Telephone::Telephone(string theNumber):number(theNumber)
{

}

Telephone::Telephone()
{

}


string Reseau::lister()
{
    string allReseau="";
     for (int i = 0; i < reseau.size(); i++) {
       allReseau += reseau[i].getNumero() + "\n";
    }

    return allReseau;
}

Reseau::Reseau(){}

void Reseau::ajouter(string addTelephone){
    reseau.push_back(addTelephone);
}

