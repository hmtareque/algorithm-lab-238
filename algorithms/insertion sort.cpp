// insertion sort
#include<stdio.h>
#include<conio.h>
void main()
{
	int a[100],n,i,j,temp,k,s=1;

  	printf("How many numbers: ");
 	scanf("%d",&n);
   printf("\nGive the numbers: ");

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(j=1;j<n;j++)
	  {
		k=a[j];
		i=j-1;
		while(k<a[i])
		  {
			a[i+1]=a[i];
         i--;
		  }
      a[i+1]=k;

      printf("\n\nStep %d: ",s);
      s++;
      for(i=0;i<n;i++)
		printf(" %d",a[i]);
	   }

 	printf("\n\nThe sorted list is: ");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
      getch();
}