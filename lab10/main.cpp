#include<bits/stdc++.h>
#include<math.h>
using namespace std;

// ============================================================
//  POINT STRUCT
// ============================================================
struct Point {
    float x;
    float y;
} typedef Point;

// ============================================================
//  LAB 07 - SHAPE КЛАССУУД
// ============================================================

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
        virtual float talbai()    = 0;
        virtual float perimetr()  = 0;
        string getName() { return name; }
        virtual ~Shape2D() {}
};

// ---------- Circle ----------
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

// ---------- Square ----------
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

// ---------- Triangle ----------
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

// ============================================================
//  LAB 10 - TEMPLATE LINKEDLIST
// ============================================================

template <typename T>
class LinkedList {
    private:
        // Дотоод Node бүтэц
        struct Node {
            T data;
            Node* next;
            Node(T val) : data(val), next(nullptr) {}
        };

        Node* head;
        int   size;

    public:
        // Байгуулагч
        LinkedList() : head(nullptr), size(0) {}

        // Устгагч - санах ойг цэвэрлэнэ
        ~LinkedList() {
            Node* cur = head;
            while (cur) {
                Node* tmp = cur->next;
                delete cur;
                cur = tmp;
            }
        }

        // ---- void add(T t) — сүүлд нэмнэ ----
        void add(T t) {
            Node* newNode = new Node(t);
            if (!head) {
                head = newNode;
            } else {
                Node* cur = head;
                while (cur->next) cur = cur->next;
                cur->next = newNode;
            }
            size++;
        }

        // ---- void insert(T t, int index) — index дүгээрт оруулна ----
        void insert(T t, int index) {
            if (index < 0 || index > size) {
                cout << "insert: index хязгаараас гарлаа!\n";
                return;
            }
            Node* newNode = new Node(t);
            if (index == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* cur = head;
                for (int i = 0; i < index - 1; i++) cur = cur->next;
                newNode->next = cur->next;
                cur->next     = newNode;
            }
            size++;
        }

        // ---- T get(int index) — i-р элементийн утгыг буцаана ----
        T get(int index) {
            if (index < 0 || index >= size) {
                cout << "get: index хязгаараас гарлаа!\n";
                // Pointer байвал nullptr буцаана
                return nullptr;
            }
            Node* cur = head;
            for (int i = 0; i < index; i++) cur = cur->next;
            return cur->data;
        }

        // ---- void remove(int index) — i-р элементийг устгана ----
        // (C++ дээр "delete" нь түлхүүр үг тул "remove" нэр ашиглав)
        void remove(int index) {
            if (index < 0 || index >= size) {
                cout << "remove: index хязгаараас гарлаа!\n";
                return;
            }
            Node* toDelete;
            if (index == 0) {
                toDelete = head;
                head     = head->next;
            } else {
                Node* cur = head;
                for (int i = 0; i < index - 1; i++) cur = cur->next;
                toDelete  = cur->next;
                cur->next = toDelete->next;
            }
            delete toDelete;
            size--;
        }

        // ---- int length() — жагсаалтын уртыг буцаана ----
        int length() { return size; }
};

// ============================================================
//  BUBBLE SORT (талбайгаар)
// ============================================================
void bubbleSort(LinkedList<Shape2D*>& list) {
    int n = list.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list.get(j)->talbai() > list.get(j + 1)->talbai()) {
                Shape2D* tmp = list.get(j);
                // Байрлалаа солихын тулд устгаж, дахин оруулна
                list.remove(j);
                list.insert(tmp, j + 1);
            }
        }
    }
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    srand(42); // Санамсаргүй тоо үүсгэх үр

    LinkedList<Shape2D*> shapes;

    // Санамсаргүй тал/радиустай 20-30 объект үүсгэнэ (энд 24 ш)
    int totalShapes = 24;

    for (int i = 0; i < totalShapes; i++) {
        // Санамсаргүй тал: 1.0 - 10.0
        float side   = 1.0f + (rand() % 91) / 10.0f;
        Point origin = {(float)(rand() % 20), (float)(rand() % 20)};
        int   type   = rand() % 3; // 0=Circle, 1=Square, 2=Triangle

        string name;
        Shape2D* shape;

        if (type == 0) {
            name  = "Circle_"   + to_string(i + 1);
            shape = new Circle(origin, side, name);
        } else if (type == 1) {
            name  = "Square_"   + to_string(i + 1);
            shape = new Square(origin, side, name);
        } else {
            name  = "Triangle_" + to_string(i + 1);
            shape = new Triangle(origin, side, name);
        }

        shapes.add(shape);
    }

    cout << "Нийт объект: " << shapes.length() << "\n\n";

    // Талбайгаар эрэмбэлнэ (bubble sort)
    bubbleSort(shapes);

    // Хэвлэнэ
    cout << "======================================\n";
    cout << "   Talbaigaar erembelsen dursuud\n";
    cout << "======================================\n\n";

    for (int i = 0; i < shapes.length(); i++) {
        Shape2D* s = shapes.get(i);
        cout << i + 1 << ". " << s->getName() << "\n";
        cout << "   Talbai   : " << fixed << setprecision(2) << s->talbai()   << "\n";
        cout << "   Perimetr : " << fixed << setprecision(2) << s->perimetr() << "\n";
        cout << "--------------------------------------\n";
    }

    // Санах ой цэвэрлэнэ
    for (int i = 0; i < shapes.length(); i++) {
        delete shapes.get(i);
    }

    return 0;
}