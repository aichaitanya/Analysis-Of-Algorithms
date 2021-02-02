#include<stdio.h>
#include<conio.h>

void Rmaxmin(int[],int,int,int*,int*);
  void main()
  {
  int i,n,A[50],max,min;
  clrscr();
  printf("Enter the num of elements : ");
  scanf("%d",&n);
  printf("Enter the elements.....\n");
  for(i=0;i<n;i++)
   scanf("%d",&A[i]);
  Rmaxmin(A,0,n-1,&max,&min);
  printf("MAximum element : %d\n",max);
  printf("Minimum element : %d",min);
  getch();

}

void Rmaxmin(int A[50],int low,int high,int *fmax,int *fmin)
{

  int mid ,hmax,hmin;
  if(low==high)
   *fmax=*fmin=A[low];
  else
  if(low==high-1)
   if(A[low]>A[high])
    {
      *fmax=A[low];
      *fmin=A[high];
    }
  else
   {
    *fmax=A[high];
    *fmin=A[low];
   }
   else
   {
     mid=(high+low)/2;
     Rmaxmin(A,low,mid,&hmax,&hmin);
     Rmaxmin(A,mid+1,high,fmax,fmin);
     *fmax=(hmax>*fmax)?hmax:*fmax;
     *fmin=(hmin<*fmin)?hmin:*fmin;
}
}



OUTPUT :

Enter the num of elements : 7
Enter the elements.....
56
234
90
-22
45                                                                              
11                                                                              
99                                                                              
MAximum element : 234                                                           
Minimum element : -22                                                           
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
