#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int data){

    struct node* newNode = malloc(sizeof(struct node));

    if (newNode == NULL){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//insert first last and after

struct node* insertBeg(struct node* head, int data){
    struct node* newNode = createNode(data);

    newNode->next = head;
    
    return newNode;
}

struct node* insertLast(struct node* head, int data){
    struct node* newNode = createNode(data);

    if (head == NULL){
        newNode->next = head;
        return newNode;
    }

    else if (head->next == NULL){
        head->next = newNode;
        return head;
    }

    struct node* temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

struct node* insertAfter(struct node* head, int data, int key){
    

    struct node* newNode = createNode(data);

    if (head == NULL){
        return head;
    }
    struct node* temp = head;


    while (temp != NULL){
        if (temp->data == key){
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }

        else {
            temp = temp->next;
        }
    }

    return head;
}


struct node* deleteBeg(struct node* head){
    if (head == NULL){
        return head;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteLast(struct node* head){

    if (head == NULL){
        return head;
    }

    else if (head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }

    struct node *temp, *curr;

    {
        while (temp->next != NULL){
            curr = temp;
            temp = temp->next;
            }

        free(temp);
        curr->next = NULL;
        return head; 
    }    
}

struct node* deleteAfter(struct node* head, int key){

    if (head == NULL){
        return head;
    }

    struct node* curr, *temp;

    curr = head;

    while (curr->data != key){
        curr = curr->next;
    }

    if (curr == NULL){
        return head;
    }

    else{
        temp = curr->next;
        curr->next = temp->next;
        free(temp);

        return head;
    }
}

struct node* deleteList(struct node* head){
    struct node* temp = head;

    while (temp!=NULL){
        temp = head->next;
        free(head);
        head = temp;
    }

    return NULL;
}


