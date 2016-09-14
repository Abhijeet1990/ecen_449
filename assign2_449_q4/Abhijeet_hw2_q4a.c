#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;
}


int sort_array(int *A, int L)
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

int merge(int *A,int *B,int A_size,int B_size,int *M)
{
int i;
int net_size=A_size+B_size;
for(i=0;i<A_size;i++)
	{
	M[i]=A[i];}
int j=0;

for(i=A_size;i<net_size;i++)
	{
	M[i]=B[j];
	j++;
	}


sort_array(M,net_size);

int k=0;
int temp;
for(i=0;i<net_size;i++)
	{
	if(M[i]==M[i+1])
		{
		temp=M[i];
		}
	else
		{
		M[k]=M[i];
		k++;
		}

	}

if(k==0)
{M[k]=M[i];
return k+1;}
else
return k;
}


int main()
{
int A[4]={1,3,9,20};
int B[4]={2,4,10,16};
int A_size=sizeof(A)/sizeof(int);
int B_size=sizeof(B)/sizeof(int);
int *X=malloc(sizeof(int)*(A_size+B_size));
int length,i;
length=merge(A,B,A_size,B_size,X);
printf("length of merged array is %d \n",length);
for(i=0;i<A_size+B_size;i++)
{printf("%d \n",X[i]);}

X=(int*)realloc(X,length);
for(i=0;i<length;i++)
{
printf("merged array element no %d is: %d \n",i+1,X[i]);
}
free(X);
return 0;
}
