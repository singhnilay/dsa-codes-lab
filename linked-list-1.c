#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createList(struct node*){
    struct node* head = malloc(sizeof(int));

    return head;
}

void traverse(struct node* head){
    struct node* temp = head;

    while (temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct node* insertBeg(struct node* head, int data){
    struct node* newNode = malloc(sizeof(struct node));

    if (newNode == NULL){
        return head;
    }

    if (head == NULL){
        newNode->data = data;
        newNode->next = NULL;

        return newNode;
    }

    else{
        newNode->data = data;
        newNode->next = head;

        return newNode;
    }
}

struct node* insertEnd(struct node* head, int data){
    struct node* newNode = malloc(sizeof(struct node));

    struct node* temp = head;

    newNode->data = data;
    newNode->next = NULL;

    if (temp != NULL){
        while (temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }

    else{
        head = newNode;
    }

    return newNode;
}

struct node* insertAfter(struct node* head, int value, int data){

    struct node* temp = head;

    struct node* newNode = malloc(sizeof(struct node));

    while ((temp!=NULL) && (temp->data != value)){
        temp = temp->next;
    }

    if (temp->data = value){
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

struct node* deleteBeg(struct node* head){

    struct node* temp = head;

    if (temp==NULL){
        return head;
    }

    head = head->next;
    free(temp);

    return head;
}

struct node* deleteLast(struct node* head){
    struct node *temp, *prev;

    temp = head;

    if (temp == NULL){
        return head;
    }

    while (temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    return head;

}

struct node* deleteBeg(struct node* head){
    struct node* temp = head;

    if (temp == NULL){
        return head;
    }

    else{
        temp = head->next;
        free(head);
        return temp;
    }
}

struct node* deleteAfter(struct node* head, int value){
    struct node *temp, *curr;

    temp = head;

    if (temp == NULL){
        return head;
    }

    else if (temp->next == NULL){
        head = NULL;
        free(temp);
    }

    else{
        while ((temp->data != value) && (temp != NULL)){
            temp = temp->next;
        }

        curr = temp->next;
        temp->next = curr->next;
        free(curr);
    }

    return head;
}

struct node* deleteList(struct node* head){
    struct node* temp = head;

    while (temp != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }

    return head;
}