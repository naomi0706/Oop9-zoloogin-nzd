#pragma once
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
struct Point {
    float x;
    float y;
} typedef Point;
//  LAB 07 - SHAPE КЛАССУУД
class Shape {
    protected:
        Point points[100];
    public:
        Shape() {}
        virtual ~Shape() {}
};
class Shape2D : public Shape {
    protected:
        string name;
    public:
        Shape2D(string n) : Shape() {
            name = n;
        }
        virtual float talbai()   = 0;
        virtual float perimetr() = 0;
        string getName() { return name; }
        virtual ~Shape2D() {}
};

//  Circle 
class Circle : public Shape2D {
    protected:
        Point p1;
        float radius;
    public:
        Circle(Point p1, float radius, string name) : Shape2D(name) {
            this->p1     = p1;
            this->radius = radius;
        }
        float talbai()   override { return 3.14f * radius * radius; }
        float perimetr() override { return 2 * 3.14f * radius; }
        ~Circle() {}
};

// Square 
class Square : public Shape2D {
    protected:
        Point p1, p2, p3, p4;
        float tal;
    public:
        Square(Point topLeft, float length, string n) : Shape2D(n) {
            p1  = topLeft;
            p2  = {topLeft.x + length, topLeft.y};
            p3  = {topLeft.x + length, topLeft.y - length};
            p4  = {topLeft.x,          topLeft.y - length};
            tal = length;
        }
        float talbai()   override { return tal * tal; }
        float perimetr() override { return 4 * tal; }
        ~Square() {}
};

//  Triangle 
class Triangle : public Shape2D {
    protected:
        Point p1, p2, p3;
        float tal1, tal2, tal3;
    public:
        Triangle(Point top, float a, string n) : Shape2D(n) {
            p1 = top;
            float height = sqrt(3.0f) / 2.0f * a;
            p2 = {top.x - a / 2.0f, top.y - height};
            p3 = {top.x + a / 2.0f, top.y - height};
            tal1 = tal2 = tal3 = a;
        }
        float talbai()   override { return (sqrt(3.0f) / 4.0f) * tal1 * tal1; }
        float perimetr() override { return tal1 + tal2 + tal3; }
        ~Triangle() {}
};
//  FACTORY — санамсаргүй Shape2D* объект үүсгэнэ

vector<Shape2D*> generateRandomShapes(int count);