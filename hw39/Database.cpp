#include "Database.h"

void Database::addViolation(string number, Violation violation)
{
	database[number].push_back(violation);
}

void Database::payViolation(string carNumber, int number)
{
	map<string, vector<Violation>>::iterator item = database.find(carNumber);
	if (item == database.end()) {
		cout << "Car number not found\n";
	}
	else {
		if (number > item->second.size()) {
			cout << "Violation not found\n";
		}
		else {
			item->second.erase(item->second.begin() + number);
			cout << "You paid for violation\n";
		}
		if (item->second.size() == 0) {
			database.erase(carNumber);
		}
	}
}

void Database::findInPeriod(Date start, Date end) const
{
	map<string, vector<Violation>>::const_iterator item;
	if (database.empty()) {
		cout << "No violations found\n";
		return;
	}
	else {
		cout << "Violations in period " << start << " - " << end << endl;
		for (item = database.begin(); item != database.end(); item++) {
			for (auto it : item->second) {
				if (it.getWhen() >= start && it.getWhen() <= end) {
					cout << "Car number: " << item->first << ". Violation - " << it.getViolation() << endl;
				}
			}
		}
	}
}

void Database::calcViolations(string number) const
{
	map<string, vector<Violation>>::const_iterator item = database.find(number);
	if (item == database.end()) {
		cout << "Car number not found\n";
	}
	else {
		int total = 0;
		for (int i = 0; i < item->second.size(); i++) {
			total += item->second[i].getPrice();
		}
		cout << "Total price: " << total << endl;
	}
}

void Database::showAll() const
{
	if (database.size() == 0) {
		cout << "Database is empty\n";
	}
	else
	{
		map<string, vector<Violation>>::const_iterator item;
		for (item = database.begin(); item != database.end(); item++) {
			cout << item->first << ":" << endl;
			for (auto violation : item->second) {
				violation.showInfo();
			}
		}
	}
}
