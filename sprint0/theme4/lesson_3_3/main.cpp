#include <iostream>
#include <string>

using namespace std;

int main() {
    double first, second;
    cin >> first >> second;
    if (first == second) {
        cout << "The orange is divided into two equal parts"s << endl;
    } else if (first > second) {
        cout << "Cut off "s << first - second << " from the first part"s << endl;
    } else {
        cout << "Cut off "s << second - first << " from the second part"s << endl;
    }
}