#ifndef __SMS
#define __SMS
#include <string>
#include<vector>

using namespace std;
class Reseau; // Déclaration avancée de la classe Reseau


class Telephone
{
    private:
        string number="";
        Reseau* reseau = nullptr; // Pointeur vers le réseau auquel le téléphone appartient

    public:
        string getNumero() const;
        void setNumero(string newNumber);
        Telephone(string theNumber);
        Telephone();
        Reseau* getReseau() const;
        void setReseau(Reseau* network);
        
};

class Reseau
{
    private:
        vector<Telephone> reseau;
    public:
        string lister();
        Reseau();
        void ajouter(string addTelephone);
        Telephone trouveTel(string numberSearched);
        
};



#endif