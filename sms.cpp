#include "sms.hpp"
#include <algorithm>
#include <stdexcept>


std::string Telephone::getNumero() const
{
    return number;
}

void Telephone::setNumero(const std::string& newNumber)
{
    number = newNumber;
}

Telephone::Telephone(const std::string& theNumber)
    : number(theNumber), reseau(nullptr)
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

const Telephone& Reseau::trouveTel(const std::string& numberSearched) const
{
    for (const Telephone& telephone : reseau) {
        if (telephone.getNumero() == numberSearched) {
            return telephone;
        }
    }
    throw MauvaisNumero();}


void Telephone::setReseau(Reseau* network)
{
    reseau = network;
}

