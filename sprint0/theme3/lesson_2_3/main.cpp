#include <iostream>
#include <string>

using namespace std;

int main() {
    int document_count;
    cin >> document_count;
    if (document_count == 0) {
        cout << "No documents found"s;
    } else if (document_count == 1) {
        cout << "One document found"s;
    } else {
        string message = to_string(document_count) + " documents found"s;
        cout << message;
    }
    cout << endl;
}