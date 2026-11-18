#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// push pop peek display

int isEmpty(int stack[]){
    return (top == -1);
}

int isFull(int stack[]){
    return (top == SIZE - 1);
}

void push(int stack[], int data){
    if (isFull(stack)){
        printf("Stack full bro!");
        return;
    }

    stack[++top] = data;
    return;
}

int pop(int stack[]){
    if (isEmpty(stack)){
        printf("Stack underflow!");
        return - 1;
    }

    int temp = stack[top--];
    return temp;
}

int peek(int stack[]){
    if (isEmpty(stack)){
        printf("stack empty!");
        return -1;
    }

    return stack[top];
}

void display(int stack[]){
    if (isEmpty(stack)){
        printf("Nothing to display!");
        return;
    }

    for (int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
}