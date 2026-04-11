#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int stack[MAX]; //defining an array for the stack
int top = -1;

void push(int data) {
    if(top == MAX - 1) { //full
        printf("stack overflow\n");
        return;
    }

    top++;
    stack[top] = data;
}

void pop(){
    if(top == -1) {
        printf("empty stack\n");
    }

    top--;
}

int peek(){
    if(top == -1) {
        printf("empty stack\n");
    }

    printf("%d", stack[top]);
}

void display() {
    if(top == -1) {
        printf("empty stack\n");
        return;
    }

    for(int i=top; i>=0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {

    push(3);
    push(2);
    push(1);

    display();

    pop();
    printf("popped: \n");

    display();

    printf("stack top: ");
    peek();

    // display();
    return 0;
}