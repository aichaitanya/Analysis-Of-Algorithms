
#include<stdio.h>
#include<conio.h>
  
void readarray(int a[50],int n)
  {
    int i;
    printf("\nEnter elements of an array.....\n");
    for(i=0;i<n;i++)
    {
      printf("enter value a[%d] = ",i);
      scanf("%d",&a[i]);
    }
  }
  
void printarray(int a[50],int n)
  {
     int i;
     for(i=0;i<n;i++)
     printf("a[%d] = %d\n",i,a[i]);
     printf("\n");
  }
  
void insertionsort(int a[50],int n)
  {
    int i,j,key;
    for(i=1;i<n;i++)
    {
      key = a[i];
      for(j = i-1; (j >= 0)&& (a[j] > key); j--)
      {
	 a[j+1] = a[j];
      }
      a[j+1] = key;
   }
  }
  
void main()
  {
   int x[50],n;
   clrscr();
   printf(" * * * * * INSERTION SORT * * * * * \n\n");
   printf("Enter no. of elements to be sorted : ");
   scanf("%d",&n);
   readarray(x,n);
   insertionsort(x,n);
   printf("Sorted elements using insertion sort.....\n");
   printarray(x,n);
   getch();
  }

/*..............OUTPUT.............
 * * * * * INSERTION SORT * * * * *
Enter no. of elements to be sorted : 6
Enter elements of an array.....
enter value a[0] = 2
enter value a[1] = 3
enter value a[2] = 6
enter value a[3] = 7
enter value a[4] = 9
enter value a[5] = 1
Sorted elements using insertion sort.....
a[0] = 1
a[1] = 2
a[2] = 3
a[3] = 6
a[4] = 7
a[5] = 9
*/