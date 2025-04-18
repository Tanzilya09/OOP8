#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "Введите название: "; getline(cin, title);
        cout << "Введите цену: "; cin >> price;
        cin.ignore(); 
    }
    virtual void putdata() const {
        cout << "Название: " << title << ", Цена: " << price << endl;
    }

    virtual bool isOversize() const = 0;
    virtual ~publication() {}
};

class book : public publication {
private:
    int pages;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите количество страниц: "; cin >> pages;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Страниц: " << pages << endl;
    }

    bool isOversize() const override {
        return pages > 800;
    }
};

class tape : public publication {
private:
    float time;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите время проигрывания (в минутах): "; cin >> time;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Время: " << time << " минут" << endl;
    }

    bool isOversize() const override {
        return time > 90.0f;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    const int N = 5;
    publication* pubarr[N];
    int n = 0;
    char choice;

    do {
        cout << "Книга (k) или кассета (c)? ";
        cin >> choice;
        cin.ignore();

        if (choice == 'k') {
            pubarr[n] = new book;
        }
        else {
            pubarr[n] = new tape;
        }

        pubarr[n]->getdata();
        n++;

        cout << "Добавить еще? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' && n < N);

    cout << "\nИнформация о публикациях:\n";
    for (int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        if (pubarr[j]->isOversize())
            cout << "Превышение размера!" << endl;
        cout << endl;
    }

    for (int j = 0; j < n; j++)
        delete pubarr[j];

    return 0;
}

