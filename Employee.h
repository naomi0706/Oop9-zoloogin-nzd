#pragma once
#include <string>
#include <vector>
#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"
using namespace std;

// Employee class inherits from Person
// Demonstrates different types of relationships in Object-Oriented Programming:
// 1. Composition: Division (1) and JobDescription (1..n) - tightly coupled, destroyed with Employee.
// 2. Aggregation: Spouse (0..1) and Child (0..n) - loosely coupled, exist independently.
class Employee : public Person {
private:
    string companyID;
    string title;
    string startDate;

    // --- Composition Relationships ---
    // Employee owns these objects. If Employee is destroyed, these are too.
    Division           division;       // 1 Division relationship
    vector<JobDescription> jobDescs;   // 1..n JobDescription relationship

    // --- Aggregation Relationships ---
    // Employee holds pointers to these objects, but does not own their lifecycle.
    Spouse* spouse;                    // 0..1 Spouse relationship (can be null)
    vector<Child*> children;           // 0..n Child relationship (can be empty)

public:
    // Constructor
    // Initializes the Person base class and the Employee's specific attributes.
    // Also initializes the division (Composition) and sets spouse to nullptr.
    Employee(string n, string ss, int a,
             string id, string t, string sd,
             string divName)
        : Person(n, ss, a),
          companyID(id),
          title(t),
          startDate(sd),
          division(divName),   // Division is created directly within the Employee
          spouse(nullptr)      // Initially no spouse
    {}

    // Destructor
    ~Employee() {}

    // --- Getter Methods ---
    string getCompanyID() const { return companyID; }
    string getTitle()     const { return title; }
    string getStartDate() const { return startDate; }

    // --- Setter Methods ---
    void setCompanyID(string id) { companyID = id; }
    void setTitle(string t)      { title     = t; }
    void setStartDate(string sd) { startDate = sd; }

    // --- JobDescription (1..n Composition) ---
    // Adds a new job description by creating a JobDescription object and adding it to the list.
    void addJobDescription(string desc) {
        jobDescs.push_back(JobDescription(desc));
    }

    void addJobDescription(const JobDescription& jd) {
        jobDescs.push_back(jd);
    }

    // --- Division (1 Composition) ---
    // Sets or updates the division.
    void setDivision(const Division& d) {
        division = d;
    }

    // --- Spouse (0..1 Aggregation) ---
    // Assigns a pointer to a Spouse object.
    void setSpouse(Spouse* s) { spouse = s; }

    // --- Child (0..n Aggregation) ---
    // Adds a pointer to a Child object to the children list.
    void addChild(Child* c) { children.push_back(c); }

    // --- Utility Method ---
    // Prints all information about the employee, including their relationships.
    void printInfo() const {
        cout << "=== Employee ===" << endl;
        cout << "name      : " << getName() << endl;
        cout << "ID       : " << companyID << endl;
        cout << "title    : " << title << endl;
        cout << "startDate : " << startDate << endl;
        cout << "division : " << division.getDivisionName() << endl;

        // Print 1..n JobDescription relationship
        cout << "Job Descriptions:" << endl;
        for (const auto& jd : jobDescs)
            cout << "  - " << jd.getDescription() << endl;

        // Print 0..1 Spouse relationship if it exists
        if (spouse != nullptr)
            cout << "Spouse: " << spouse->getName() << endl;

        // Print 0..n Child relationship if there are any children
        if (!children.empty()) {
            cout << "Children:" << endl;
            for (const auto& c : children)
                cout << "  - " << c->getName() << endl;
        }
    }
};