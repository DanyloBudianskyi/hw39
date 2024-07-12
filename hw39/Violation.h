#pragma once
#include "Date.h"
#include <string>

class Violation
{
	string violation;
	Date when;
	int price;
public:
	Violation();
	Violation(string violation, Date when, int price);

	void setVioaltion(string violation);
	void setWhen(Date when);
	void setPrice(int price);

	string getViolation()const;
	Date getWhen()const;
	int getPrice()const;

	void showInfo()const;
};

