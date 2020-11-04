#include <iostream>
#include <cstring>

using namespace std;

class Node {
public:
    char data;
    Node *next;
};

class Stack {
private:
    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char x);

    char pop();

    int parenthesisMatching(char *exp);

    int allBracketsMatching(char *exp);

    char stackTop();

    int isEmpty();

    static int precedenceChecker(char x);

    static int isOperand(char x);

    char *infixToPostfix(char *exp);

    int postfixEvaluation(char *postfix);
};

void Stack::push(char x) {
    Node *n = new Node;
    n->data = x;
    n->next = top;
    top = n;
}

char Stack::pop() {
    char x = -1;
    if (top != nullptr) {
        x = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    return x;
}

int Stack::parenthesisMatching(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == nullptr) {
                return 0;
            }
            pop();
        }
    }

    if (top == nullptr)
        return 1;
    else
        return 0;
}

int Stack::allBracketsMatching(char *exp) {
    char x;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
            continue;
        }

        if (isEmpty()) {
            return false;
        } else {
            switch (exp[i]) {
                case ')':
                    x = stackTop();
                    pop();
                    if (x == '{' || x == '[') {
                        return false;
                    }
                    break;
                case '}':
                    x = stackTop();
                    pop();
                    if (x == '(' || x == '[') {
                        return false;
                    }
                    break;
                case ']':
                    x = stackTop();
                    pop();
                    if (x == '(' || x == '{') {
                        return false;
                    }
                    break;
            }
        }
    }
    return (isEmpty());
}

int Stack::isEmpty() {
    if (top == nullptr)
        return 1;
    else
        return 0;
}

char Stack::stackTop() {
    if (!isEmpty()) {
        return top->data;
    } else {
        return -1;
    }
}

int Stack::precedenceChecker(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int Stack::isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *Stack::infixToPostfix(char *exp) {
    char *postfix;
    postfix = new char[strlen(exp) + 1];

    int i = 0;
    int j = 0;

    while (exp[i] != '\0') {
        if (isOperand(exp[i])) {
            postfix[j++] = exp[i++];
        } else {
            if (precedenceChecker(exp[i]) > precedenceChecker(stackTop()))
                push(exp[i++]);
            else {
                postfix[j++] = pop();
            }
        }
    }

    while (top != nullptr) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int Stack::postfixEvaluation(char *postfix) {
    int x1, x2, r;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else {
            x2 = pop();
            x1 = pop();

            switch (postfix[i]) {
                case '+' :
                    r = x1 + x2;
                    push(r);
                    break;
                case '-' :
                    r = x1 - x2;
                    push(r);
                    break;
                case '*' :
                    r = x1 * x2;
                    push(r);
                    break;
                case '/' :
                    r = x1 / x2;
                    push(r);
                    break;
            }
        }
    }
    return pop();
}

int main() {
    Stack stack;

    char *infix = "35*62/+4-";

    int num = stack.postfixEvaluation(infix);
    cout << num << endl;

    return 0;

}
