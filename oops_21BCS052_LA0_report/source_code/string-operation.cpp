# include <iostream>
# include <string.h>
# include <vector>
# include <map>

using namespace std;

class Sentence{
    
    private:
        string sentence;

    public:
        void takeInput();
        void removeDups();
        void reverseWords();
        string reverseWord(string &);
        void print(){
            cout<<"Sentence = "<<sentence<<endl;
        };
};


void Sentence :: takeInput(){
    cout<<"Enter Your Sentence : ";
    getline(cin, sentence);
}

void Sentence :: removeDups(){
    
    map <string, int> mans;
    
    vector<string> ans;
    string s;
    
    for(auto i: sentence){
        if(i!=' '){
            s.push_back(i);
        }else{
            if(!mans[s]){
                mans[s] = 1;
                ans.push_back(s);
            }
            s = "";
        }
    }
    if(s.length() and mans[s]!=1){
        ans.push_back(s);
    }
    
    sentence = "";
    for(auto i : ans){
        // cout<<i<<" ";
        sentence += i;
        sentence.push_back(' ');
    }
    
    print();

}

string Sentence :: reverseWord(string &s){
    
    int l = 0, r = s.length()-1;
    while(l<r){
        swap(s[l], s[r]);
        l++;
        r--;
    }
    
    return s;
    
}

void Sentence :: reverseWords(){
    
    string s;
    vector <string> ans;
    
    for(auto i : sentence){
        
        if(i!=' '){
            s.push_back(i);
        } else{
            s = reverseWord(s);
            ans.push_back(s);
            s = "";
        }
        
    }
    if(s.length()){
        reverseWord(s);
        ans.push_back(s);
    }
    sentence = "";
    for(auto i: ans){
        sentence += i + " ";
    }
    
}


int main(){
    
    Sentence s;
    
    s.takeInput();
    s.removeDups();
    s.reverseWords();
    s.print();
    
    
    return 0;
}