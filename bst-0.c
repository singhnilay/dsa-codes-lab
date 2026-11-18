#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct Node* insert(struct Node* root, int data){
    struct Node* newNode = createNode(data);

    if (root == NULL){
        root = newNode;
        return newNode;
    }

    else if(data > root->data){
        root->right = insert(root->right, newNode);
    }

    else {
        root->left = insert(root->left, newNode);
    }

    return root;

}

struct Node* search(struct Node* root, int value){
    if (root == NULL || root->data == value){
        return root;
    }

    if (value > root->right){
        return search(root->right, value);
    }

    else return search(root->left, value);
}

void inOrder(struct Node* root){
    if (root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preOrder(struct Node* root){
    if (root==NULL){
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node* root){
    if (root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

struct Node* findMin(struct Node* root){
    if (root == NULL){
        return root; 
    }

    while (root->left != NULL){
        root = root->left;
    }

    return root;
}

void freeTree(struct Node* root){
    if (root == NULL){
        return;
    }

    freeTree(root->right);
    freeTree(root->right);
    free(root);
}

