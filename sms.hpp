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
        string getNumero() ;
        void setNumero(string newNumber);
        Telephone(string theNumber);
        Telephone();



};



#endif