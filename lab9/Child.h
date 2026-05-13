#pragma once
#include <string>
#include "Person.h"
using namespace std;

// Child класс - Person-аас өвлөн авсан
// Employee-ийн хүүхдийг (0..n харилцаа) илэрхийлнэ.
class Child : public Person {
private:
    string favoriteToy;

public:
    Child(string n, string ss, int a, string toy)
        : Person(n, ss, a), favoriteToy(toy) {}

    ~Child() {}

    // favoriteToy талбарын үзэгч, тохируулагч функцууд
    string getFavoriteToy() const { return favoriteToy; }
    void   setFavoriteToy(string t) { favoriteToy = t; }
};