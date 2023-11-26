#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Sentence {
   private:
    string originalSentence;

   public:
    void takeInput();
    void removeDuplicates();
    void reverseWords();
    string reverseWord(const string &word);
    void print() const { cout << "Sentence = " << originalSentence << endl; }
};

void Sentence::takeInput() {
    cout << "Enter Your Sentence: ";
    getline(cin, originalSentence);
}

void Sentence::removeDuplicates() {
    unordered_set<string> uniqueWords;
    vector<string> words;
    string currentWord;

    for (char character : originalSentence) {
        if (character != ' ') {
            currentWord.push_back(character);
        } else {
            if (uniqueWords.insert(currentWord).second) {
                words.push_back(currentWord);
            }
            currentWord.clear();
        }
    }
    if (!currentWord.empty() && uniqueWords.insert(currentWord).second) {
        words.push_back(currentWord);
    }

    originalSentence.clear();
    for (const auto &word : words) {
        originalSentence += word + ' ';
    }

    print();
}

string Sentence::reverseWord(const string &word) {
    string reversedWord = word;
    int left = 0, right = reversedWord.length() - 1;
    while (left < right) {
        swap(reversedWord[left++], reversedWord[right--]);
    }

    return reversedWord;
}

void Sentence::reverseWords() {
    string currentWord;
    vector<string> reversedWords;

    for (char character : originalSentence) {
        if (character != ' ') {
            currentWord.push_back(character);
        } else {
            reversedWords.push_back(reverseWord(currentWord));
            currentWord.clear();
        }
    }
    if (!currentWord.empty()) {
        reversedWords.push_back(reverseWord(currentWord));
    }

    originalSentence.clear();
    for (const auto &reversedWord : reversedWords) {
        originalSentence += reversedWord + ' ';
    }
}

int main() {
    Sentence sentence;

    sentence.takeInput();
    sentence.print();
    sentence.removeDuplicates();
    sentence.reverseWords();
    sentence.print();

    return 0;
}
