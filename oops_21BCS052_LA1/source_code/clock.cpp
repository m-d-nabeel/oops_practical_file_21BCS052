#include <iomanip>
#include <iostream>
using std::cout, std::endl, std::setfill, std::setw, std::string;

class Clock {
   private:
    int hour;
    int minute;
    int second;
    string meridian;

   public:
    void setClock(int h, int m, int s, string mer) {
        hour = h;
        minute = m;
        second = s;
        meridian = mer;
    }

    void displayStandard() {
        cout << "Time (Standard): ";
        cout << setw(2) << setfill('0') << hour << ":";
        cout << setw(2) << setfill('0') << minute << ":";
        cout << setw(2) << setfill('0') << second << " " << meridian << endl;
    }

    void displayMilitary() {
        int military_hour = hour;
        if (meridian == "PM") {
            military_hour += 12;
        }
        if (hour == 12 && meridian == "AM") {
            military_hour = 0;
        }
        cout << "Time (Military): ";
        cout << setw(2) << setfill('0') << military_hour << ":";
        cout << setw(2) << setfill('0') << minute << ":";
        cout << setw(2) << setfill('0') << second << endl;
    }
};

// TESTING
int main() {
    cout << __FILE__ << endl;
    Clock myClock1, myClock2;
    myClock1.setClock(3, 30, 45, "PM");
    myClock1.displayStandard();
    myClock1.displayMilitary();
    myClock2.setClock(12, 30, 45, "AM");
    myClock2.displayStandard();
    myClock2.displayMilitary();
    cout << endl;
    return 0;
}

// OUTPUT
// Time (Standard): 03:30:45 PM
// Time (Military): 15:30:45
// Time (Standard): 12:30:45 AM
// Time (Military): 00:30:45