#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n],k;
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    int pos = -1;
    for (int i=0;i< n;i++) {
        if(arr[i] == k) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        printf("Element Found at position %d",pos);
    }
    else {
        printf("Element Not Found");
    }
    
    return 0;
}