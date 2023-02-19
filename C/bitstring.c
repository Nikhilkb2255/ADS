#include<stdio.h>
void main(){
 int a[10],i,n;
 char s[10];
 printf("Enter number of elements in array:");
 scanf("%d",&n);
 printf("Enter elements:");
 for(i=0;i<n;++i)
	scanf("%d",&a[i]);
 printf("Enter bitstring:");
 scanf("%s",s);
 printf("Array:");
 for(i=0;i<n;++i)
	printf("%d ",a[i]);
 printf("\nSet: ");
 for(i=0;i<n;++i)
	if(s[i]=='1')
		printf("%d\t",a[i]);

}