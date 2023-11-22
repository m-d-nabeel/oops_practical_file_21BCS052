#include <iostream>

using namespace std;

class Line {
   public:
    void setLength(double len);
    double getLength(void);
    // Constructor declaration
    Line();  // This is the constructor

    // Destructor declaration
    ~Line();  // This is the destructor

   private:
    double length;
};

Line::Line(void) { cout << "Object is being created" << endl; }

Line::~Line(void) { cout << "Object is being deleted" << endl; }

void Line::setLength(double len) { length = len; }

double Line::getLength(void) { return length; }

// Main function for the program

int main() {
    Line line;
    cout << __FILE__ << endl;
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;
    cout << endl;

    return 0;
}

// In this code:
// The constructor is responsible for initializing the object and printing a
// message when the object is being created. The destructor is responsible for
// any cleanup or finalization tasks and prints a message when the object is
// being deleted. When you run this program, you'll see messages indicating when
// the object is being created and when it is being deleted. The utility of
// destructors becomes more apparent in scenarios where dynamic memory is
// allocated or other resources need to be managed, and cleanup is required when
// an object is no longer needed.