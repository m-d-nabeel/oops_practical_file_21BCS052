#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    double pounds, kilograms;
    cout << __FILE__ << endl;

    cout << "Enter the weight in pounds: ";
    cin >> pounds;
    kilograms = pounds * 0.453592;
    cout << pounds << " pounds is " << kilograms << " kilograms." << endl
         << endl;

    cout << "Enter the weight in kilograms: ";
    cin >> kilograms;
    pounds = kilograms * 2.20462;
    cout << kilograms << " kilograms is " << pounds << " pounds." << endl;

    cout << endl;
    return 0;
}
