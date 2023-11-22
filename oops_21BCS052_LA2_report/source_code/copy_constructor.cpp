#include <iostream>

using namespace std;

class Line {
   public:
    // Member function declarations
    void setLength(double len);
    double getLength(void);

    // Constructor declaration
    Line();  // This is the default constructor
    Line(Line &line);

   private:
    double length;
};
Line::Line(void) {
    cout << "Object is being created using Default constructor" << endl;
}
Line::Line(Line &line) {
    cout << "Object is being created using Copy constructor" << endl;
    length = line.length;
}
void Line::setLength(double len) { length = len; }
double Line::getLength(void) { return length; }

int main() {
    cout << __FILE__ << endl;
    Line line;
    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;
    Line cLine = Line(line);  // This also calls copy constructor
    cout << "Length of copied line: " << cLine.getLength() << endl;
    cout << endl;
    return 0;
}
