#include <stdio.h>

int main()
{
     int n;
     scanf("%d",&n);
     int pattern[n][n];
     int count = 1;

     for (int i=0;i<n;i++)
     {
          if (i%2 == 0)
          {
               for (int j=0;j<n;j++)
               {
                    pattern[j][i] = count;
                    count++;
               }
          }
          else
          {
               for (int j =n-1;j>=0; j--)
               {
                    pattern[j][i] = count;
                    count++;
               }
          }
     }

     for (int i = 0; i<n;i++)
     {
          for (int j=0;j<n;j++)
          {
               printf("%d ", pattern[i][j]);
          }
          printf("\n");
     }

     return 0;
}
