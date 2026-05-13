#pragma once
#include <string>
#include "Person.h"
using namespace std;

// Spouse класс - Person-аас өвлөн авсан
// Employee-ийн нөхөр/нөхөрлөл (0..1 харилцаа) болохыг илэрхийлнэ.
class Spouse : public Person {
private:
    string anniversaryDate;

public:
    Spouse(string n, string ss, int a, string date)
        : Person(n, ss, a), anniversaryDate(date) {}

    ~Spouse() {}

    // anniversaryDate талбарын үзэгч, тохируулагч функцууд
    string getAnniversaryDate() const { return anniversaryDate; }
    void   setAnniversaryDate(string d) { anniversaryDate = d; }
};