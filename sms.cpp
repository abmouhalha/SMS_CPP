#include "sms.hpp"
#include <algorithm>
#include <stdexcept>

int Message::cle =0;

std::string Telephone::getNumero() const
{
    return number;
}

void Telephone::setNumero(const std::string& newNumber)
{
    number = newNumber;
}

Telephone::Telephone(const std::string& theNumber)
    : number(theNumber), reseau(nullptr), nbMessage(0)
{

}

Telephone::Telephone()
    : reseau(nullptr)
{
}

std::string Reseau::lister() const
{
    std::vector<Telephone> copieReseau = reseau;

    // Sort the copieReseau based on phone numbers
    std::sort(copieReseau.begin(), copieReseau.end(), [](const Telephone& t1, const Telephone& t2) {
        return t1.getNumero() < t2.getNumero();
    });

    std::string allReseau = "";
    for (const Telephone& telephone : copieReseau) {
        allReseau += telephone.getNumero() + "\n";
    }

    return allReseau;
}

void Reseau::ajouter(const std::string& addTelephone)
{
    reseau.emplace_back(addTelephone);
}

Reseau* Telephone::getReseau() const
{
    return reseau;
}

Telephone& Reseau::trouveTel(const std::string& numberSearched) const
{
    for (std::vector<Telephone>::size_type i = 0; i < reseau.size(); i++) {
        if (reseau[i].getNumero() == numberSearched) {
            return reseau[i]; // Return the object, not its address
        }
    }
    throw MauvaisNumero();
}





void Telephone::setReseau(Reseau* network)
{
    reseau = network;
}

SMS::SMS(){}
SMS::SMS(std::string a,std::string b,std::string c){
    expediteur=a;
    destinataire=b;
    data=c;
    }
void SMS::setTexte(std::string a){
    data=a;
}
std::string SMS::getTexte(){
    return data;
}

Message::Message(/* args */){
    id = cle;
    cle ++;
}
std::string Message::afficher(){

    return data;
}
int Message::getCle(){
    return cle;
}

int Message::getId(){
    return id;
}

int Telephone::getNbMessages()const {
    return nbMessage;
}
void Telephone::textoter(std::string dest, std::string msg)
{
    SMS sms(this->getNumero(), dest, msg);
    nbMessage++;
    // this->reseau->trouveTel(dest).addMsg();
}

void Telephone::addMsg()
{
    nbMessage++;

}


Media::Media(){}

std::string Media::afficher()const{
    return mda;
}

Image::Image(/* args */){
    mda="[[image]]";
    }

Son::Son()
{
    mda="[[son]]";
}

Video::Video()
{
    mda="[[video]]";
}