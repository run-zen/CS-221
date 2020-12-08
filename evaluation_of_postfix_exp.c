#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct snode {
     int data;
     struct snode* next;
};

void push(struct snode** top_ref, char data) {
     struct snode* new_node = (struct snode*)malloc(sizeof(struct snode));

     new_node->data = data;
     new_node->next = *top_ref;

     *top_ref = new_node;
}

char pop(struct snode** top_ref) {
     if (*top_ref == NULL) {
          printf("\nStack Underflow: cannot be popped");
          getchar();
          exit(1);
     }
     struct snode* temp = *top_ref;
     char popped = temp->data;
     *top_ref = temp->next;
     free(temp);

     return popped;
}

int evalPostfixExp(char exp[]) {

     struct snode* root = NULL;

     int i;

     for(int i=0; exp[i] != '\0'; i++) {
          if(isdigit(exp[i])) {
               push(&root, exp[i]-'0');
          }
          else {
               int n1 = pop(&root);
               int n2 = pop(&root);
               switch(exp[i]) {
                    case '+' : push(&root,n2+n1); break;
                    case '-' : push(&root,n2-n1); break;
                    case '*' : push(&root,n2*n1); break;
                    case '/' : push(&root,n2/n1); break;
                    case '%' : push(&root,n2%n1); break;
                    case '^' : push(&root,pow(n1,n2)); break;
               }
          }
     }
     return pop(&root);

}

int main() {
     char exp[100];
     printf("\nEnter the expression : ");
     gets(exp);
     int result = evalPostfixExp(exp);

     printf("%d", result);

     return 0;
}
