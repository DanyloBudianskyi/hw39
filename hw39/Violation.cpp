#include "Violation.h"

Violation::Violation()
{
    violation = "undefined";
    when = Date();
    price = 0;
}

Violation::Violation(string violation, Date when, int price)
{
    this->violation = violation;
    this->when = when;
    this->price = price;
}

void Violation::setVioaltion(string violation)
{
    this->violation = violation;
}

void Violation::setWhen(Date when)
{
    this->when = when;
}

void Violation::setPrice(int price)
{
    this->price = price;
}

string Violation::getViolation() const
{
    return violation;
}

Date Violation::getWhen() const
{
    return when;
}

int Violation::getPrice() const
{
    return price;
}

void Violation::showInfo() const
{
    cout << "\tViolation: " << violation << endl;
    cout << "\tDate: " << when << endl;
    cout << "\tTo pay: " << price << endl << endl;
}
