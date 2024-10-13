#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    cout << sum * to_string(sum).size() << endl;
}