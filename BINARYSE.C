#include<stdio.h>
#include<conio.h>

void readarray(int a[50],int n)
{
  int i;
  printf("\nEnter Elements : ");
  for(i=0;i<n;i++)
    {
     scanf("\n%d",&a[i]);
    }
}

void printarr(int a[50],int n){
   int i;
   printf("\nElements\n");
   for(i=0;i<n;i++)
    {
      printf("%d\t",a[i]);
    }
    printf("\n");
}

int binary(int a[100],int l,int h,int key){
  int mid;
  if(l<=h)
  {
      mid=(l+h)/2;
      if(key==a[mid])
	  return mid;
      else 
           if(a[mid]>key)
		return binary(a,l,mid-1,key);
	   else
		      return binary(a,mid+1,h,key);
    }
   return -1;
}

void bubblesort(int a[50],int n)
{
   int i,j,temp;
   for(i=1;i<n;i++)
   {
	for(j=0;j<n-i;j++)
	{
	     if(a[j]>a[j+1])
	     {
		temp = a[j];
		a[j] = a[j+1];
		a[j+1] = temp;
	     }
	 }
   }
}

void main() {
  int n,ch=1,a[100],key,b;
  clrscr();
  printf("\nEnter Size : ");
  scanf("%d",&n);
  readarray(a,n);
  bubblesort(a,n);
  printarr(a,n);

  while(ch){
     printf("\nEnter Search : ");
     scanf("%d",&key);
     b=binary(a,0,n-1,key);
     if(b!=-1)
       printf("\nKey Found");
     else printf("\nNot Found");
     printf("\nEnter Option : ");
     scanf("%d",&ch);
  }
  getch();

}
