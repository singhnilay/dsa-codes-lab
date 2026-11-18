#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createNode(int data){
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

struct node* insert(struct node* root, int data){
    struct node* newNode = createNode(data);

    if (root == NULL){
        return newNode;
    }

    if (data > root->data){
        root->right = insert(root->right, data);
    }

    else if (data < root->data) {
        root->left = insert(root->left, data);
    }

    return root;
}

struct node* findMin(struct node* root){
    if (root == NULL){
        return root;
    }

    else {
        root = root->left;
    }

    return root;
}

struct node* deleteNode(struct node* root, int data){
    if (root == NULL){
        return root;
    }

    if (data > root->data){
        root->right = deleteNode(root->right, data);
    }

    else if (data < root->data){
        root->left = deleteNode(root->left, data);
    }

    else {
        if (root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        else if (root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

struct node* search(struct node* root, int val){

    if (root == NULL || root->data == val){
        return root;
    }

    else if (val > root->data)
    {
        return search(root->right, val);
    }

    else {
        return search(root->left, val);
    }
    
}
