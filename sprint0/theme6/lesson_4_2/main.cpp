#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromeFilter(vector<string> words, int min_length) {
    vector<string> result;
    for (string s : words) {
        if (s.size() >= min_length && IsPalindrome(s)) {
            result.push_back(s);
        }
    }
    return result;
}

int main() {
}