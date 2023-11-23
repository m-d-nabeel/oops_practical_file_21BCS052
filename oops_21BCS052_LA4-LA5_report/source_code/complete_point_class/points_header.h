#include <bits/stdc++.h>
#define TOLERANCE 0.5
using namespace std;

enum Index { X_VALUE, Y_VALUE };

class Point {
    static int count;
    double _x;
    double _y;

   public:
    void setCoords(double, double);
    void printCoords();
    double distFrom(Point &) const;
    Point midPoint(Point &);
    static int objInstances();  // static Member function
    double l2Norm() const;
    pair<double, double> getCords() const;
    // static int getCount();

    // CONSTRUCTORS & DESTRUCTORS
    Point();                // This is the DEFAULT constructor
    Point(double, double);  // This is the PARAMETERIZED constructor
    Point(const Point &);   // This is the COPY constructor
    ~Point();               // This is the destructor

    // OVERLOADINGS
    Point operator+(const Point &) const;
    // postfix increment operator
    Point operator++(int);
    // prefix increment operator
    Point operator++();
    Point operator-() const;
    // Ans 1 -> Operator overload declaration,
    // Ans 2 -> Return type Point' and Argument Type 'Point'.
    // friend Point operator-(const Point &);
    bool operator<(const Point &) const;
    bool operator>(const Point &) const;
    bool operator==(const Point &) const;
    Point operator+=(const Point &);
    Point operator=(const Point &);
    double &operator[](const Index index);
    friend istream &operator>>(istream &input, Point &p);
    friend ostream &operator<<(ostream &output, const Point &p);
    void *operator new(size_t);
    void operator delete(void *);
};

Point Point::operator+=(const Point &p) {
    _x += p._x;
    _y += p._y;
    return (*this);
}

void *Point::operator new(size_t size) {
    cout << "New Operator called.\n";
    void *p = malloc(size);
    return p;
}
void Point::operator delete(void *p) {
    cout << "Delete Operator called.\n";
    free(p);
}

Point Point ::operator=(const Point &p) {
    _x = p._x;
    _y = p._y;
    return *this;
}
Point Point ::operator++(int) {
    Point temp;
    temp = *this;
    ++_x;
    ++_y;
    return temp;
}
Point Point ::operator++() {
    ++_x;
    ++_y;
    return (*this);
}
Point Point ::operator+(const Point &p) const {
    Point p3;
    p3._x = _x + p._x;
    p3._y = _y + p._y;
    return p3;
}
Point Point ::operator-() const {
    Point p3;
    p3._x = -1 * _x;
    p3._y = -1 * _y;
    return p3;
}

// Problem 2
bool Point ::operator<(const Point &p) const {
    double d1 = _x * _x + _y * _y;
    double d2 = p._x * p._x + p._y * p._y;
    return d1 < d2;
}

bool Point ::operator>(const Point &p) const {
    double d1 = _x * _x + _y * _y;
    double d2 = p._x * p._x + p._y * p._y;
    return d1 > d2;
}

bool Point ::operator==(const Point &p) const {
    double d1 = _x * _x + _y * _y;
    double d2 = p._x * p._x + p._y * p._y;
    return fabs(sqrt(d1) - sqrt(d2)) <= TOLERANCE;
}
istream &operator>>(istream &input, Point &p) {
    input >> p._x;
    input >> p._y;
    return input;
}
ostream &operator<<(ostream &output, const Point &p) {
    output << "x : " << p._x << ", y: " << p._y;
    return output;
}
double Point ::l2Norm() const { return sqrt(_x * _x + _y * _y); }
double &Point::operator[](const Index index) {
    return index == X_VALUE ? _x : _y;
}
Point ::Point() {
    count++;
    _x = _y = 0;
    cout << "Point Default Constructor is called" << endl;
}
// destructor
Point ::~Point() {
    count--;
    cout << "Point Destructor is called for " << _x << "," << _y << endl;
}

// Parameterized constructor
Point ::Point(double x, double y) {
    count++;
    _x = x;
    _y = y;

    cout << "Point Parameterized constructor is called" << endl;
}

Point ::Point(const Point &p) {
    _x = p._x;
    _y = p._y;
    count++;
    cout << "Point Copy constructor is called" << endl;
}

// Member functions
void Point ::setCoords(double x, double y) {
    _x = x;
    _y = y;
}

void Point ::printCoords() { cout << _x << "," << _y << endl; }

// 5. Member function accessing private member of all objects of this class.

double Point ::distFrom(Point &p) const {
    // const Member because it can't change the data Member of this object
    double d;
    d = sqrt(pow((_x - p._x), 2) + pow((_y - p._y), 2));
    return d;
}

Point Point ::midPoint(Point &p) {
    Point nP;

    nP._x = (_x + p._x) / 2;
    nP._y = (_y + p._y) / 2;

    return nP;
}
// definition of static variable. Memory is allocated here;
int Point ::count = 0;

int Point ::objInstances() { return count; }

// Ans 4
pair<double, double> Point::getCords() const { return {_x, _y}; }