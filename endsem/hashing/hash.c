#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* table[SIZE];

Node* createnode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("memory allocation failed");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

int hash(int key){
    return key % SIZE;
}

void insert(int key){
    int index = hash(key);

    Node* newnode = createnode(key);

    newnode->next = table[index];
    table[index] = newnode;
}

void search(int key){
    int index = hash(key);

    Node* temp = table[index];

    while(temp != NULL){
        if(temp->data == key){
            printf("found the key at the index: %d", index);
            return;
        }

        temp = temp->next;
    }

    printf("not found");
}

void delete(int key){
    int index = hash(key);

    Node* temp = table[index];
    Node* prev = NULL;

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("key not found");
        return;
    }

    if(prev == NULL){
        table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void display(){
    for(int i=0; i<SIZE; i++){
        printf("[%d]: ", i);

        Node* temp = table[i];

        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL");
    }
}

int main(){
    for(int i=0; i<SIZE; i++){
        table[i] = NULL;
    }


    insert(25);
    insert(35);
    insert(15);
    insert(7);

    display();

    search(35);
    search(100);

    return 0;
}