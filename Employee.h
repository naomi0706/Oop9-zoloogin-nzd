#pragma once
#include <string>
#include <vector>
#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"
using namespace std;

// Employee класс Person-аас өвлөн авна
// Объект хандлагын програмчлалд харилцааны төрөлүүдийг харуулна:
// 1. Бүрэлдэхүүн (Composition): Division (1) болон JobDescription (1..n) - бэхжүүлсэн хамаарал, Employee-тай хамт устна.
// 2. Агрегаци (Aggregation): Spouse (0..1) болон Child (0..n) - сул хамаарал, бие даан оршин байх боломжтой.
class Employee : public Person {
private:
    string companyID;
    string title;
    string startDate;

    // --- Агрегаци хамаарал (хуучин Бүрэлдэхүүн байсан) ---
    // Employee эдгээр объектуудын зааврыг барьдаг бөгөөд амьдралын мөчлөгийг удирдахгүй.
    Division*          division;       // 1 тасгийн харилцаа
    vector<JobDescription*> jobDescs;  // 1..n JobDescription харилцаа

    // --- Агрегаци хамаарал ---
    // Employee эдгээр объектын зааврыг барьдаг, гэхдээ амьдралын мөчлөгийг нь удирддаггүй.
    Spouse* spouse;                    // 0..1 Spouse харилцаа (null байж болно)
    vector<Child*> children;           // 0..n Child харилцаа (хоосон байж болно)

public:
    // Байгуулагч
    // Person суурь классыг болон Employee-ийн тодорхой талбаруудыг эхлүүлнэ.
    // Мөн division-ыг (Composition) эхлүүлж, spouse-г nullptr болгоно.
    Employee(string n, string ss, int a,
             string id, string t, string sd)
        : Person(n, ss, a),
          companyID(id),
          title(t),
          startDate(sd),
          division(nullptr),   // Агрегаци тул эхэндээ хоосон байж болно
          spouse(nullptr)      // Эхэндээ spouse байхгүй
    {}

    // Устгагч
    ~Employee() {}

    // --- Үзэгч функцууд ---
    string getCompanyID() const { return companyID; }
    string getTitle()     const { return title; }
    string getStartDate() const { return startDate; }

    // --- Тохируулагч функцууд ---
    void setCompanyID(string id) { companyID = id; }
    void setTitle(string t)      { title     = t; }
    void setStartDate(string sd) { startDate = sd; }

    // --- JobDescription (1..n Агрегаци) ---
    void addJobDescription(JobDescription* jd) {
        jobDescs.push_back(jd);
    }

    // --- Division (1 Агрегаци) ---
    // Division-ыг тохируулж эсвэл шинэчилнэ.
    void setDivision(Division* d) {
        division = d;
    }

    // --- Spouse (0..1 Агрегаци) ---
    // Spouse объектын зааврыг онооно.
    void setSpouse(Spouse* s) { spouse = s; }

    // --- Child (0..n Агрегаци) ---
    // Child объектын зааврыг children жагсаалтанд нэмнэ.
    void addChild(Child* c) { children.push_back(c); }

    // --- Туслах функц ---
    // Бүх ажилтан болон тэдний харилцааны мэдээллийг хэвлэнэ.
    void printInfo() const {
        cout << "=== Employee ===" << endl;
        cout << "name      : " << getName() << endl;
        cout << "ID       : " << companyID << endl;
        cout << "title    : " << title << endl;
        cout << "startDate : " << startDate << endl;
        if (division)
            cout << "division : " << division->getDivisionName() << endl;
        else
            cout << "division : None" << endl;

        // 1..n JobDescription харилцааг хэвлэнэ
        cout << "Job Descriptions:" << endl;
        for (const auto& jd : jobDescs)
            if (jd) cout << "  - " << jd->getDescription() << endl;

        // 0..1 Spouse харилцаа байгаа бол хэвлэнэ
        if (spouse != nullptr)
            cout << "Spouse: " << spouse->getName() << endl;

        // Хүүхэд байвал 0..n Child харилцааг хэвлэнэ
        if (!children.empty()) {
            cout << "Children:" << endl;
            for (const auto& c : children)
                cout << "  - " << c->getName() << endl;
        }
    }
};