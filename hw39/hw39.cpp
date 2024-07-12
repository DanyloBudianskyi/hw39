#include "Database.h"

int main()
{
    Database database;

    database.findInPeriod(Date() - 14, Date() - 5);
    cout << "-------------------------------\n";
    database.addViolation("AX0000AX", Violation("Red light", Date(), 500));
    database.addViolation("AX0000AX", Violation("Speed", Date() - 13, 2500));
    database.addViolation("AX1111AX", Violation("Parking", Date() - 10, 700));
    database.findInPeriod(Date() - 14, Date() - 5);
    cout << "-------------------------------\n";
    database.showAll();    
    cout << "-------------------------------\n";
    database.calcViolations("AX0000AX");
    cout << "-------------------------------\n";
    database.payViolation("AX0000AX", 0);
    database.showAll();
}