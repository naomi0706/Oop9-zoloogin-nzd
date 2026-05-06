#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    // 1. Өөр өөр хэлтсүүдийг төлөөлөх Division объектуудыг үүсгэнэ
    Division itDivision("IT");
    Division hrDivision("HR");
    Division financeDivision("Finance");

    // 2. Янз бүрийн үүрэгтэй JobDescription объектуудыг үүсгэнэ
    JobDescription jd1("System Development");
    JobDescription jd2("Code Review");
    JobDescription jd3("Recruitment");
    JobDescription jd4("Payroll Management");
    JobDescription jd5("Budget Analysis");

    // 3. Employee объектуудыг үүсгэн, тэдний Division (1 харилцаа) болон JobDescriptions (1..n харилцаа)-г тохируулна
    Employee emp1("Bold", "123-456", 35,
                  "EMP001", "Engineer", "2020-01-15",
                  "IT");
    emp1.setDivision(itDivision); // Division-ыг онооно
    emp1.addJobDescription(jd1);  // Эхний ажлын тодорхойлолтыг нэмнэ
    emp1.addJobDescription(jd2);  // Хоёр дахь ажлын тодорхойлолтыг нэмнэ

    Employee emp2("Munkh", "234-567", 29,
                  "EMP002", "HR Specialist", "2019-07-01",
                  "HR");
    emp2.setDivision(hrDivision);
    emp2.addJobDescription(jd3);

    Employee emp3("Tsetseg", "345-678", 31,
                  "EMP003", "Finance Analyst", "2021-03-10",
                  "Finance");
    emp3.setDivision(financeDivision);
    emp3.addJobDescription(jd4);
    emp3.addJobDescription(jd5);

    // 4. emp1-д Spouse (0..1 харилцаа) болон Child (0..n харилцаа)-г тохируулна
    Spouse sp("Nomin", "789-012", 32, "2018-06-20");
    emp1.setSpouse(&sp); // emp1-д spouse онооно

    Child c1("temuulen", "111-222", 5, "lego");
    Child c2("chinguun", "333-444", 3, "doll");
    emp1.addChild(&c1); // emp1-д эхний хүүхдийг нэмнэ
    emp1.addChild(&c2); // emp1-д хоёр дахь хүүхдийг нэмнэ

    // Бүх ажилтануудын эхний мэдээллийг хэвлэнэ
    emp1.printInfo();
    cout << endl;
    emp2.printInfo();
    cout << endl;
    emp3.printInfo();

    // Даалгавар 1: Employee ангийн объектуудад spouse болон child-ыг тохируулна.
    // emp2-ийн харилцааг тохируулна
    Spouse sp2("Saraa", "999-888", 28, "2021-02-14");
    emp2.setSpouse(&sp2);
    Child c3("Bold", "777-666", 3, "Ball");
    emp2.addChild(&c3);

    // emp3-ийн харилцааг тохируулна
    Spouse sp3("Tulga", "555-444", 33, "2019-10-10");
    Child c4("Maral", "333-222", 5, "Book");
    Child c5("Anar", "111-000", 1, "Toy");
    emp3.setSpouse(&sp3);
    emp3.addChild(&c4);
    emp3.addChild(&c5);

    //  Employee ангийн объектын бүх мэдээллийг хэвлэнэ
    // Бүх ажилтны бүрэн тохируулагдсан мэдээллийг хэвлэнэ
    cout << "\n--- Updated Employee Information ---\n" << endl;
    emp1.printInfo();
    cout << endl;
    emp2.printInfo();
    cout << endl;
    emp3.printInfo();

    return 0;
}
