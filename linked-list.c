#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *head)
{
    struct node *ptr;

    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertBeg(int data, struct node *head)
{
    struct node *newNode = malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        return head;
    }

    newNode->data = data;

    newNode->next = head;

    head = newNode;

    return head;
}

struct node *insertLast(int data, struct node *head)
{
    struct node *newNode, *ptr;

    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    ptr = head;

    if (ptr != NULL)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newNode;
    }

    else
    {
        head = newNode;
    }

    return head;
}

struct node *insertAfter(int value, int data, struct node *head)
{
    struct node *temp, *newNode;

    newNode = malloc(sizeof(struct node));

    newNode->data = data;
    temp = head;

    while ((temp->data != value) && (temp != NULL))
    {
        temp = temp->next;
    }

    if (temp->data == value)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

struct node *deleteBeg(struct node *head)
{

    struct node *ptr;

    if (head == NULL)
    {
        return head;
    }

    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }

    return head;
}

struct node *deleteEnd(struct node *head)
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        return head;
    }

    else if (head->next = NULL)
    {
        free(head);
        head = NULL;
    }

    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }

    return head;
}

struct node *deleteAfter(struct node *head, int key)
{
    struct node *curr, *temp;

    curr = head;

    while (curr->next != NULL)
    {
        if (curr->data == key)
        {
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
            break;
        }
        curr = curr->next;
    }

    return head;
}

struct node *deleteList(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }

    return head;
}