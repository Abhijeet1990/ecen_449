#include <stdio.h>

struct coordinate{
int x;
int y;
}; 
  
int main(void)
{
    struct coordinate A[50000];
    int num[100000];
    int i = 0,j=0,h=0;
    FILE * fp;
 
    if (fp = fopen("points.txt", "r")) {
        while (fscanf(fp, "%d,", &num[i]) != EOF) {
              
		++i;
		
        }
        fclose(fp);
    }
    for(i=0;i<100000;i++)
	printf("%d\n",num[i]);
 
    for (i=0; i < 100000;i=i+2)
{	A[h].x=num[i];
	A[h].y=num[i+1];
	printf("%d: x and y = %d  %d\n",h,A[h].x,A[h].y);
	
 }
    return 0;
}
