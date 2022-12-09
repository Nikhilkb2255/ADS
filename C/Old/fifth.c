#include<stdio.h>
void f1();
int a=5,b=10,c;
void main()
{
c=a+b;
f1();
}
void f1()
{
printf("This is my 1st function");
printf(" The sum is %d",c);
}
