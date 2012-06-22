#include<stdio.h>
#include<conio.h>
#define MAX 100

void make_choice(int n,double index[],double p[],double w[])
	{
   int i;
   	for(i=0;i<n;i++)
      	index[i]=p[i]/w[i];
	}

int choice(int n,double index[])
	{
   int i,max_index;
   double max=0.0;
   	for(i=0;i<n;i++)
      {
      	if(index[i]>max)
         {
         	max=index[i];
            max_index=i;
         }
      }
      index[max_index]=0.0;
      return max_index;
   }

void knapsack(double w[],double p[],double x[],double knap_w,int n)
	{
   int i;
   double weight,index[MAX];
		for(i=0;i<n;i++)
      	x[i]=0.0;
      weight=0.0;
      make_choice(n,index,p,w);
      while(weight<knap_w)
      {
      	i=choice(n,index);

         if((weight+w[i])<=knap_w)
         {
         	x[i]=1;
            weight=weight+w[i];
         }
         else
         {
         	x[i]=(knap_w-weight)/w[i];
            weight+=w[i]*x[i];
         }
      }
	}

void main()
	{
   int i,n;
   double w[MAX],p[MAX],x[MAX],optimal_profit,knap_w;
   	while(scanf("%d %lf",&n,&knap_w)==2)
      {
      	for(i=0;i<n;i++)
         scanf("%lf %lf",&w[i],&p[i]);

         knapsack(w,p,x,knap_w,n);
         optimal_profit=0.0;
         
         for(i=0;i<n;i++)
         	optimal_profit+=x[i]*p[i];
         printf("prof= %lf\n",optimal_profit);
      }
	}