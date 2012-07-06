//quick sort
#include<stdio.h>
#include<conio.h>
long int partition(long int arr[],long int m,long int p);
void interchange(long int arr[],long int i,long int j);
void quicksort(long int arr[],long int p,long int q);

void interchange(long int arr[],long int i,long int j)
{
	long int temp;
	temp=arr[i];
	arr[i]=arr[j];
        arr[j]=temp;
}

void quicksort(long int arr[],long int p,long int q)
{
   long int j;
	if(p<q)
	{
		j=partition(arr,p,q+1);

		quicksort(arr,p,j-1);
		quicksort(arr,j+1,q);
	}
}

long int partition(long int arr[],long int m,long int p)
{
	long int v=arr[m];
	long int i=m;
	long int j=p;

	do
	{
		do
		{
       i++;
		}while(arr[i]<v);

		do
		{
       j--;
		}while(arr[j]>v);

		if(i<j)
      interchange(arr,i,j);
	}while(i<j);

	arr[m]=arr[j];
	arr[j]=v;
   return j;
}

void main()
{
	long int n=0,num[100],x;

  	printf("How many numbers: ");
  	scanf("%ld",&n);
  	printf("Give the numbers: ");

	for(x=1;x<=n;x++)
		scanf("%ld",&num[x]);

	quicksort(num,1,n);

	printf("\n\nThe sorted list is: ");
	for(x=1;x<=n;x++)
		printf("%ld ",num[x]);
      getch();
}