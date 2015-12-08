/* to find largest contiguous sum sub-array from given array*/
#include<stdio.h>
int Largest_Sum(int a[], int n, int *begin)
{
	int max = 0, end = 0,i,sum=0,count=0,min,m=0;
	for (i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			if (count == 0)
			{
				min = i;
				count = 1;
			}
			sum = sum + a[i];
			if (sum>max)
			{
				*begin = min;
				max = sum;
				m = 1;
			}
		}
		else
		{
			sum = 0;
			count = 0;
			min = 0;
			if (m == 1)
			{
				end = i - 1;
				m = 0;
			}
		}
	}
	if (m == 1)
		end = i - 1;
	return end;
}
int main()
{
	int a[100], n,i,begin=0,end=0;
	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("INVALID INPUT:\n");
		return 1;
	}
	printf("enter the elements in the array to find largest contiguous sum sub-array:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	end=Largest_Sum(a, n, &begin);
	printf("the largest contiguous sum sub-array is:\n");
	for (begin; begin <= end; begin++)
	{
		printf("%d\t", a[begin]);
	}
	return 0;
}