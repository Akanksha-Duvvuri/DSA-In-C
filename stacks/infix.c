#include <stdio.h>
#include <ctype.h>
#define MAX 100

// ---- char stack for infix to postfix ----
char cstack[MAX];
int ctop = -1;

void cpush(char x) { cstack[++ctop] = x; }
char cpop() { return cstack[ctop--]; }
char cpeek() { return cstack[ctop]; }

// ---- int stack for evaluation ----
int istack[MAX];
int itop = -1;

void ipush(int x) { istack[++itop] = x; }
int ipop() { return istack[itop--]; }

// ---- precedence ----
int precedence(char op) {
    if (op == '+' || op == '-') { return 1; }
    if (op == '*' || op == '/') { return 2; }
    return 0;
}

// ---- infix to postfix ----
void infixToPostfix(char exp[], char postfix[]) {
    int k = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            postfix[k++] = exp[i];
        } else if (exp[i] == '(') {
            cpush(exp[i]);
        } else if (exp[i] == ')') {
            while (cpeek() != '(') { postfix[k++] = cpop(); }
            cpop();
        } else {
            while (ctop != -1 && precedence(cpeek()) >= precedence(exp[i])) {
                postfix[k++] = cpop();
            }
            cpush(exp[i]);
        }
    }
    while (ctop != -1) { postfix[k++] = cpop(); }
    postfix[k] = '\0';
}

// ---- evaluate postfix ----
int evaluate(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            ipush(exp[i] - '0');
        } else {
            int b = ipop();
            int a = ipop();
            if (exp[i] == '+') { ipush(a + b); }
            else if (exp[i] == '-') { ipush(a - b); }
            else if (exp[i] == '*') { ipush(a * b); }
            else if (exp[i] == '/') { ipush(a / b); }
        }
    }
    return ipop();
}

// ---- main ----
int main() {
    char exp[] = "2+3*4";
    char postfix[MAX];

    infixToPostfix(exp, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluate(postfix));

    return 0;
}