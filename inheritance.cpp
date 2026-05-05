#include<iostream>
using namespace std;
class Car {
    public:
    string name;
    void start() {
        cout << name << " is starting" << endl;
    }
    void stop() {
        cout << name << " is stopping" << endl;
    }
};
class Navigation {
    public:
    virtual void show_direction() = 0;
};
class Camera {
    public:
    virtual void rear_camera() = 0;
};
class Tesla : public Car, public Navigation, public Camera {
    public:
    void show_direction() override {
        cout << "Tesla navigation turned on" << endl;
    }
    void rear_camera() override {
        cout << "Tesla rear camera turned on" << endl;
    }
};
int main() {
    Tesla t;
    t.name = "Tesla Model 3";
    t.start();
    t.show_direction();
    t.rear_camera();
    t.stop();
}