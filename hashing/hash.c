#include<stdio.h>
#include<stdlib.h>

//Hashing = directly jump to where data should be stored - CORE IDEA. Not searching the whole list
//table[index] = always points to the head of the list

#define SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* table[SIZE]; //array of LL, each index stores a LL head
 
Node* createnode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("memory allocation failed\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

//hash function - decides which index to go to
int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);

    Node* newnode = createnode(key); //data is the key

    //insert at beginning of LL in that index
    newnode->next = table[index];
    table[index] = newnode;
}

void search(int key) {
    int index = hash(key);

    Node* temp = table[index]; //first go to that index in the hash table

    while(temp != NULL){ //then traverse the LL to find the element required
        if(temp->data == key){
            printf("found the key at index: %d\n", index);
            return;
        } 
        temp = temp->next;
    }

    printf("not found\n");
}

void delete(int key){
    int index = key % SIZE;

    Node* temp = table[index];
    Node* prev = NULL;

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("key not found\n");
        return;
    }

    //first node
    if(prev == NULL){
        table[index] = temp->next;
    } else {
        prev->next = temp->next; //deleting temp
    }

    free(temp);
}

void display() {
    for(int i = 0; i< SIZE; i++){
        printf("[%d]: ", i);

        Node* temp = table[i];

        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    //initialising the table
    for(int i = 0; i< SIZE; i++) {
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

// archlinux% gcc hash.c && ./a.out
// [0]: NULL
// [1]: NULL
// [2]: NULL
// [3]: NULL
// [4]: NULL
// [5]: 15 -> 35 -> 25 -> NULL
// [6]: NULL
// [7]: 7 -> NULL
// [8]: NULL
// [9]: NULL
// found the key at index: 5
// not found


//initially youre initialising to NULL and then youre only inserting a few values right? so only those will have LL
//NULL here means theres no LL at that index
//Only indices where keys hash to will have data, rest stay NULL