#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

int isEmpty(int queue[]){
    return ((front == -1) || (front > rear));
}

int isFull(int queue[]){
    return (rear == SIZE -1);
}

void enqueue(int queue[], int data){
    if (isFull(queue)){
        printf("No can add. Overflow!!!");
        return;
    }

    queue[++rear] = data;
}

int dequeue(int queue[]){
    if (isEmpty(queue)){
        printf("Underflow!");
        return -1;
    }

    int temp = queue[front++];
    
    return temp;
}

int peek(int queue[]){
    if (isEmpty(queue)){
        printf("Empty");
        return -1;
    }

    return queue[front];
}

void display(int queue[]){

    for (int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
}