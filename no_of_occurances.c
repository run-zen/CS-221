#include <stdio.h>

int findmax(int arr[],int n) {
     int max = arr[0];
     for (int i=0;i<n;i++) {
          if(arr[i] > max) {
               max = arr[i];
          }
     }

     return max;
}

void dropdup(int *p,int arr[],int n) {
     int i;
     for (i=0;i<n;i++)
          *(p+i) = 11;
     int flag = 0,key,pos = 0;
     for(i=0;i<n;i++){
          key =  arr[i];
          for(int j=0;j<n;j++) {
               if(key == *(p+j)) {
                    flag = 1;
                    break;
               }
          }
          if (flag == 0) {
               *(p+pos) = key;

               pos++;
          }
          flag = 0;
     }

}

int main() {
     int n;
     scanf("%d",&n);
     int arr[n];
     for(int i=0;i<n;i++) {
          scanf("%d", &arr[i]);
     }
     int max = findmax(arr,n);
     int list[max];
     for (int i=0;i<n;i++) {
          list[arr[i]] = 0;
     }

     for (int i=0;i<n;i++) {
          list[arr[i]] +=1;
     }
     int unique[n];
     dropdup(unique,arr,n);
     for(int i=0;i<n;i++) {
          if (unique[i] == 11) {
               break;
          }

          printf("%d - %d times\n", unique[i],list[unique[i]]);
     }

     return 0;
}
