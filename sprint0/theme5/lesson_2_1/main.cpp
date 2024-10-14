#include <iostream>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    int answer = 1;
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            answer = 0;
        }
    }
    cout << answer << endl;
}

int main() {
    IsPalindrome("abacaba"s);
    IsPalindrome("abacdba"s);
}