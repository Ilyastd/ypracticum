#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string query;
    getline(cin, query);
    vector<string> words;
    string word;
    
    for (char c : query) {
        if (c == ' ') {
            words.push_back(word);
            word = ""s;
        } else {
            word += c;
        }
    }
    
    words.push_back(word);
    for (string word : words) {
        cout << '[' << word << ']' << endl;
    }
}