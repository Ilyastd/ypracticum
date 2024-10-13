#include <iostream>
using namespace std;

int main() {
    int result;
    for (int i = 0; i < 10; ++i) {
        cin >> result;
        if (result == 0) {
            cout << "No cake :(" << endl;
            break;
        }
        cout << "Om-nom-nom :P" << endl;
    }
}