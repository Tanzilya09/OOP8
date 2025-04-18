#include <iostream>
#include <cmath>
using namespace std;

class Horse {
protected:
    float position;
    string name;
public:
    Horse(string name) : name(name), position(0.0f) {}

    virtual void horse_tick(Horse* hArray[], int numHorses) {
        position += 0.1f;
        cout << name << " прошла " << position << " форлонгов." << endl;
    }
    float getPosition() const {
        return position;
    }
    string getName() const {
        return name;
    }
};

class ComHorse : public Horse {
public:
    ComHorse(string name) : Horse(name) {}
    void horse_tick(Horse* hArray[], int numHorses) override {
        position += 0.1f;
        bool isLeading = true;
        for (int i = 0; i < numHorses; i++) {
            if (hArray[i] != this && hArray[i]->getPosition() > position) {
                isLeading = false;
                break;
            }
        }

        if (isLeading) {
            for (int i = 0; i < numHorses; i++) {
                if (hArray[i] != this && abs(hArray[i]->getPosition() - position) < 0.1f) {
                    position += 0.05f;
                    cout << name << " ускоряется, чтобы остаться впереди!" << endl;
                    break;
                }
            }
        }
        cout << name << " прошла " << position << " форлонгов." << endl;
    }
};

class ComTrack {
private:
    Horse* hArray[100];
    int numHorses;
public:
    ComTrack() : numHorses(0) {}

    void addHorse(Horse* h) {
        hArray[numHorses++] = h;
    }
    void race() {
        for (int tick = 0; tick < 10; tick++) {
            cout << "Такт " << tick + 1 << ":\n";
            for (int i = 0; i < numHorses; i++) {
                hArray[i]->horse_tick(hArray, numHorses);
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    ComTrack track;
    Horse* h1 = new Horse("Лошадь 1");
    Horse* h2 = new ComHorse("Конкурентная Лошадь 2");
    Horse* h3 = new ComHorse("Конкурентная Лошадь 3");
    track.addHorse(h1);
    track.addHorse(h2);
    track.addHorse(h3);
    track.race();

    delete h1;
    delete h2;
    delete h3;
    return 0;
}

