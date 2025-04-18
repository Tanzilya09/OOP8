#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class Token { 
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
};

class Number : public Token {
private:
    float value;
public:
    Number(float val) : value(val) {} 
    float getNumber() override { return value; }
    char getOperator() override { return '\0'; }
};

class Operator : public Token { 
private:
    char op;
public:
    Operator(char oper) : op(oper) {}
    float getNumber() override { return 0.0f; }
    char getOperator() override { return op; }
};

class TokenList {
private:
    Token* tokens[100];
    int index;
public:
    TokenList() : index(0) {}
    void push(Token* t) {
        tokens[index++] = t;
    }
    Token* pop() {
        return tokens[--index];
    }
    bool isEmpty() {
        return index == 0;
    }
};

float evaluatePostfixExpression(const string& expression) {
    TokenList s;
    const char* ptr = expression.c_str();

    while (*ptr) {
        if (isdigit(*ptr) || *ptr == '.') {
            float number = strtof(ptr, (char**)&ptr);
            Number* numToken = new Number(number);
            s.push(numToken);
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            Operator* opToken = new Operator(*ptr);
            s.push(opToken);
            ptr++;
        }
        else {
            ptr++;
        }
    }

    while (!s.isEmpty()) {
        Token* token = s.pop();
        if (token->getOperator() == '\0') {
            cout << "Число: " << token->getNumber() << endl;
        }
        else {
            cout << "Оператор: " << token->getOperator() << endl;
        }
        delete token;
    }

    return 0.0f;
}

int main() {
    setlocale(LC_ALL, "rus"); 
    string expr = "3.14 2.0 + 75.25 3.333 * + 6.02 /";
    evaluatePostfixExpression(expr);
    return 0;
}
