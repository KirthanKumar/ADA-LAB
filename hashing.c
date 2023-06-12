#include<stdio.h>
#define size 7

int arr[size];

void init(){
    int i;
    for(i=0; i<size; i++){
        arr[i] = -1;
    }
}

int hashFunc2(int value){
    return (5-(value % 5));
}

void linearProbing(int value){
    int key = value % size;
    if(arr[key] == -1){
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else{
        printf("Collision : arr[%d] has element %d already\n", key, arr[key]);
        while(arr[key] != -1){
            key++;
            arr[key] = value;
            printf("%d inserted at arr[%d]\n", value, key);
        }
    }
}

void quadraticProbing(int value){
    int key = value % size;
    if(arr[key] == -1){
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else{
        printf("Collision : arr[%d] has element %d already\n", key, arr[key]);
        int i = 1;
        while(key != -1){
            key += i*i;
            arr[key] = value;
            printf("%d inserted at arr[%d]\n", value, key);
            i++;
        }
    }
}

void doubleHashing(int value){
    int key = value % size;
    if(arr[key] == -1){
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else{
        printf("Collision : arr[%d] has element %d already\n", key, arr[key]);
        int i = 1;
        while(key != -1){
            key += i*hashFunc2(value);
            arr[key] = value;
            printf("%d inserted at arr[%d]\n", value, key);
            i++;
        }
    }
}

void del(int value){
    int key = value%size;
    if(arr[key] == value){
        arr[key] = -1;
    }
    else{
        printf("%d not present in the hash table\n", value);
    }
}

void search(int value){
    int key = value % size;
    if(arr[key] == value){
        printf("Search Found\n");
    }
    else{
        printf("Search Not Found\n");
    }
}

void print(){
    int i;
    for(i=0; i<size; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main(){

    init();
    print();

    return 0;
}
