#include"Abhijeet_HW2_Q3_swap.h"
#include"Abhijeet_HW2_Q3_sort.h"

void sort_array(int *A, int L)
{
int c,i;
for(c=0;c<L-1;c++)
	{
	for(i=0;i<L-c-1;i++)
		{
		if(A[i]>A[i+1])
		 {swap(&A[i],&A[i+1]); 
			}
		}
	}

}

