#pragma once
#include <string>
#include "Person.h"
using namespace std;

// Spouse клас — Person-оос удамших (0..1 харьцаа Employee-тэй)
class Spouse : public Person {
private:
    string anniversaryDate;

public:
    Spouse(string n, string ss, int a, string date)
        : Person(n, ss, a), anniversaryDate(date) {}

    ~Spouse() {}

    // Getter, Setter
    string getAnniversaryDate() const { return anniversaryDate; }
    void   setAnniversaryDate(string d) { anniversaryDate = d; }
};