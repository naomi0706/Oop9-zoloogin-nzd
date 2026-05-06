#include<iostream>
using namespace std;
class Mammal {
    public:
    string name;
    void breathing() {
        cout << name << " amisgalj baina" << endl;
    }
    void sleeping() {
        cout << name << " untaj baina" << endl;
    }
};
class Think {
    public:
    virtual void thinking() = 0;
};
class Walk {
    public:
    virtual void walking() = 0;
};
class Human : public Mammal, public Think, public Walk {
    public:
    void thinking() override {
        cout << "Hun bodoj baina" << endl;
    }
    void walking() override {
        cout << "Hun alhaj baina" << endl;
    }
};
int main() {
    Human h;
    h.name = "Bold";
    h.breathing();
    h.thinking();
    h.walking();
    h.sleeping();
}