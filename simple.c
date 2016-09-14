#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,n;
printf("enter the array size \n");
scanf("%d",&n);
int *A=malloc(sizeof(int)*(n));
for(i=0;i<n;i++)
{scanf("%d",&A[i]);
printf("%d \n",A[i]);}


}
