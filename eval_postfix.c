#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct snode {
    int data;
    struct snode* next;
};

void push(struct snode** top_ref, int data) {
    struct snode* new_node = (struct snode*)malloc(sizeof(struct snode));
    
    new_node->data = data;
    new_node->next = *top_ref;
    *top_ref = new_node;
}

char pop(struct snode** top_ref) {
    struct snode* temp = *top_ref;
    char popped = temp->data;
    
    *top_ref = temp->next;
    
    free(temp);
    
    return popped;
}

int evalpostfix(char exp[]) {
    struct snode* root = NULL;
    
    int i = 0;
    
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == ' ') {
            continue;
        }
        if(isdigit(exp[i])) {
            push(&root, exp[i] - '0');
        }
        else {
            int n2 = pop(&root);
            int n1 = pop(&root);
            
            switch(exp[i]) {
                case '+': push(&root,n1+n2); break;
                case '-': push(&root,n1-n2); break;
                case '*': push(&root,n1*n2); break;
                case '/': push(&root,n1/n2); break;
                case '%': push(&root,n1&n2); break;
                case '^': push(&root,pow(n2,n1)); break;
            }
        }
    }
    
    return pop(&root);
    
}

int main() {
    char exp[100];
    gets(exp);
    
    int result = evalpostfix(exp);
    printf("%d\n", result);
    
    return 0;
}














