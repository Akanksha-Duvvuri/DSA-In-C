#include <stdio.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int priority(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]){
    int k = 0;

    for(int i = 0; infix[i] != '\0'; i++){

        if(infix[i] >= '0' && infix[i] <= '9'){
            postfix[k++] = infix[i];
        }
        else{
            while(top != -1 && priority(peek()) >= priority(infix[i])){
                postfix[k++] = pop();
            }

            push(infix[i]);
        }
    }

    while(top != -1){
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main(){
    char infix[100] = "2+3*4";
    char postfix[100];

    infixToPostfix(infix, postfix);

    printf("Postfix = %s\n", postfix);

    return 0;
}