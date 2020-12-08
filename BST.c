#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int key) {
     struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inOrder(struct node* node) {
     if(node != NULL) {
          inOrder(node->left);
          printf(" %d", node->key);
          inOrder(node->right);
     }
}

void preOrder(struct node* node) {
     if(node != NULL) {
          printf(" %d", node->key);
          preOrder(node->left);
          preOrder(node->right);
     }
}

void postOrder(struct node* node) {
     if(node != NULL) {
          postOrder(node->left);
          postOrder(node->right);
          printf(" %d", node->key);
     }
}


int main() {

     struct node* root = NULL;
     int value;
     int choice = 0;
     while(1) {
          printf("Enter your choice: ");
          scanf("%d", &choice);
          if(choice < 1 || choice >= 5)
               break;
          else {
               switch(choice) {
                    case 1: printf("Enter Data to Insert: ");
                              scanf("%d", &value);
                              if(root != NULL) {
                                   insert(root, value);
                              }
                              else {
                                   root = insert(root, value);
                              }
                              break;
                    case 2: if(root == NULL) {
                                   printf("Tree is Empty\n");
                              }
                              else {
                                   printf("Inorder:");
                                   inOrder(root);
                                   printf("\n");
                              }
                              break;
                    case 3:  if(root == NULL) {
                                   printf("Tree is Empty\n");
                              }
                              else {
                                   printf("Preorder:");
                                   preOrder(root);
                                   printf("\n");
                              }
                              break;
                    case 4: if(root == NULL) {
                                   printf("Tree is Empty");
                              }
                              else {
                                   printf("Postorder:");
                                   postOrder(root);
                                   printf("\n");
                              }
                              break;
               }
          }
     }

     return 0;
}
