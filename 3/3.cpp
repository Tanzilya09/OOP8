#include <iostream>
#include <cmath>
using namespace std;

class Distance {
protected:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {
        normalize();}
    Distance(float fdist) {
        feet = static_cast<int>(fdist);
        inches = (fdist - feet) * 12.0f;
        normalize();
    }
    virtual void getdist() {
        cout << "Введите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
        normalize();
    }
    virtual void showdist() const {
        cout << feet << "\'-" << inches << "\"";
    }

    virtual Distance* multiply(const Distance* other) const = 0;
    void normalize() {
        if (inches >= 12.0) {
            feet += static_cast<int>(inches / 12);
            inches = fmod(inches, 12.0);
        }
    }

    float toInches() const {
        return feet * 12.0f + inches;
    }
    friend Distance* operator*(const Distance& d1, const Distance& d2);
    friend Distance* operator*(float val, const Distance& d);
};

class Mult : public Distance {
public:
    Mult() : Distance() {}
    Mult(int ft, float in) : Distance(ft, in) {}
    Mult(float fdist) : Distance(fdist) {}

    Distance* multiply(const Distance* other) const override {
        float res = this->toInches() * other->toInches();
        return new Mult(res / 12.0f);
    }

    friend Mult operator*(float val, const Mult& d);
};

Distance* operator*(const Distance& d1, const Distance& d2) {
    return d1.multiply(&d2);
}

Distance* operator*(float val, const Distance& d) {
    float res = d.toInches() * val;
    return new Mult(res / 12.0f);
}

Mult operator*(float val, const Mult& d) {
    float res = d.toInches() * val;
    return Mult(res / 12.0f);
}

int main() {
    setlocale(LC_ALL, "rus");  
    Distance* d1 = new Mult();
    Distance* d2 = new Mult();

    cout << "Введите первое расстояние:\n";
    d1->getdist();
    cout << "Введите второе расстояние:\n";
    d2->getdist();

    Distance* result = (*d1) * (*d2);
    cout << "\nРезультат умножения расстояний: ";
    result->showdist();

    Distance* result2 = 2.5f * (*d1);
    cout << "\nРезультат 2.5 * первое расстояние: ";
    result2->showdist();

    delete d1;
    delete d2;
    delete result;
    delete result2;

    return 0;
}


