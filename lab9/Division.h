#pragma once
#include <string>
using namespace std;

// Division класс
// Employee ажилладаг хэлтсийг илэрхийлнэ.
// Employee-тай 1-ээс-1 бүрэлдэхүүн хамааралтай.
class Division {
private:
    string divisionName;

public:
    Division(string name) : divisionName(name) {}

    ~Division() {}

    string getDivisionName() const { return divisionName; }
    void   setDivisionName(string n) { divisionName = n; }
};