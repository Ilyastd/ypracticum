#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CountAndAddNewDogs(const vector<string>& new_dogs, const map<string, int>& max_amount,
    map<string, int>& shelter) {
    //
    return count_if(new_dogs.begin(), new_dogs.end(), [&max_amount, &shelter](const string& dog) {
        int count = shelter[dog];
        int max = max_amount.at(dog);
        if (max >= ++count) {
            shelter[dog] = count;
            return true;
        } else {
            return false;
        }
        });
}

int main() {
    map<string, int> shelter{
        {"shepherd"s, 1},
        {"corgi"s, 3},
    };

    map<string, int> max_amount{
        {"shepherd"s, 2},
        {"corgi"s, 3},
        {"shiba inu"s, 1},
    };

    int count = CountAndAddNewDogs({ "shepherd"s, "shiba inu"s, "shiba inu"s, "corgi"s }, max_amount, shelter);
    cout << count  << endl;
}