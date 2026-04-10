#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createnode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL){
        printf("allocation failed\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void insertend(int data) {
    Node* newnode = createnode(data);

    if(head == NULL) {
        head = tail = newnode;
        tail->next = head; //circular LL
    } else {
        tail->next = newnode;
        tail = newnode;
        tail->next = head; //circular LL
    }
}

void print() {\
    if(head == NULL) {
        printf("empty LL\n");
        return;
    }

    Node* temp = head;

    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("%d\n", head->data); //prints the head again


}

int main() {
    insertend(1);
    insertend(2);
    insertend(3);


    print();
    return 0;
}