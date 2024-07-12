#pragma once
#include "Violation.h"
#include <map>
#include <vector>

class Database
{
	map<string, vector<Violation>> database;
public:
	void addViolation(string number, Violation violation);
	void payViolation(string carNumber, int number);
	void findInPeriod(Date start, Date end)const;
	void calcViolations(string number)const;
	void showAll()const;
};

