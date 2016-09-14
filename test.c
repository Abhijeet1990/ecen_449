#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 

struct coordinate{
int x;
int y;
};

float dist (struct coordinate A, struct coordinate B)
{return (pow((pow(A.x-B.x,2)+pow(A.y-B.y,2)),0.5));
    //return ((A.x-B.x)+(A.y-B.y));

}

 

int max (int A[],int num_element)
{
int max=0,i;
for(i=0;i<num_element;i++)
{
	if(A[i]>max)
	{max=A[i];}

}
return max;
}

 

int main()
{  

    int maximum;
    struct coordinate A[4];
    int m=0,j,k,l,i;

    //int *C=malloc(16,sizeof(int));
    int num[4]={0,0,0,0};
    struct coordinate B[16];
    float distance;

    printf("enter the co-ordinates \n");

    for(i=0;i<4;i++)

    {  

        printf("enter %dth coordinate \n",i);

        scanf("%d",&A[i].x);

        scanf("%d",&A[i].y);

    }

    for(j=0;j<4;j++)
    {
	for(i=j+1;i<4;i++)
            {  
		
                distance=dist(A[j],A[i]);
		
                if(distance<10.0)

                {printf("%d %d \n",i,j);
		B[m].x=j;

                 B[m].y=i;
		 m++;
                }

            

            }

    }
printf("m=%d \n",m);

for(i=0;i<m;i++)
{printf("%d %d \n",B[i].x,B[i].y);
}

    //C=(int*)realloc(C,2*m);

    int C[2*m];

    for(k=0,l=0;k<m;k++)

    {

        C[l]=B[k].x;

        C[l+1]=B[k].y;
	l=l+2;

    }

   for(i=0;i<2*m;i++)
{printf("%d \n",C[i]);}

    for(j=0;j<4;j++)

    {

        for(i=0;i<2*m;i++)

        {

            if(C[i]==j)

            num[j]++;

        }

    }

/*for(i=0;i<4;i++)
{printf("%d",num[i]);}*/   

    maximum=max(num,4);

    printf("best node least distance=%d",maximum);

    return 0;

}
