#include <iostream>

using namespace std;

int main() {
    int n1, n2, sum;
    cin >> n1 >> n2 >> sum;
    
    int expected_sum = n1 + n2;
    if (sum != expected_sum) {
        cout << "Error. The sum of "s << n1 << " and "s << n2 << " is "s  << expected_sum << endl;
    }
}