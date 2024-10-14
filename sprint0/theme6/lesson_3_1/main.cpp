#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> ToSet(vector<string> vec) {
    set<string> result;
    for(string s: vec) {
        result.insert(s);
    }
    return result;
}

int CalculateSimilarity(vector<string> first, vector<string> second) {
    // верните размер пересечения множеств слов first и second
    set<string> first_set = ToSet(first);
    set<string> second_set = ToSet(second);
    set<string> intersection;
    int counter = 0;
    for(string s: first_set) {
        if(second_set.count(s)) {
            ++counter;
        }
    }
    return counter;
}

// SplitIntoWords разбивает строку text на слова и возвращает их в виде вектора
// Слово - последовательность непробельных символов,
// разделённых одним или более пробелов.
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
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;
}