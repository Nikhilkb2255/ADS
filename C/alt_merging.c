#include<stdio.h>  
  
#define N 5  
#define M (N * 2)  
  
void main()  
{  
    int a[N], b[N], c[M], i, k;  
  
    printf("Enter %d elements for 1st array", N);  
    for(i = 0; i < N; i++)  
        scanf("%d", &a[i]);  
  
    printf("Enter %d elements for 2nd array", N);  
    for(i = 0; i < N; i++)  
        scanf("%d", &b[i]);  
  
    printf("\nAfter merging arrays a & b in alternate position\n");  
    for(i = 0, k = 0; i < N; i++, k += 2)  
        c[k] = a[i];  
  
    for(i = 0, k = 1; i < N; i++, k += 2)  
        c[k] = b[i];  
  
    printf("Array elements of c is:\n");  
    for(i = 0; i < M; i++)  
    
        printf("%d\n", c[i]);  

}  
