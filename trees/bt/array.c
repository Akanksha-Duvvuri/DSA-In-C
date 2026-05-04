#include <stdio.h>

int tree[10];

int main(){
    tree[1] = 10;
    tree[2] = 20;
    tree[3] = 30;
    tree[4] = 40;
    tree[5] = 50;

    for(int i = 1; i <= 5; i++){
        printf("%d ", tree[i]);
    }

    return 0;
}