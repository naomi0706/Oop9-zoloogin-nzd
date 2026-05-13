#pragma once
#include <string>
using namespace std;

// JobDescription класс
// Employee-д даалгасан тодорхой үүрэг, ажлыг илэрхийлнэ.
// Employee-тай 1..n бүрэлдэхүүн хамааралтай.
class JobDescription {
private:
    string description;

public:
    JobDescription(string d) : description(d) {}

    ~JobDescription() {}

    string getDescription() const { return description; }
    void   setDescription(string d) { description = d; }
};