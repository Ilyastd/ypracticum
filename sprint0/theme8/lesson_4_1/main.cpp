#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string FindWidespreadBird(const vector<string>& types) {
    map<string, int> bird_count;

    // пройдём по вектору и по названию-ключу увеличим счетчик
    for (const string& type : types) {
        bird_count[type]++;
    }

    // находим самую популярную птицу
    int current_max = 0;
    string widespread_bird;
    for (auto& [bird, count] : bird_count) {
        if (count > current_max) {
            current_max = count;
            widespread_bird = bird;
        }
    }
    
    return widespread_bird;
}

int main() {
    vector<string> bird_types1 = {"zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s};
    if (FindWidespreadBird(bird_types1) == "sinica"s) {
        cout << "Correct"s << endl;
    } else {
        cout << "Not correct"s << endl;
    }

    vector<string> bird_types2 = {"ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s};
    if (FindWidespreadBird(bird_types2) == "blue bird of fortune"s ) {
        cout << "Correct"s << endl;
    } else {
        cout << "Not correct"s << endl;
    }
}