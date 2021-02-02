/* C implementation QuickSort */
#include<stdio.h>

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element
	int j,temp;
	for (j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
		      
		       temp=arr[i];
		       arr[i]=arr[j];
		       arr[j]=temp;
		}
	}
       
		       temp=arr[i+1];
		       arr[i+1]=arr[high];
		       arr[high]=temp;
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
void main()
{     
	int n,i,a[50];
	clrscr();
	printf("enter no of elements in array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	 printf("enter array elements");
	 scanf("%d",&a[i]);
	}
	quickSort(a, 0, n-1);
	printf("Sorted array: \n");
	printArray(a, n);
	getch();

}