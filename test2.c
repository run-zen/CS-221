#include<stdio.h>

void callcall(int* a) {
     printf("\nCallcall function :\n");
     printf("\n%d  %p\n", *a,a);
}

void call(int *a) {
     printf("\n Call function :\n");
     printf("\n %d %p\n", *a,a);
     callcall(a);
}

int main() {
     int a;
     scanf("%d", &a);
     printf("\nMain function :\n");
     printf("\n %d  %p\n", a,&a);

     call(&a);

     return 0;
}
