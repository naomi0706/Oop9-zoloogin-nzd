#pragma once
#include <string>
#include "Person.h"
using namespace std;

// Child class - inherits from Person
// Represents an Employee's child (0..n relationship with Employee)
class Child : public Person {
private:
    string favoriteToy;

public:
    Child(string n, string ss, int a, string toy)
        : Person(n, ss, a), favoriteToy(toy) {}

    ~Child() {}

    // Getter and Setter methods for favoriteToy
    string getFavoriteToy() const { return favoriteToy; }
    void   setFavoriteToy(string t) { favoriteToy = t; }
};