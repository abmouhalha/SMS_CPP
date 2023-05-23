#ifndef __SMS
#define __SMS
#include <string>
#include<vector>

using namespace std;

class Telephone
{
    private:
        string number="";
    public:
        string getNumero() const;
        void setNumero(string newNumber);
        Telephone(string theNumber);
        Telephone();



};

class Reseau
{
    private:
        vector<Telephone> reseau;
    public:
        string lister();
        Reseau();
        void ajouter(string addTelephone);

};



#endif