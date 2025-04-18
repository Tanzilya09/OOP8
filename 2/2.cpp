#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "Введите название публикации: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore();
    }

    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " сом" << endl;
    }

    virtual ~publication() {}
};

class book : public publication {
private:
    int page_count;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> page_count;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Страниц: " << page_count << endl;
    }
};

class tape : public publication {
private:
    float playing_time;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите длительность записи (в минутах): ";
        cin >> playing_time;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Длительность: " << playing_time << " минут" << endl;
    }
};


int main() {
    setlocale(LC_ALL, "rus");    
    const int N = 100;
    publication* pubarr[N]; 
    int n = 0; 
    char choice;

    do {
        cout << "\nСоздать книгу (k) или кассету (c)? ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 'k' || choice == 'K') {
            pubarr[n] = new book;
        }
        else if (choice == 'c' || choice == 'C') {
            pubarr[n] = new tape;
        }
        else {
            cout << "Некорректный выбор\n";
            break;
        }
        pubarr[n]->getdata(); 
        n++;
        cout << "Добавить ещё публикацию? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while ((choice == 'y' || choice == 'Y') && n < N);
    for (int j = 0; j < n; j++) {
        cout << "\nПубликация " << j + 1 << ":\n";
        pubarr[j]->putdata(); 
    }

    for (int j = 0; j < n; j++) {
        delete pubarr[j];
    }

    return 0;
}

