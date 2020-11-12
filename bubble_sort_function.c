#include<stdio.h>


void swap(int *x, int* y) {
     int temp = *x;
     *x = *y;
     *y = temp;
     return;
}

void bubbleSort(int *arr, int n) {
     int i,j;
     for (i=0;i<n-1;i++)
     {
          for(j=0;j<n-i-1;j++)
          {
               if(*(arr+j) > *(arr+j+1)) {
                    swap((arr+j+1),(arr+j));
               }
          }
     }
}

void printarr(int arr[],int n) {
     int i;
     printf("\n");
     for (int i=0;i<n;i++) {
          printf("%d  ", arr[i]);
     }
     return;
}

int main () {
     int n;
     scanf("%d", &n);
     int arr[n];
     for(int i=0;i<n;i++) {
          scanf("%d", &arr[i]);
     }

     bubbleSort(arr,n);
     printarr(arr,n);

     return 0;
}
