#include <stdio.h>
#include <stdlib.h>

struct node {
     int data;
     struct node* next;
};

//inserting at the end
void pushEnd(struct node** head_ref,int new_data) {

     struct node* new_node= (struct node*)malloc(sizeof(struct node));

     new_node->data = new_data;

     new_node->next = NULL;
     struct node* last = *head_ref;
     if (*head_ref == NULL){
          *head_ref = new_node;
     }
     else {
          while(last->next != NULL) {
               last = last->next;
          }
          last->next = new_node;
     }
     return;
}

//to print the list
void printlist(struct node* node) {
     if(node == NULL) {
          printf("List is Empty");
     }
     else {
          while(node != NULL) {
               printf("%d ", node->data);
               node = node->next;
          }
     }
     printf("\n");

     return;
}

void ShowReverse(struct node* head,int len) {
     if(head == NULL) {
          printf("List is Empty");
     }
     else {
          int arr[len];
          int i=0;
          while(head != NULL) {
               arr[i] = head->data;
               i++;
               head = head->next;
          }
          printf("Reverse List of Elements: ");
          for(i=len-1;i>=0;i--) {
               printf("%d ", arr[i]);
          }
     }
     printf("\n");

}

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertionSort(struct node **head_ref)
{
    struct node *sorted = NULL;

    struct node *current = *head_ref;
    while (current != NULL)
    {
        struct node *next = current->next;

        sortedInsert(&sorted, current);

        current = next;
    }

    *head_ref = sorted;
}

int main() {

     struct node* head = NULL;
     int len = 0;
     int value;
     int choice;
     while(1)
     {
          printf("Enter your choice: ");
          scanf("%d",&choice);
          if(choice >=1 && choice <= 4) {
               switch(choice)
               {
                    case 1:printf("Enter Data to Insert: ");
                           scanf("%d", &value);
                           pushEnd(&head,value);
                           len++;
                           break;

                    case 2:if(head!=NULL)
                              printf("List of Elements: ");
                           printlist(head);
                           break;

                    case 3:ShowReverse(head,len);
                           break;

                    case 4:insertionSort(&head);
                           printf("Sorted List of Elements: ");
                           printlist(head);
                           break;
               }
          }
          else {
               break;
          }
     }


     return 0;
}
