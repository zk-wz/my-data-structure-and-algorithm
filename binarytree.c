#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

// def the node structure
typedef struct node {
    char data;
    struct node *parent;
    struct node *left;
    struct node *right;
} bitree;

// create bitree
// get the node end with #, and the @ is an empty node
bitree *create_bitree(){
    // initailize the variations
    char ch;
    bitree *root, *s;
    root = NULL;
    int front, rear;
    front = 1;rear = 0;
    bitree *queue[maxsize];

    // get the data
    while((ch = getchar()) != '#'){
        s = NULL;
        if(ch != '@'){
            s = (bitree *)malloc(sizeof(bitree));
            s->data = ch;
            s->left = NULL;
            s->right = NULL;
        }
        rear++;
        queue[rear] = s;
        if(!root){
            root = s;
        }
        else{
            if(s && queue[front]){
                if(rear % 2 == 0){
                    queue[front]->left = s;
                }
                else{
                    queue[front]->right = s;
                }
            }
            if(rear % 2 == 1){
                front++;
            }
        }
    }
    return root;
}

// preorder traverse
void preorder(bitree *root){
    if(root){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// inorder traverse
void inorder(bitree *root){
    if(root){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

// postorder traverse
void postorder(bitree *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

// exchange all the left and right child
void exchange(bitree *root){
    if(root){
        bitree *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        exchange(root->left);
        exchange(root->right);
    }
}

// breadth first traverse
void breadth_first(bitree *root){
    int front, rear;
    front = 1;rear = 0;
    bitree *queue[maxsize];
    bitree *p;
    if(root){
        rear++;
        queue[rear] = root;
        while(front <= rear){
            p = queue[front];
            front++;
            printf("%c", p->data);
            if(p->left){
                rear++;
                queue[rear] = p->left;
            }
            if(p->right){
                rear++;
                queue[rear] = p->right;
            }
        }
    }
}

// get the total number of nodes
int get_num(bitree *root){
    if(root){
        return get_num(root->left) + get_num(root->right) + 1;
    }
    else{
        return 0;
    }
}

// get the depth of the tree
int get_depth(bitree *root){
    int depth = 0;
    if(root){
        int left_depth = get_depth(root->left);
        int right_depth = get_depth(root->right);
        depth = left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
    return depth;
}

// main function
int main(){
    bitree *root;
    printf("Please input the binary tree: ");
    root = create_bitree();
    printf("preorder: ");
    preorder(root);
    printf("\ninorder: ");
    inorder(root);
    printf("\npostorder: ");
    postorder(root);
    printf("\nbreadth first: ");
    breadth_first(root);
    printf("\nthe number of nodes: %d", get_num(root));
    printf("\nthe depth of the tree: %d", get_depth(root));
    return 0;
}