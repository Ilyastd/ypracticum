#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}


int main() {
    string query;
    getline(cin, query);
    
    for (string word : SplitIntoWords(query)) {
        cout << '[' << word << ']' << endl;
    }

    return 0;
}