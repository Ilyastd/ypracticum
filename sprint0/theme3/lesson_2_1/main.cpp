#include <iostream>

using namespace std;

int main() {
    // Считайте целое число (код с ошейника) из стандартного ввода
    // Если это код 11235813, выведите Fibo is found (Фибо найден)
    // Иначе выведите This is not Fibo (Это не Фибо)
    int fiboCode = 11235813;
    int inCode;
    cin >> inCode;
    if(inCode == fiboCode) {
        cout << "Fibo is found"s << endl;
    } else {
        cout << "This is not Fibo"s << endl;
    }
}