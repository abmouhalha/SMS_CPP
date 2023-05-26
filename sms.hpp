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

public:
    std::string getNumero() const;
    void setNumero(const std::string& newNumber);
    Telephone(const std::string& theNumber);
    Telephone();
    Reseau* getReseau() const;
    void setReseau(Reseau* network);
};

class Reseau
{
private:
    std::vector<Telephone> reseau;

public:
    std::string lister() const;
    void ajouter(const std::string& addTelephone);
    const Telephone& trouveTel(const std::string& numberSearched) const;
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



#endif
