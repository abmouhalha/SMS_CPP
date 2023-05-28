#ifndef __SMS
#define __SMS

#include <string>
#include <vector>
#include <stdexcept>

class Reseau; // Forward declaration of the Reseau class

class Telephone
{
private:
    std::string number;
    Reseau* reseau;
    int nbMessage;

public:
    std::string getNumero() const;
    void setNumero(const std::string& newNumber);
    Telephone(const std::string& theNumber);
    Telephone();
    Reseau* getReseau() const;
    void setReseau(Reseau* network);
    int getNbMessages()const;
    void textoter(std::string dest,std::string msg);
    void addMsg();
};

class Reseau
{
private:
    mutable std::vector<Telephone> reseau;

public:
    std::string lister() const;
    void ajouter(const std::string& addTelephone);
    Telephone& trouveTel(const std::string& numberSearched) const;
};

class MauvaisNumero : public std::invalid_argument
{
public:
    MauvaisNumero() : std::invalid_argument("mauvais numero") {}

    const char* what() const noexcept override
    {
        return std::invalid_argument::what();
    }
};

class Message
{
protected:
    std::string expediteur;
    std::string destinataire;
    std::string data;
    static int cle;
    int id;
public:
    Message(/* args */);
    std::string afficher();
    static int getCle();
    int getId();

};

class SMS : public Message
{
private:
    
public:
    SMS();
    SMS(std::string a,std::string b,std::string c);
    void setTexte(std::string a);
    std::string getTexte();
};

class Media
{
protected:
    std::string mda;
public:
    Media(/* args */);
    std::string afficher()const;
};

class Image : public Media
{
private:
    /* data */
public:
    Image(/* args */);
};

class Son : public Media
{
private:
    /* data */
public:
    Son(/* args */);
};

class Video : public Media
{
private:
    /* data */
public:
    Video(/* args */);
};


class MMS : public Message
{
private:
    /* data */
public:
    MMS(std::string a,std::string b,std::string c);
    std::string afficher();
    ~MMS();
};





#endif
