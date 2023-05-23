#include "sms.hpp"
#include <iostream>
#include<string>
#include <cstring>
#include <stack>
#include<algorithm>


int Message::cle=0;

////////////////////////////////////////////////////////////Message ////////////////////////////////////////////////////////////////////////

Telephone::Telephone():num(""),nb_msg(0){ }


Telephone::Telephone(std::string a): num(a),nb_msg(0){}




std::string Telephone::getNumero()const{
    
    return num;
}


void Telephone::textoter(std::string a,std::string b){
    nb_msg++;
}

void Telephone::setNumero(const std::string&  a){

   num =a;

}
int Telephone::getReseau()const{

    return 0;
}


int Telephone::getNbMessages()const{
    return nb_msg;
}



Telephone::~Telephone(){}




 ///  ////////////////////////////////////////////////reseau/////////////////////////////////////////////////////////////////////////
 Reseau:: Reseau():indice(0),m_numeros(new std::string[100])
{

}
 Reseau::~Reseau()
{
}
// void Reseau::ajouter(const std::string& numero) {
    //     m_numeros.push_back(numero);
    // }

// std::string Reseau::lister() const {
//     std::vector<std::string> sorted_numeros(m_numeros);
//     std::sort(sorted_numeros.begin(), sorted_numeros.end());

//     std::string result;
//     for (const auto& numero : sorted_numeros) {
//         result += numero + "\n";
//     }
//     return result;
// }

void Reseau::ajouter(const std::string& numero) {
    m_numeros[indice]=numero;
    indice++;
}

std::string Reseau::lister() const{

    std::vector<std::string> sorted_num(m_numeros,m_numeros+1);
    std::sort(sorted_num.begin(),sorted_num.end());

    std::string resultat;
    for(const std::string& numero : sorted_num){
        resultat+=numero+ "\n";
    }

    return resultat;

}


Telephone Reseau::trouveTel(const std::string& numero) const {
    for (int i = 0; i < indice; i++) {
        if (m_numeros[i] == numero) {
            return Telephone(m_numeros[i]);
        }
    }
    throw std::runtime_error("Le numéro n'existe pas dans le réseau.");
}



MauvaisNumero::MauvaisNumero(){}

   
MauvaisNumero::~MauvaisNumero(){}

const char* MauvaisNumero::what() noexcept{

    return msg.c_str();
}



//////////////////////////////////////////// SMS  //////////////////////////////////////////////////////////////
SMS::SMS(std::string a, std::string b, std::string d):num1(a),num2(b),dat(d)
{
}

void SMS::setTexte(std::string nsg){
    msg=nsg;
}
std::string SMS::getTexte(){
    return msg;
}
std::string SMS::afficher(){
    return msg;
}

SMS::~SMS()
{
}

//////////////////////////////////////////////////////////////message .////////////////////////////////////////////////////////////////

 Message::Message():id(cle){
    cle ++;
 }
const int Message::getId() const{
    return id;
}

int Message::getCle(){
        return cle;
    }
 Message::~Message(){}