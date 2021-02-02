#include<stdio.h>
#include<conio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
   float x[20],tp;
   int i,j,rcap;

   tp = 0;
   rcap = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++)
   {
      if (weight[i] > rcap)
	 break;
      else
      {
	 x[i] = 1.0;
	 tp = tp + profit[i];
	 rcap = rcap - weight[i];
      }
   }

   if (i < n)
      x[i] = rcap / weight[i];

   tp = tp + (x[i] * profit[i]);

   printf("\nThe result vector is = {");
   for (i=0; i<n-1; i++)
      printf("%0.2f, ",x[i]);
   printf("%0.2f}\n",x[i]);
   printf("\nMaximum profit is = %0.3f",tp);

}

void main()
{
   float weight[20], profit[20], ratio[20], capacity;
   int num,i,j;
   float temp;

   clrscr();
   printf("Enter the no. of items : ");
   scanf("%d",&num);
   printf("\nEnter the capacity of knapsack : ");
   scanf("%f",&capacity);

   printf("\nEnter the wights and profits of each object.....\n");
   for (i = 0; i < num; i++)
   {
      printf("Item no. %d : ",i+1);
      scanf("%f%f",&weight[i],&profit[i]);
   }

   for (i = 0; i < num; i++)
      ratio[i] = profit[i] / weight[i];

   for (i = 1; i < num; i++)
      for (j = 0; j < num-i; j++)
	 if (ratio[j] < ratio[j+1])
	 {
	    temp = ratio[j];
	    ratio[j] = ratio[j+1];
	    ratio[j+1] = temp;

	    temp = weight[j];
	    weight[j] = weight[j+1];
	    weight[j+1] = temp;

	    temp = profit[j];
	    profit[j] = profit[j+1];
	    profit[j+1] = temp;
	 }

   knapsack(num, weight, profit, capacity);
   getch();
}

/*
OUTPUT :

Enter the no. of items : 7

Enter the capacity of knapsack : 15

Enter the wights and profits of each object.....
Item no. 1 : 2 10
Item no. 2 : 3 5
Item no. 3 : 5 15
Item no. 4 : 7 7
Item no. 5 : 1 6
Item no. 6 : 4 18
Item no. 7 : 1 3

The result vector is = {1.00, 1.00, 1.00, 1.00, 1.00, 0.67, 0.00}

Maximum profit is = 55.333


*/






                                                                                
