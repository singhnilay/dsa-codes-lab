#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

int isFull(int stack[]){
    return (top == SIZE-1);
}

int isEmpty(int stack[]){
    return (top == -1);
    
}

void push(int stack[], int num){
    if (isFull(stack)){
        printf("Overflow");
        return;
    }

    else{
        stack[++top] = num;
    }
}

int pop(int stack[]){
    if (isEmpty(stack))     
    {
        printf("Underflow, returning -1");
        return -1;
    }

    else{
        int num = stack[top--];
        return num;
    }
}

int peek(int stack[]){
    if (isEmpty(stack)){
        return -1;
    }

    else {
        return (stack[top]);
    }
}

void display(int stack[]){
    int i = top;

    while (i >= 0)
    {
        printf("%d ", stack[i]);
        i--;
    }
    
}

