#pragma once
#include <string>
#include "Person.h"
using namespace std;

// Spouse class - inherits from Person
// Represents an Employee's spouse (0..1 relationship with Employee)
class Spouse : public Person {
private:
    string anniversaryDate;

public:
    Spouse(string n, string ss, int a, string date)
        : Person(n, ss, a), anniversaryDate(date) {}

    ~Spouse() {}

    // Getter and Setter methods for anniversaryDate
    string getAnniversaryDate() const { return anniversaryDate; }
    void   setAnniversaryDate(string d) { anniversaryDate = d; }
};