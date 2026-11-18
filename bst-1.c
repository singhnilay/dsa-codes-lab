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
        root->right = insert(root, data);
    }

    else{
        root->left = insert(root, data);
    }

    return root;
}

struct node* search(struct node* root, int val){

    if (root == NULL){
        return root;
    }

    if (val > root->data){
        return search(root->right, val);
    }

    {
        return search(root->left, val);
    }

}

void inOrder(struct node* root){
    if (root == NULL){
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct node* root){
    if (root == NULL){
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node* root){
    if (root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
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

struct node* deleteTree(struct node* root){
    if (root == NULL){
        return root;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
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

        if (root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        else {
            struct node* temp = findMin(root->right);

            root->data = temp->data;
            
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }
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