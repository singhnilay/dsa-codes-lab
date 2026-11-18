#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

int isFull(int queue[]);
int isEmpty(int queue[]);
void enqueue(int queue[], int num);
int dequeue(int queue[]);
int peek(int queue[]);
void display(int queue[]);

int isFull(int queue[]){
    return (rear == MAX-1);
}

int isEmpty(int queue[]){
    return ((front == -1) || (front > rear));
}

void enqueue(int queue[], int num){
    if (isFull(queue)){
        printf("Queue Overflow");
        return;
    }

    if (front == -1){
        front = 0;
    }

    queue[++rear] = num;
    return;
}

int dequeue(int queue[]){
    if (isEmpty(queue)){
        printf("Underflow!!!");
        return -1;
    }

    int item = queue[front++];
    return item;
}

int peek(int queue[]){


    if (isEmpty(queue)){
        printf("Nothing to display! Queue empty");
        return -1;
    }

    int item = queue[front];

    return item;
}

void display(int queue[]){
    for (int i = rear; i >= front; i--){
        printf("%d ", queue[i]);
    }
}

