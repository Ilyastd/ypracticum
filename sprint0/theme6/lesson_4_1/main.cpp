#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> MakeSet(vector<string> query_words) {
    set<string> s(query_words.begin(), query_words.end());
    return s;
} 

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (const char c : text) {
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
    /* Считайте строку со стоп-словами */
    string stop_words_raw;
    getline(cin, stop_words_raw);
    vector<string> v = SplitIntoWords(stop_words_raw);
    set<string> stop_words(v.begin(), v.end());
    
    // Считываем строку-запрос
    string query;
    getline(cin, query);
    
    // Выведите только те слова, которых нет среди стоп-слов
    for (string word : SplitIntoWords(query)) {
        if(!stop_words.count(word)) {
            cout << '[' << word << ']' << endl;
        }
    }
}