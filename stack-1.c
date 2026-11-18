#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];

int top = -1;

int isFull(int stack[]){
    return (top == SIZE - 1);
}

int isEmpty(int stack[]){
    return (top == -1);
}

void push(int stack[], int data){
    if (isFull(stack)){
        printf("Overflow");
        return;
    }

    stack[++top] = data;
    return;
}   

int pop(int stack[]){
    if (isEmpty(stack)){
        printf("Underflow");
        return -1;
    }

    return stack[top--];
}

int peek(int stack[]){
    if (isEmpty(stack)){
        printf("Nothing to display");
        return -1;
    }

    return stack[top];
}

void display(int stack[]){
    if (isEmpty(stack)){
        printf("Nothing to display");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return;
    
}


