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
    vector<Telephone> copieReseau = reseau;

    // Trie la copieReseau selon le numéro de téléphone
    sort(copieReseau.begin(), copieReseau.end(), [](const Telephone& t1, const Telephone& t2) {
        return t1.getNumero() < t2.getNumero();
    });

    string allReseau = "";
    for (int i = 0; i < copieReseau.size(); i++) {
        allReseau += copieReseau[i].getNumero() + "\n";
    }

    return allReseau;
}

Reseau::Reseau(){}

void Reseau::ajouter(string addTelephone){
    reseau.push_back(addTelephone);
}

Telephone Reseau::trouveTel(string numberSearched)
{
    Telephone defaultNumber;
    Reseau* network= this;
    for (int i = 0; i < reseau.size(); i++) {

        if( reseau[i].getNumero() == numberSearched )
        {   
            defaultNumber.setReseau( network );
            delete network;
            return reseau[i];
        }
    }
    delete network;
   
    return defaultNumber;

}

Reseau* Telephone::getReseau() const
{
    return reseau;
}

void Telephone::setReseau(Reseau* network)
{
   *reseau = *network;
}
