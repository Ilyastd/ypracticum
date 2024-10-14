#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (string& s : source) {
        destination.push_back(s);
    }
    source.clear();
}

main() {

}