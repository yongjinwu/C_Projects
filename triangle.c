#include <stdio.h>
int main() 
{
    
int initialNum;

printf("Enter a number: ");
    scanf("%d", &initialNum);
int initialNumCopy=initialNum;

int lower=initialNumCopy-1;
int upper=initialNumCopy+1;

if (initialNumCopy==1)
{printf("*");
printf("\n");}
else
{
int i=1;

while(i!=initialNumCopy)
{
    
    printf(" ");
  i=i+1;  
    
}
   printf("*");
   printf("\n");
   initialNumCopy=initialNumCopy-1;
   while(initialNumCopy!=1)
   {
       int j;
       for (j=0;j<lower-1;j++)
       {
           printf(" ");
       }
       printf("*");
       int k;
       for (k=0;k<upper-lower-1;k++)
       {
           
           
           printf(" ");
       }
       printf("*");
       lower=lower-1;
       upper=upper+1;
       initialNumCopy=initialNumCopy-1;
       printf("\n");
   }
   for (i=1;i<upper+1;i++)
   {
       printf("*");
   }

   printf("\n");
}
}


