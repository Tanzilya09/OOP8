#include <iostream>
using namespace std;

class Array {
private:
    int* ptr;   
    int n;   
public:
    Array(int s) : n(s) {
        ptr = new int[n];
    }
    Array(const Array& other) : n(other.n) {
        ptr = new int[n];
        for (int i = 0; i < n; i++)
            ptr[i] = other.ptr[i];
    }

    Array& operator=(const Array& other) {
        if (this == &other)
            return *this; 
        delete[] ptr; 
        n = other.n;
        ptr = new int[n];
        for (int i = 0; i < n; i++)
            ptr[i] = other.ptr[i];

        return *this;
    }
    ~Array() {
        delete[] ptr;
    }
    int& operator[](int j) {
        return *(ptr + j);
    }

    int getSize() const {
        return n;
    }
};
int main() {
    setlocale(LC_ALL, "rus"); 
    const int N = 10;
    Array arr1(N);

    for (int j = 0; j < N; j++)
        arr1[j] = j * j;
    Array arr2(arr1);
    Array arr3(N);
    arr3 = arr1;
    cout << "arr1: ";
    for (int j = 0; j < N; j++)
        cout << arr1[j] << ' ';
    cout << endl;
    cout << "arr2: ";
    for (int j = 0; j < arr2.getSize(); j++)
        cout << arr2[j] << ' ';
    cout << endl;

    cout << "arr3: ";
    for (int j = 0; j < arr3.getSize(); j++)
        cout << arr3[j] << ' ';
    cout << endl;

    return 0;
}


