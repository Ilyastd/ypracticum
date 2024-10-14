#include <iostream>

using namespace std;

/* Допишите класс в соответствии с требованиями задания*/
class TV {
public:
    // Включает телевизор.
    void TurnOn() {
        // Напишите код этого метода
        enabled_ = true;
    }

    // Выключает телевизор
    void TurnOff() {
        // Напишите код этого метода
        enabled_ = false;
    }

    // Возвращает true, если телевизор включен и false, если телевизор выключен
    bool IsTurnedOn() {
        // Напишите код этого метода
        return enabled_;
    }

    // Возвращает номер текущего канала, либо 0, если телевизор был выключен.
    // Номер канала не сбрасывается при выключении и повторном включении.
    // При первом включении телевизор показывает канал №1.
    int GetCurrentChannel() {
        // Напишите код этого метода
        if (!enabled_) {
            return 0;
        }
        return channel_;
    }

    // Выбирает канал с указанным номером. Номер канала должен быть в диапазоне [1..99].
    // Если указан недопустимый номер канала, либо телевизор выключен, возвращает false и не меняет
    // текущий канал. В противном случае возвращает true.
    bool SelectChannel(int channel) {
        // Напишите код этого метода
        if (!IsTurnedOn() || (channel < 1 || channel > 99)) {
            return false;
        }
        channel_ = channel;
        return true;
    }
private:
    bool enabled_ = false;
    int channel_ = 1;
};

int main() {
    TV tv;
    cout << tv.IsTurnedOn() << ", channel:"s << tv.GetCurrentChannel() << endl;
    tv.TurnOn();
    cout << tv.IsTurnedOn() << ", channel: "s << tv.GetCurrentChannel() << endl;
    tv.SelectChannel(25);
    cout << tv.IsTurnedOn() << ", channel: "s << tv.GetCurrentChannel() << endl;
    tv.TurnOff();
    cout << tv.IsTurnedOn() << ", channel: "s << tv.GetCurrentChannel() << endl;
}