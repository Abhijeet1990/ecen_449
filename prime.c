#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;
}


void sort_array(int *A, int L)
{
int c,i;
for(c=0;c<L-1;c++)
	{
	for(i=0;i<L-c-1;i++)
		{
		if(A[i]>A[i+1])
		 {swap(&A[i],&A[i+1]);}
		}
	}

}

int prime(int *B,int M)
{
int i,j,count=0,k=0;

for(i=0;i<M;i++)
	{
	for(j=1;j<=B[i];j++)
		{
		if(B[i]%j==0)
			{count++;}
		}
	if(count==2)
	{B[k]=B[i];
	k++;}
	count=0;

	}
return k;
}

int main()
{int i,n;
printf("enter the array size \n");
scanf("%d \n",&n);
int *A=malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{scanf("%d \n",&A[i]);}
sort_array(A,n);
for(i=0;i<n;i++)
{printf("sorted list element %d \n",A[i]);
}
int l=prime(A,n);
A=(int*)realloc(A,l);
for(i=0;i<l;i++)
{printf("prime list element %d \n",A[i]);
}
}

