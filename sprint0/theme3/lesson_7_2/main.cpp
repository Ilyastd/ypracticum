#include <iostream>
using namespace std;

int main() {
    int bill;
    int sum = 0;
    
    do {
        cin >> bill;
        if (bill > 0) {
            cout << "Income: " << bill << endl;
            sum += bill;
        }
    } while (bill != 0);
    cout << "Total income: " << sum << endl;
}