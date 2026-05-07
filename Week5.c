#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* stack1[MAX];
struct Node* stack2[MAX];
int top1 = -1;
int top2 = -1;

void push1(struct Node* node){
    stack1[++top1] = node;
}

void push2(struct Node* node){
    stack2[++top2] = node;
}

struct Node* pop1(){
    return stack1[top1--];
}

struct Node* pop2(){
    return stack2[top2--];
}

int isEmpty1(){
    return top1 == -1;
}

int isEmpty2(){
    return top2 == -1;
}

void zigzagTraversal(struct Node* root){

    if(root == NULL)
        return;

    push1(root);

    while(!isEmpty1() || !isEmpty2()){

        while(!isEmpty1()){
            struct Node* node = pop1();
            printf("%d ", node->data);

            if(node->left)
                push2(node->left);

            if(node->right)
                push2(node->right);
        }

        while(!isEmpty2()){
            struct Node* node = pop2();
            printf("%d ", node->data);

            if(node->right)
                push1(node->right);

            if(node->left)
                push1(node->left);
        }
    }
}

int main(){

    struct Node* root = createNode(37);
    root->left = createNode(15);
    root->right = createNode(63);
    root->left->left = createNode(9);
    root->left->right = createNode(28);
    root->right->right = createNode(74);
    root->left->left->left = createNode(3);
    root->left->left->right = createNode(12);

    printf("Zigzag Traversal: ");
    zigzagTraversal(root);

    return 0;
}
