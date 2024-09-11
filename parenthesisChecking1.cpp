#include <iostream>
using namespace std;

class stack {
    char data;
    stack* next;

public:
    stack* top;

    stack() {
        top = nullptr;
    }

    stack(char value) {
        data = value;
        next = nullptr;
    }

    bool empty() {
        return top == nullptr;
    }

    void push(char value) {
        stack* newNode = new stack(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        stack* temp = top;
        char n = temp->data;
        top = top->next;
        delete temp;
    }

    char peek() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return '\0'; // Return a default value
        }
        return top->data;
    }

    bool parenthesisChecking(string str) {
        for (char c : str) {
            if (c == '(') {
                push(c);
            } else if (c == ')') {
                if (empty()) {
                    return false;
                }
                pop();
            }
        }
        return empty();
    }
};

int main() {
    stack s;
    string str1 = "(4*2)";
    if (s.parenthesisChecking(str1)) {
        cout << "Expression is balanced" << endl;
    } else {
        cout << "Expression not balanced" << endl;
    }
}
