#pragma once
#include <string>
using namespace std;

// Division class
// Represents a department where an Employee works.
// Has a 1-to-1 composition relationship with an Employee.
class Division {
private:
    string divisionName;

public:
    Division(string name) : divisionName(name) {}

    ~Division() {}

    string getDivisionName() const { return divisionName; }
    void   setDivisionName(string n) { divisionName = n; }
};