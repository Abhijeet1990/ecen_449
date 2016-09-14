#include"Abhijeet_HW2_Q3_Prime.h"
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
