#include <iostream>

using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > b) {
        n *= 1.0 - y / 100;
    } else if (n > a) {
        n *= 1.0 - x / 100;
    }
    cout << n << endl;
}