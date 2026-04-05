#include<stdio.h>

void change(int x) {
    x = 100;
}

void modify(int arr[]){  
    arr[0] = 10;
}

void foo(int *arr) {
    arr[1] += 5;
}

void changeptr(int *w) {
    *w = 50; //value of the element
}

int main() {
    int arr[3] = {2,4,6};
    printf("%d\n", arr[2]);

    int *p = arr;
    printf("%d\n", *(p+1));

    int a = 10;
    change(a);
    printf("%d\n", a); //wont change as its passed by value


    int b[2] = {1,2};
    modify(b);
    printf("%d\n", b[0]);  //arrays are passed by ref

    int arr2[3] = {5, 10, 15};
    int *ptr = arr2;
    printf("%d\n", *ptr + *(ptr+2));

    int x = 7;
    int *ptr2 = &x;
    *ptr2 += 3;
    printf("%d\n", x);

    foo(arr);
    printf("%d\n", arr[1]);

    // int *ptr3;
    // printf("%d\n", *ptr3);  //segmentation fault - undefined behaviour because its uninitialised, it points to a random memeory address rather than a valid integer causing a runtime error (segmentation fault) or printing garbage value when printf tries to deference it

    int c = 10;
    int *ptr4 = &c;
    int **q = &ptr4;

    **q = 20;

    printf("%d %d %d\n", c, *ptr4, **q);

    int s = 10;
    changeptr(&s);
    printf("%d", s);
    return 0;
}