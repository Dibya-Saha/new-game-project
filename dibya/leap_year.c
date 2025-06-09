#include <stdio.h>
int main()
{ int a;
    printf("year:");
scanf("%d",&a);
if ((a%4==0&&a%100!=0)||a%400==0)
printf("leap year\n");
else 
printf("Not leap year\n");



}