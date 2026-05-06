#pragma once
#include <string>
using namespace std;

// Base Person class
// This class serves as the parent class for Employee, Child, and Spouse.
// It contains common attributes shared among all people in this system.
class Person {
private:
    string name;
    string ssNum;
    int    age;

public:
    // Constructor
    // Initializes the basic person details.
    Person(string n, string ss, int a)
        : name(n), ssNum(ss), age(a) {}

    // Virtual Destructor
    // Required because this class is intended to be used as a base class.
    // It ensures that derived class destructors are called properly.
    virtual ~Person() {}

    // Getter methods
    string getName()   const { return name; }
    string getSSNum()  const { return ssNum; }
    int    getAge()    const { return age; }

    // Setter methods
    void setName(string n)   { name  = n; }
    void setSSNum(string ss) { ssNum = ss; }
    void setAge(int a)       { age   = a; }
};