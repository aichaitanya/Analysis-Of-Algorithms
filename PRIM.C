/*
AIM:Prim's
Name:
Roll no:           
*/
#include<stdio.h>
#include<conio.h>
const int maxint=32767;
void readgraph(int adj[10][10],int e)
{
 int i,j,s,d;
 printf("Enter the cost of each edge of graph.....\n");
 for(i=1;i<=e;i++)
 {
  printf("Enter the source and desestination node:");
  scanf("%d%d",&s,&d);
  printf("Enter cost of edge :");
  scanf("%d",&adj[s][d]);
  adj[d][s]=adj[s][d];
 }
}
void primst(int adj[10][10],int visited[10],int n)
{
 int i,j,nd,min,ss,sd,x,y;
 int cost=0;
 visited[1]=1;
 nd=1;
 while(nd<n)
 {
  for(i=1,min=maxint;i<=n;i++)
   for(j=1;j<=n;j++)
    if(adj[i][j]<min)
     if(visited[i]!=0)
     {
      min=adj[i][j];
      x=ss=i;
      y=sd=j;
     }
     if(visited[ss]==0 || visited[sd]==0)
     {
      printf("Edge of MST %d:{%d-%d} and cost =%d\n",nd++,x,y,min);
      cost+=min;
      visited[y]=1;
     }
    adj[x][y]=adj[y][x]=maxint;
 }
 printf("Minimum cost of given Spanning Tree =%d",cost);
}
void main()
{
 int adj[10][10],visited[10],i,j,n,eg;
 clrscr();
 printf("Enter the total no. of nodes of graph:");
 scanf("%d",&n);

 for(i=1;i<=n;i++)
  visited[i]=0;

 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   adj[i][j]=maxint;

 printf("Enter total no. of edges of graph:");
 scanf("%d",&eg);

 readgraph(adj,eg);
 primst(adj,visited,n);
 getch();
}
/*OUTPUT:
Enter the total no. of nodes of graph:6
Enter total no. of edges of graph:8
Enter the cost of each edge of graph.....
Enter the source and desestination node:1 2
Enter cost of edge :5
Enter the source and desestination node:1 5
Enter cost of edge :9
Enter the source and desestination node:1 3
Enter cost of edge :8
Enter the source and desestination node:2 3
Enter cost of edge :3
Enter the source and desestination node:3 4
Enter cost of edge :7
Enter the source and desestination node:4 6
Enter cost of edge :2
Enter the source and desestination node:5 6
Enter cost of edge :1
Enter the source and desestination node:5 3
Enter cost of edge :4
Edge of MST 1:{1-2} and cost =5
Edge of MST 2:{2-3} and cost =3
Edge of MST 3:{3-5} and cost =4
Edge of MST 4:{5-6} and cost =1
Edge of MST 5:{6-4} and cost =2
Minimum cost of given Spanning Tree =15 */
