#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    cout << c << endl
         << b << endl
         << a << endl;
}