#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int data){
    if(top == MAX - 1) {
        printf("stack overflow");
        return;
    }

    top++;
    stack[top] = data;
}

void pop(){
    if(top == -1){
        printf("empty stack");
        return;
    }

    top--;
}

int peek(){
    if(top == -1){
        printf("empty stack");
        return -1;
    }

    return stack[top];
}

void display(){
    if(top == -1){
        printf("empty stack");
        return;
    }

    for(int i=top; i>=0; i--){
        printf("%d ", stack[i]);
    }
}

int main(){

    push(3);
    push(2);
    push(1);

    display();

    pop();
    printf("popped: ");

    display();

    printf("stack top: ");
    printf("%d", peek());

    display();
    return 0;
    return 0;
}