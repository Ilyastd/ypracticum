#include <iostream>

using namespace std;

int main() {
    string house_color_1, house_color_2, house_color_3, target_house_color;
    cin >> house_color_1 >> house_color_2 >> house_color_3 >> target_house_color;
    
    int house_number = 0;
    if (target_house_color == house_color_1) {
        house_number = 1;
    } else if (target_house_color == house_color_2) {
        house_number = 2;
    } else if (target_house_color == house_color_3) {
        house_number = 3;
    }
    
    if (house_number != 0) {
        cout << "Enter the house "s << house_number << endl;
    } else {
        cout << "Seek somewhere else"s << endl;
    }
    return 0;
}