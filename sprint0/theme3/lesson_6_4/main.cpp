#include <iostream>
#include <string>

using namespace std;

int main() {
    string query;
    getline(cin, query);
    string word;
    
    for (int i = 0; i < query.size(); ++i) {
        if (query[i] == ' ') {
            cout << '[' << word << ']' << endl;
            word = ""s;
        } else {
            word += query[i];
        }
    }
    cout << '[' << word << ']' << endl;
}