#include <iostream>
using namespace std;

class Link {
public:
    int data;
    Link* next;
    Link(int val) : data(val), next(nullptr) {}
};

class LinkList {
private:
    Link* head;
public:
    LinkList() : head(nullptr) {}

    LinkList(const LinkList& other) : head(nullptr) {
        Link* temp = other.head;
        while (temp) {
            append(temp->data);
            temp = temp->next;
        }
    }

    LinkList& operator=(const LinkList& other) {
        if (this == &other) return *this;

        clear();
        Link* temp = other.head;
        while (temp) {
            append(temp->data);
            temp = temp->next;
        }
        return *this;
    }

    void append(int val) {
        Link* newLink = new Link(val);
        if (!head) {
            head = newLink;
        }
        else {
            Link* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newLink;
        }
    }

    void print() const {
        Link* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkList() {
        clear();
    }

    void clear() {
        Link* temp = head;
        while (temp) {
            Link* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    LinkList list1;
    list1.append(10);
    list1.append(20);
    list1.append(30);

    cout << "list1: ";
    list1.print();
    LinkList list2 = list1;
    cout << "list2 (после копирования): ";
    list2.print();
    LinkList list3;
    list3 = list1;
    cout << "list3 (после присваивания): ";
    list3.print();
    list1.clear();
    cout << "list1 (после очистки): ";
    list1.print();
    cout << "list2 (должен остаться без изменений): ";
    list2.print();
    cout << "list3 (должен остаться без изменений): ";
    list3.print();

    return 0;
}
