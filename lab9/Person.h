#pragma once
#include <string>
using namespace std;

// Анхны Person класс
// Энэ класс Employee, Child, Spouse-ийн эцэг класс болно.
// Систем дэх бүх хүний нийтлэг талбаруудыг агуулна.
class Person {
private:
    string name;
    string ssNum;
    int    age;

public:
    // Байгуулагч
    // Хүн тус бүрийн үндсэн мэдээллийг эхлүүлнэ.
    Person(string n, string ss, int a)
        : name(n), ssNum(ss), age(a) {}

    // Виртуал устгагч
    // Энэ класс суурь класс учир шаардлагатай.
    // Удирдагдсан классуудын устгагдах үед зөв дуудна.
    virtual ~Person() {}

    // Үзэгч функцууд
    string getName()   const { return name; }
    string getSSNum()  const { return ssNum; }
    int    getAge()    const { return age; }

    // Тохируулагч функцууд
    void setName(string n)   { name  = n; }
    void setSSNum(string ss) { ssNum = ss; }
    void setAge(int a)       { age   = a; }
};