#pragma once
#include <string>
using namespace std;

// Хэлтэс — Employee-тэй 1 харьцаатай
class Division {
private:
    string divisionName;

public:
    Division(string name) : divisionName(name) {}

    ~Division() {}

    string getDivisionName() const { return divisionName; }
    void   setDivisionName(string n) { divisionName = n; }
};