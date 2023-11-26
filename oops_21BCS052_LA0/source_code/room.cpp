#include <iostream>
using namespace std;

class Room {
   private:
    float takeInput(string type);

   public:
    void area(int length, int width);
    void volume(int length, int width, int height);
    void area();
    void volume();
    void area(string unit);
    void volume(string unit);
};

float Room::takeInput(string type) {
    float value;
    cout << "Enter " << type << " : ";
    cin >> value;
    return value;
}

void Room::area(int length, int width) {
    float roomArea = length * width;
    cout << "Area of Room = " << roomArea << endl;
}

void Room::volume(int length, int width, int height) {
    float roomVolume = length * width * height;
    cout << "Volume of Room = " << roomVolume << endl;
}

void Room::area() {
    float roomArea = takeInput("Length") * takeInput("Width");
    cout << "Area of Room = " << roomArea << endl;
}

void Room::volume() {
    float roomVolume =
        takeInput("Length") * takeInput("Width") * takeInput("Height");
    cout << "Volume of Room = " << roomVolume << endl;
}

void Room::area(string unit) {
    float roomArea = takeInput("Length") * takeInput("Width");
    cout << "Area of Room = " << roomArea << " " << unit << "^2" << endl;
}

void Room::volume(string unit) {
    int length, width, height;
    length = takeInput("Length");
    width = takeInput("Width");
    height = takeInput("Height");

    float roomVolume = length * width * height;
    cout << "Volume of Room = " << roomVolume << " " << unit << "^3" << endl;
}

int main() {
    cout << __FILE__ << endl;
    Room room;

    room.area(4, 6);
    room.volume(3, 4, 3);
    room.volume("cm");
    room.volume();
    cout << "-------------------------------------------\n";

    return 0;
}
