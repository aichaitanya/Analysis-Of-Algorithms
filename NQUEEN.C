#include<stdio.h>
#include<conio.h>

int place(int x[10],int k)
{
  int i=1,flag=1;
  while((i<=k-1)&&(flag))
  {
    if((x[i]==x[k])||(abs(x[i]-x[k]))==abs(i-k))
       flag=0;
    else
       i++;
  }
  return flag;
}

void main()
{
   int k,i,x[10],count,n;
   clrscr();
   printf("Enter the number ofqueens : ");
   scanf("%d",&n);
   printf("Solutions for %d no ofqueens are.....\n",n);
   count=0;
   k=1;
   x[k]=0;
   while(k>0)
   {
     x[k]++;
     while((x[k]<=n)&&(!place(x,k)))
	x[k]++;
     if(x[k]<=n)
     {
	if(k==n)
	{
	  count=count+1;
	  for(i=1;i<=n;i++)
	     printf("%d\t",x[i]);
	  printf("\n");
	  if(count % 5 == 0)
	     getch();
	}
	else
	{
	   k++;
	   x[k]=0;
	}
     }
     else
	k--;
   }
   printf("\nTotal no of solution = %d",count);
   getch();
 }

/*
OUTPUT :

Enter the number ofqueens : 5
Solutions for 5 no ofqueens are.....
1       3       5       2       4
1       4       2       5       3
2       4       1       3       5
2       5       3       1       4
3       1       4       2       5
3       5       2       4       1
4       1       3       5       2
4       2       5       3       1
5       2       4       1       3
5       3       1       4       2                                               
                                                                                
Total no of solution = 10                                                       
                                                                                
*/