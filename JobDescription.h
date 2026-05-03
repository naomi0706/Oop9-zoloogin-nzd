#pragma once
#include <string>
using namespace std;

// Ажлын тодорхойлолт — Employee-тэй 1..n харьцаатай
class JobDescription {
private:
    string description;

public:
    JobDescription(string d) : description(d) {}

    ~JobDescription() {}

    string getDescription() const { return description; }
    void   setDescription(string d) { description = d; }
};