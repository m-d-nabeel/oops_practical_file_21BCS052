#include <iostream>
using namespace std;


class Room{

    public:

        float takeInput(string type){
            float value;
            string t;
            for(int i=0; i<type.length(); i++){
                if(type[i] != ' '){
                    t.push_back(type[i]);
                }
            }

            cout<<"Enter "<<t<<" : "; cin>>value;
            return value;
        }


        void area(int length, int width){
            float area = length * width;
            cout<<"Area of Room = "<< area << endl;
        }

        void volume(int length, int width, int height){
            float volume = length * width * height;
            cout<<"Volume of Room = "<< volume << endl;
        }

        void area(){
            float a;
            a = takeInput("Length") * takeInput("Width");
            cout<<a<<endl;

            // int l,b;
            // cout<<"Enter Length : "; cin>>l;
            // cout<<"Enter Width : ";  cin>>b;
            // float area = l * b;

            cout<<"Area of Room = "<< a << endl;
        }

        void volume(){
            float vol;

            vol = takeInput("Length") * takeInput("Width") * takeInput("Height") ;
            cout<<vol<<endl;

            int l,b,h;
            cout<<"Enter Length : "; cin>>l;
            cout<<"Enter Width : ";  cin>>b;
            cout<<"Enter Height : "; cin>>h;
            float volume = l * b * h;

            cout<<"Volume of Room = "<< vol << endl;
        }

        void area(string unit);
        void volume(string unit);
};

void Room :: area(string unit){
    int l,b;
    float area = takeInput("Length") * takeInput("Width");
    cout<<"Area of Room = "<<area<<unit<<" ^2"<<endl;
}

void Room :: volume(string unit){

    int l,b,h;
    cout<<"Enter Length : "; cin>>l;
    cout<<"Enter Width : ";  cin>>b;
    cout<<"Enter Height : "; cin>>h;

    float volume = l * b * h;
    cout<<"Volume of Room = "<<volume<<unit<<" ^3"<<endl;
}




int main(){
    

    Room r;

    r.area(4,6);

    r.volume(3,4,3);

    r.volume("cm");

    r.volume();


    return 0;
}