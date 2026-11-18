#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL){
        return NULL;
    }

    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int data){
    struct Node* newNode = createNode(data);
    
    if (root == NULL){
        return newNode;
    }

    else if (data > root->data){
        root->right = insert(root->right, data);
    }
    
    else if (data < root->data){
        root->left = insert(root->left, data);
    }

    return root;
}

struct Node* findMin(struct Node* root){
    if (root == NULL){
        return root;
    }

    else {
        while (root->left != NULL){
            root = root->left;
        }
    }

    return root;
}

struct Node* search(struct Node* root, int data){
    if ((root == NULL) || (root->data == data)){
        return root;
    }

    else if (root->data > data){
        return search(root->left, data);
    }

    else {
        return search(root->right, data);
    }
}

struct Node* deleteNode(struct Node* root, int data){
    if (root == NULL){
        return root;
    }

    else if (root->data < data){
        root->right = deleteNode(root->right, data);
    }

    else if (root->data > data){
        root->left = deleteNode(root->left, data);
    }

    else {
        if (root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, data);
            return root;
        }
    }
}

void deleteTree(struct Node* root){
    if (root == NULL){
        return;
    }

    deleteTree(root->right);
    deleteTree(root->left);
    free(root);
}