#pragma once
#include <string>
using namespace std;

// JobDescription class
// Represents a specific role or task assigned to an Employee.
// Has a 1..n composition relationship with an Employee.
class JobDescription {
private:
    string description;

public:
    JobDescription(string d) : description(d) {}

    ~JobDescription() {}

    string getDescription() const { return description; }
    void   setDescription(string d) { description = d; }
};