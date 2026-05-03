#pragma once
#include <string>
#include <vector>
#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"
using namespace std;

// Employee клас — Person-оос удамших
// Division болон JobDescription-тэй бүрдэл (composition) харьцаатай
// Spouse (0..1), Child (0..n) — нэгдэл (aggregation) харьцаатай
class Employee : public Person {
private:
    string companyID;
    string title;
    string startDate;

    // --- Бүрдэл харьцаа (Composition) ---
    // Employee устахад Division, JobDescription ч устана
    Division           division;       // 1 Division
    vector<JobDescription> jobDescs;   // 1..n JobDescription

    // --- Нэгдэл харьцаа (Aggregation) ---
    // Employee устсан ч Spouse, Child тусдаа оршиж болно
    Spouse* spouse;                    // 0..1 Spouse
    vector<Child*> children;           // 0..n Child

public:
    // Байгуулагч — division заавал шаардлагатай (1 харьцаа)
    Employee(string n, string ss, int a,
             string id, string t, string sd,
             string divName)
        : Person(n, ss, a),
          companyID(id),
          title(t),
          startDate(sd),
          division(divName),   // Division шууд дотроос үүснэ
          spouse(nullptr)      // Эхлээд spouse байхгүй
    {}

    ~Employee() {}

    // --- Getter методууд ---
    string getCompanyID() const { return companyID; }
    string getTitle()     const { return title; }
    string getStartDate() const { return startDate; }

    // --- Setter методууд ---
    void setCompanyID(string id) { companyID = id; }
    void setTitle(string t)      { title     = t; }
    void setStartDate(string sd) { startDate = sd; }

    // --- JobDescription нэмэх (1..n) ---
    void addJobDescription(string desc) {
        jobDescs.push_back(JobDescription(desc));
    }

    // --- Spouse оноох (0..1) ---
    void setSpouse(Spouse* s) { spouse = s; }

    // --- Child нэмэх (0..n) ---
    void addChild(Child* c) { children.push_back(c); }

    // --- Мэдээлэл хэвлэх ---
    void printInfo() const {
        cout << "=== Employee ===" << endl;
        cout << "name      : " << getName() << endl;
        cout << "ID       : " << companyID << endl;
        cout << "title    : " << title << endl;
        cout << "startDate : " << startDate << endl;
        cout << "division : " << division.getDivisionName() << endl;

        cout << "Job Descriptions:" << endl;
        for (const auto& jd : jobDescs)
            cout << "  - " << jd.getDescription() << endl;

        if (spouse != nullptr)
            cout << "Spouse: " << spouse->getName() << endl;

        if (!children.empty()) {
            cout << "Children:" << endl;
            for (const auto& c : children)
                cout << "  - " << c->getName() << endl;
        }
    }
};