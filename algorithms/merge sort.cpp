//Merge Sort
#include<stdio.h>
#include<conio.h>
void merge(int arr[],int l,int m,int h);

void merge_sort(int arr[],int l, int h)
{
   int mid,x;
	if(l<h)
	{
		mid=(l+h)/2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,h);
      printf("\n\nStep:  ");
      for(x=1;x<=5;x++)
  		printf("%d ",arr[x]);
		merge(arr,l,mid,h);
	}
}

void merge(int arr[],int l,int m,int h)
{
	int hi,i,j,k,b[100];
	hi=i=l;
	j=m+1;
	while(hi<=m && j<=h)
	{
		if(arr[hi]<=arr[j])
		{
			b[i]=arr[hi];
         hi++;
		}
		else
		{
			b[i]=arr[j];
         j++;
		}
		i++;
	}
	if(hi>m)
	{
		for(k=j;k<=h;k++)
		{
			b[i]=arr[k];
         i++;
		}
	}

	else
	{
		for(k=hi;k<=m;k++)
		{
			b[i]=arr[k];
         i++;
		}
	}

	for(k=l;k<=h;k++)
        	arr[k]=b[k];
}


void main()
{
	int num[100],x,n;

	printf("How many numbers: ");
	scanf("%d",&n);
	printf("Give the numbers: ");
	for(x=1;x<=n;x++)
		scanf("%d",&num[x]);

	merge_sort(num,1,n);

	printf("\n\nThe sorted list is: ");
	for(x=1;x<=n;x++)
		printf("%d ",num[x]);
      getch();
}