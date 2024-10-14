#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> BuildReversedMap(const map<string, string>& m) {
    map<string, string> result;
    for (const auto& [key, value]: m) {
        result[value] = key;
    }
    return result;
}