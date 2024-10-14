#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> num_names = { "zero"s, "one"s, "two"s, "three"s, "four"s, "five"s, 
                                 "six"s, "seven"s, "eight"s, "nine"s, "ten"s, "eleven"s, 
                                 "twelve"s, "thirteen"s, "fourteen"s, "fifteen"s, 
                                 "sixteen"s, "seventeen"s, "eighteen"s, "nineteen"s};

    vector<string> tens_names = {"twenty"s, "thirty"s, "fourty"s, "fifty"s, 
                                  "sixty"s, "seventy"s, "eighty"s, "ninety"s};
    int number;
    cin >> number;

    // Вычислим единицы и десятки как остаток и частное:
    int units = number % 10;
    int tens = number / 10;

    if (number < 20) {
        cout << num_names[number] << endl;
    }
    else if (units == 0) {
        cout << tens_names[tens - 2] << endl;
    }
    else {
        cout << tens_names[tens - 2] << "-"s << num_names[units] << endl;
    }
}