#include <iostream>
#include <string>
#include <cstdlib> 
#include <cctype>
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
    bMoney operator+(const bMoney& m) const {
        return bMoney(money + m.money);
    }

    bMoney operator-(const bMoney& m) const {
        return bMoney(money - m.money);
    }

    bMoney operator*(long double n) const {
        return bMoney(money * n);
    }

    bMoney operator/(long double n) const {
        return bMoney(money / n);
    }

    long double operator/(const bMoney& m) const {
        return money / m.money;
    }

    friend bMoney operator*(long double n, const bMoney& m);
    friend bMoney operator/(long double n, const bMoney& m);
};

bMoney operator*(long double n, const bMoney& m) {
    return bMoney(n * m.money);
}

bMoney operator/(long double n, const bMoney& m) {
    return bMoney(n / m.money);
}

int main() {
    setlocale(LC_ALL, "rus");
    bMoney m1, m2, result;
    long double num;
    m1.getMoney();
    m2.getMoney();
    cout << "Введите число с плавающей точкой: ";
    cin >> num;

    cout << "\nСложение: "; (m1 + m2).putMoney();
    cout << "Вычитание: "; (m1 - m2).putMoney();
    cout << "Умножение m1 * num: "; (m1 * num).putMoney();
    cout << "Деление m1 / num: "; (m1 / num).putMoney();
    cout << "Деление m1 / m2 = " << (m1 / m2) << endl;
    cout << "Умножение num * m2: "; (num * m2).putMoney();
    cout << "Деление num / m2: "; (num / m2).putMoney();

    return 0;
}

