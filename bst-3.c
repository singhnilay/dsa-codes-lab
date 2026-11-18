#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createNode(int data){
    struct node* newNode = malloc(sizeof(struct node));

    if (newNode == NULL){
        return NULL;
    }

    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

struct node* insert(struct node* root, int data){
    if (root == NULL){
        return createNode(data);
    }

    if (data > root->data){
        root->right = insert(root->right, data);
    }

    else if (data < root->data){
        root->left = insert(root->left, data);
    }

    return root;
}

struct node* findMin(struct node* root){
    if (root == NULL){
        return root;
    }

    while (root->left != NULL){
        root = root->left;
    }

    return root;
}

struct node* search(struct node* root, int key){
    if (root == NULL || root->data == key){
        return root;
    }

    if (key > root->data){
        return search(root->right, key);
    }

    else {
        return search(root->left, key);
    }
}

struct node* deleteNode(struct node* root, int value){

    if (root == NULL){
        return root;
    }

    if (value > root->data){
        root->right = deleteNode(root->right, value);
    }

    else if (value < root->data){
        root->left = deleteNode(root->left, value);
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

            root->right = deleteNode(root->right, root->data);
        }
    }

    return root;
}