#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//this structure stores the x and y coordinate of the points in the text file
struct coordinate{
int x;
int y;
};

//function for swapping two elements
void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;
}

//sorted the array based on the x coordinates 
void sort_array(int *A, int L)
{
int c,i;
for(c=0;c<L-1;c=c+2)
	{
	for(i=0;i<L-c-1;i=i+2)
		{
		if(A[i]>A[i+2])
		 {swap(&A[i],&A[i+2]);
		  swap(&A[i+1],&A[i+3]);
		 }
		}
	}
}
//minimizes the array if the distance between the sorted array points is less than 10 (for both x coordinate & y coordinate)
int minimize_array(int *A, int L)
{  int i,m=0,count=0;
   printf("start minimizing \n");
    for(i=2;i<L-3;i=i+2)
	{//compares if the abs distance of x component with previous and next point is less than 10 or 
		// if the abs distance of y component with previous and next point is less than 10
		// in both the cases it continues else it add the points to the new minimized array
	if(((abs(A[i+2]-A[i])>=10) && (abs(A[i]-A[i-2])>=10))||((abs(A[i+3]-A[i+1])>=10) && (abs(A[i+1]-A[i-1])>=10)))
		{continue;}
	else
		{count++;
		A[m+2]=A[i];
		A[m+3]=A[i+1];
		m=m+2;}
	}
printf("count of minimized array: %d \n",count);
//returns the size of the array
return m+1;
}
//dist() function calculates the distance between two coordinate
float dist (struct coordinate A, struct coordinate B)
{
	return (pow((pow(A.x-B.x,2)+pow(A.y-B.y,2)),0.5));
}

//max() calculates the maximum of all the elements in an array..nodes with the maximum number of less than 10 euclidean distance
int max (int A[],int num_element)
{
int max=0,i,k;
for(i=0;i<num_element;i++)
{
	if(A[i]>max)
	{max=A[i];
	k=i;}
}
printf("node with maximum number of euclidean distance less than 10=%d \n",max);
return k;
}

 
int main()
{  

    int maximum;
    int x=50000;
    struct coordinate A[x];
    int m=0,j,k,l,h=0,t,z;
    int nums[2*x];
    float distance;
    FILE *f;
    f=fopen("points.txt","r");
    int i=0;
    while(fscanf(f, "%d,", &nums[i])!=EOF) {         
        i++;
    }
    fclose(f); 

//lets sort the array of structure
sort_array(nums,2*x);
//lets minimize the array
t=minimize_array(nums,2*x);
//displays the coordinate of the sorted and minimized array
for(i=0;i<t;i=i+2)
{printf("x:%d and y:%d \n",nums[i],nums[i+1]);}
   
printf("minimized array size: %d \n",t);
    
for(i=0;i<t;i=i+2)

    {  
	A[h].x=nums[i];
	A[h].y=nums[i+1];
	h++;
    }
z=(t+1)/2;   
for(j=0;j<z;j++)
    {
	for(i=j+1;i<z;i++)
            {  
		distance=dist(A[j],A[i]);
		if(distance<10.0){
		 m++;
                }
            }
     }
// a new array of structure, B stores the minimized array
struct coordinate B[m];
m=0;
for(j=0;j<z;j++)
    {
	for(i=j+1;i<z;i++)
            {  
		distance=dist(A[j],A[i]);
		if(distance<10.0){
		B[m].x=j;
		B[m].y=i;
		m++;
                }
            }
     }
// array that holds all the x component and y component as separate element
//B =((1,2),(7,9),(5,97)) converts to C =(1,2,7,9,5,97)
int C[2*m];
for(k=0,l=0;k<m;k++)
    {
        C[l]=B[k].x;
        C[l+1]=B[k].y;
	l=l+2;
    }
//num array stores the count of the unique element in the C array
int num[z];
for(i=0;i<z;i++)
{num[i]=0;}
for(j=0;j<z;j++)
    {
	for(i=0;i<2*m;i++)
	{
	    if(C[i]==j)
	    num[j]++;
        }
    }
//displaying the num array
for(i=0;i<z;i++)
{printf("%d \n",num[i]);}
maximum=max(num,z);
printf("the coordinate of the node with highest number of closest point is %d and %d",A[maximum].x,A[maximum].y);
return 0;
}
