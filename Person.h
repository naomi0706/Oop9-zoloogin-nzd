#pragma once
#include <string>
using namespace std;

// Үндсэн хүний клас — бусад классуудын эцэг клас
class Person {
private:
    string name;
    string ssNum;
    int    age;

public:
    // Байгуулагч
    Person(string n, string ss, int a)
        : name(n), ssNum(ss), age(a) {}

    // Виртуал устгагч — удамшил ашиглаж байгаа тул заавал хэрэгтэй
    virtual ~Person() {}

    // Getter методууд
    string getName()   const { return name; }
    string getSSNum()  const { return ssNum; }
    int    getAge()    const { return age; }

    // Setter методууд
    void setName(string n)   { name  = n; }
    void setSSNum(string ss) { ssNum = ss; }
    void setAge(int a)       { age   = a; }
};