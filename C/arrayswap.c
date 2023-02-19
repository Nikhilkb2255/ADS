#include<stdio.h>
void main()
{
	int a[5],b[5],n,i,t;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter elements into array1: ");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	printf("Enter elements into array2: ");
	for(i=0;i<n;++i)
		scanf("%d",&b[i]);
	printf("\nArray1: ");
	for(i=0;i<n;++i)
		printf("%d\t",a[i]);
	printf("\nArray2: ");
	for(i=0;i<n;++i)
		printf("%d\t",b[i]);
	for(i=0;i<n;++i)
	{
		t=a[i];
		a[i]=b[i];
		b[i]=t;
	}
	printf("\nAfter Swapping:-\n\tArray1: ");
	for(i=0;i<n;++i)
		printf("%d\t",a[i]);
	printf("\n\tArray2: ");
	for(i=0;i<n;++i)
		printf("%d\t",b[i]);
}