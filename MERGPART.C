#include<stdio.h>

void merge(int array[50],int  low,int  mid,int high )
{
	int temp[50];
	int i = low;
	int j = mid +1 ;
	int k = low ;

	while( (i <= mid) && (j <=high) )
	{
		if(array[i] <= array[j])
			temp[k++] = array[i++] ;
		else
			temp[k++] = array[j++] ;
	}
	while( i <= mid )
		temp[k++]=array[i++];
	while( j <= high )
		temp[k++]=array[j++];
	for(i= low; i <= high ; i++)
		array[i]=temp[i];
}

void merge_sort(int a[50], int low, int high )
{
	int mid;
	if( low < high )
	{
		mid = (low+high)/2;
		merge_sort(a, low , mid );
		merge_sort(a, mid+1, high );
		merge(a, low, mid, high );
	}
}

void main()
{
	int i,n,a[50];
	clrscr();
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}

	printf("Unsorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", a[i]);

	merge_sort(a, 0, n-1);

	printf("\nSorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", a[i]);
	printf("\n");
	getch();

}