#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> month_names = {"January"s, "February"s, "March"s, "April"s, 
                                  "May"s, "June"s, "July"s, "August"s, "September"s, 
                                  "October"s, "November"s, "December"s};
    int month_index;
    cin >> month_index;

    if (month_index <= 0 || month_index > month_lengths.size()) {
        cout << "Incorrect month"s << endl;
    } else {
        cout << "There are "s << month_lengths[month_index - 1] << " days in "s
             << month_names[month_index - 1] << endl;
    }
}