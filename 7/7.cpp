#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath> 
using namespace std;

class bMoney {
private:
    long double money;

public:
    bMoney() : money(0.0) {}
    bMoney(long double m) : money(m) {}

    void getMoney() {
        string str;
        cout << "Введите денежную сумму : ";
        cin >> str;
        money = mstold(str);
    }
    void putMoney() const {
        cout << "$" << money << endl;
    }

    long double mstold(const string& str) {
        string clean;
        for (char c : str) {
            if (isdigit(c) || c == '.') clean += c;
        }
        return stold(clean);
    }
    bMoney round() const {
        long double intPart, fracPart;
        fracPart = modfl(money, &intPart);
        if (fracPart < 0.5)
            return bMoney(intPart);
        else
            return bMoney(intPart + 1.0);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    bMoney m1, m2;
    cout << "Тест округления:" << endl;

    for (int i = 0; i < 3; i++) {
        m1.getMoney();
        cout << "Исходное: ";
        m1.putMoney();
        m2 = m1.round();
        cout << "Округленное: ";
        m2.putMoney();
    }

    return 0;
}
