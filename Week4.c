#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int arr[MAX];
int indexx = 0;
int n = 0;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    arr[n++] = root->data;
    inorder(root->right);
}

void postorderFill(struct Node* root) {
    if (root == NULL)
        return;

    postorderFill(root->left);
    postorderFill(root->right);

    root->data = arr[indexx++];
}

void convertBSTtoMaxHeap(struct Node* root) {
    n = 0;
    indexx = 0;

    inorder(root);
    postorderFill(root);
}

void printPreorder(struct Node* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {

    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    convertBSTtoMaxHeap(root);

    printf("Preorder traversal of Special Max Heap:\n");
    printPreorder(root);

    return 0;
}
