#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_index;
    
    cin >> month_index;
    cout << month_lengths[month_index] << endl;
}