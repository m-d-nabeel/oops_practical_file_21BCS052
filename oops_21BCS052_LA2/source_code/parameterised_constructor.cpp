#include <iostream>

using namespace std;

class Line {
   public:
    // Member function declarations
    void setLength(double len);
    double getLength();

    // Constructor declaration
    Line();                  // This is the default constructor
    Line(const double len);  // This is the parameterised constructor

   private:
    double length;
};

// This is the default constructor implementation
Line::Line() : length(0.0) {
    cout << "Object is being created using default constructor" << endl;
}
// This is the parameterised constructor implementation
Line::Line(const double len) : length(len) {
    cout << "Object is being created using Parameterised (" << len
         << ") constructor" << endl;
}
void Line::setLength(double len) { length = len; }
double Line::getLength() { return length; }

int main() {
    cout << __FILE__ << endl;
    Line line1 = Line();
    cout << "Length of line using default constructor: " << line1.getLength()
         << endl;
    Line line2 = Line(6.0);
    cout << "Length of line using parametrized constructor: "
         << line2.getLength() << endl;
    cout << endl;
    return 0;
}
