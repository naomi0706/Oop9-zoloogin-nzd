#pragma once
#include <string>
#include "Person.h"
using namespace std;

// Child клас — Person-оос удамших (0..n харьцаа Employee-тэй)
class Child : public Person {
private:
    string favoriteToy;

public:
    Child(string n, string ss, int a, string toy)
        : Person(n, ss, a), favoriteToy(toy) {}

    ~Child() {}

    // Getter, Setter
    string getFavoriteToy() const { return favoriteToy; }
    void   setFavoriteToy(string t) { favoriteToy = t; }
};