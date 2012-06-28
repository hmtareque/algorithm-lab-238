#include<stdio.h>
#include<conio.h>

int v,e,count,c[110][110],kount=0,nodes[110],EDGE[200][5],t[200][5];

int find_id(int s)
{
int i;
for(i=0;i<kount;i++)
 if(nodes[i]==s)
  return i;
  nodes[kount++]=s;
  return (kount-1);
}

float prim()
{
	float mincost,min=10000.0;
   int i,j,k,n[110],l,index;
   for(i=0;i<v;i++)
   	for(j=0;j<v;j++)
      	if(c[i][j]<min)
         {
         	min=c[i][j];
            k=i;
            l=j;
         }
         t[0][0]=k;
         t[0][1]=l;
         for(i=0;i<v;i++)
         	if(c[i][l]<c[i][k])
            	n[i]=l;
            else
            	n[i]=k;
            n[k]=0;
            n[l]=0;

            for(i=1;i<v-1;i++)
            {
            min=10000;
            	for(j=0;j<v;j++)
               	if(n[j]!=0)
                 		if(c[j][n[j]]<min)
                     {
                    		min=c[j][n[j]];
							index=j;
                     }
               t[i][0]=index;
               t[i][1]=n[index];
               min=min+c[index][n[index]];
               n[index]=0;
               for(k=0;k<v;k++)
               	if(n[k]!=0&&c[k][n[k]]>c[k][index])
                  	n[k]=index;


            }
            return min;
}
void main()
	{
   freopen("prim.in","rt",stdin);
   //freopen("prim.out","wt",stdout);
   int i,j,EDGE[200][5],x,y,cost[110];
   float mincost=0.0;
   	printf("Enter how many node and edge:");
      scanf("%d %d",&v,&e);
      for(i=0;i<=v;i++)
      	for(j=0;j<=v;j++)
         	c[i][j]=-1;
      for(i=0;i<e;i++)
      	{
         	scanf("%d %d %f",&EDGE[i][0],&EDGE[i][1],&cost[i]);
            x=find_id(EDGE[i][0]);
            y=find_id(EDGE[i][1]);
            c[x][y]=cost[i];
            c[y][x]=cost[i];
         }
     mincost=prim();
     printf("\nMin cost %f\n",mincost);
     //getch();
   }