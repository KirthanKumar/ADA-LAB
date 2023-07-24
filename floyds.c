#include <stdio.h>
#include <stdlib.h>

int a[10][10],d[10][10],n;

int min(int a, int b)
{
  if(a<b)
  return a;
  else 
  return b;
}

void path()
{
  int i,j,k;
  for(k=0; k<n; k++){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++)
      {
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
}

int main()
{
  int i,j;
  printf("\nEnter n number of vertices: ");
  scanf("%d",&n);
  printf("\nEnter the weighted matrix: \n");
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    {
      scanf("%d",&a[i][j]);
      d[i][j] = a[i][j];
    }
    path();
    printf("\n The final distance matrix is : \n");
  for(i=0; i<n; i++)
    {
    for(j=0; j<n; j++)
    {
      printf("%5d",d[i][j]);
    }
    printf("\n");
  }
}

/*
Enter n number of vertices: 
5

Enter the cost matrix: 
0   2   99  1   8
6   0   3   2   99
99  99  0   4   99  
99  99  2   0   3
3   99  99  99  0

The final distance matrix is : 
0    2    3    1    4
6    0    3    2    5
10   12    0    4    7
6    8    2    0    3
3    5    6    4    0
*/
