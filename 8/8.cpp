#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
class Token {
public:
    virtual ~Token() {}
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
};
class Operator : public Token {
private:
    char oper;
public:
    Operator(char op) : oper(op) {}
    float getNumber() override { return 0.0f; }
    char getOperator() override { return oper; }
};

class Number : public Token {
private:
    float num;
public:
    Number(float n) : num(n) {}
    float getNumber() override { return num; }
    char getOperator() override { return '\0'; }
};

class Stack {
private:
    stack<Token*> stk;

public:
    void push(Token* token) {
        stk.push(token);
    }
    Token* pop() {
        if (stk.empty()) {
            cout << "Ошибка: Стек пуст!" << endl;
            return nullptr;
        }
        Token* token = stk.top();
        stk.pop();
        return token;
    }
    bool empty() const {
        return stk.empty();
    }
};

float evaluateExpression(const string& expr) {
    Stack stack;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0]) || token[0] == '.') {
            stack.push(new Number(stof(token)));
        }
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            char oper = token[0];
            Token* num2 = stack.pop();
            Token* num1 = stack.pop();
            if (num1 == nullptr || num2 == nullptr) {
                cout << "Ошибка: Недостаточно операндов для операции " << oper << endl;
                return 0;
            }

            float n1 = num1->getNumber();
            float n2 = num2->getNumber();
            float result = 0;

            switch (oper) {
            case '+': result = n1 + n2; break;
            case '-': result = n1 - n2; break;
            case '*': result = n1 * n2; break;
            case '/':
                if (n2 == 0) {
                    cout << "Ошибка: Деление на ноль!" << endl;
                    return 0;
                }
                result = n1 / n2;
                break;
            default:
                cout << "Ошибка: Неизвестный оператор!" << endl;
                return 0;
            }
            delete num1;
            delete num2;
            stack.push(new Number(result));
        }
    }

    Token* resultToken = stack.pop();
    if (resultToken == nullptr) {
        cout << "Ошибка: Стек пуст!" << endl;
        return 0;
    }
    float result = resultToken->getNumber();
    delete resultToken;
    return result;
}

int main() {
    setlocale(LC_ALL, "rus");
    string expression;
    cout << "Введите математическое выражение: ";
    getline(cin, expression);
    float result = evaluateExpression(expression);
    if (result != 0) {
        cout << "Результат: " << result << endl;
    }

    return 0;
}
