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
    book myBook;
    tape myTape;

    cout << "Ввод данных для книги :\n";
    myBook.getdata();

    cout << "\nВвод данных для аудиокассеты :\n";
    myTape.getdata();

    cout << "\nИнформация о книге :\n";
    myBook.putdata();

    cout << "\nИнформация о кассете :\n";
    myTape.putdata();

    return 0;
}
