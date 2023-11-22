#include <iostream>

using namespace std;

class Line {
   public:
    // Member function declarations
    void setLength(double len);
    double getLength(void);

    // Constructor declaration
    Line();  // This is the constructor

   private:
    double length;
};

// This is the constructor implementation
Line::Line(void) {
    cout << "Object is being created using Default constructor" << endl;
}
void Line::setLength(double len) { length = len; }
double Line::getLength(void) { return length; }

int main() {
    cout << __FILE__ << endl;
    Line line;
    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;
    cout << endl;
    return 0;
}
