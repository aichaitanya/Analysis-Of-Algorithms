#include<stdio.h>
#include<conio.h>
#define maxint 999

void djkstra(int n,int v,int cost[10][10],int dist[])
{
   int i,u,count,w,flag[10],min;
   for(i=1;i<=n;i++)
       flag[i]=0;
       dist[i]=cost[v][i];
   count=2;
   while(count<=n)
   {
     min=999;
     for(w=1;w<=n;w++)
	   if(dist[w]<min && !flag[w])
	   {
		 min=dist[w];
		 u=w;
	   }
     flag[u]=1;
     count++;
     for(w=1;w<=n;w++)
	if(((dist[u]+cost[u][w])<dist[w])&& !flag[w])
	   dist[w]=dist[u]+cost[u][w];
   }
}

void readgraph(int cost[10][10],int edge){
 int i,s,d;
 for(i=1;i<=edge;i++){
     printf("Enter the source and destination nodes of edge %d : ",i);
     scanf("%d%d",&s,&d);
     printf("Enter the weight of edge : ");
     scanf("%d",&cost[s][d]);
     cost[d][s]=cost[s][d];
 }
}

void main()
{
  int n,v,i,j,cost[10][10],dist[10],edge;
  clrscr();
  printf("Enter the number of nodes : ");
  scanf("%d",&n);
  printf("Enter the number of edges : ");
  scanf("%d",&edge);

  for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
      cost[i][j]=maxint;

  printf("\nEnter weight of edges.....\n");
  readgraph(cost,edge);

  printf("\nEnter the source node : ");
  scanf("%d",&v);

  djkstra(n,v,cost,dist);

  printf("\nShortest Path.....\n");
  for(i=1;i<=n;i++)
     if(i!=v)
	printf("%d -> %d and cost = %d\n",v,i,dist[i]);

  getch();
}
/*
OUTPUT :

Enter the number of nodes : 6
Enter the number of edges : 9

Enter weight of edges.....
Enter the source and destination nodes of edge 1 : 1 2
Enter the weight of edge : 7
Enter the source and destination nodes of edge 2 : 1 6
Enter the weight of edge : 3
Enter the source and destination nodes of edge 3 : 2 3
Enter the weight of edge : 4
Enter the source and destination nodes of edge 4 : 2 6
Enter the weight of edge : 2
Enter the source and destination nodes of edge 5 : 3 4
Enter the weight of edge : 8
Enter the source and destination nodes of edge 6 : 3 5
Enter the weight of edge : 5
Enter the source and destination nodes of edge 7 : 3 6
Enter the weight of edge : 5
Enter the source and destination nodes of edge 8 : 4 5
Enter the weight of edge : 3
Enter the source and destination nodes of edge 9 : 5 6
Enter the weight of edge : 6

Enter the source node : 1

Shortest Path.....
1 -> 2 and cost = 5
1 -> 3 and cost = 8
1 -> 4 and cost = 12
1 -> 5 and cost = 9
1 -> 6 and cost = 3
*/