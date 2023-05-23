#include "sms.hpp"
#include <iostream>
#include<string>
#include <cstring>
#include <stack>
#include<algorithm>


string Telephone::getNumero() 
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


