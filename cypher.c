

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int temp;
    int shiftVal;
    char str[83];
int j;
    for(j=0;j<80;j++)
    {
        str[j]=0;
    }
    printf("Enter a sentence\n");
   fgets(str, 83, stdin);
//input error check 1
if ((int)str[82]<1)
{
printf("String too large");
printf("\n");
exit(0);
}
else
{
    printf("Enter a shift value\n");
    scanf("%d",&shiftVal);
//input error check 2
if (shiftVal<1||shiftVal>25)
{
printf("Invalid shitft value");
printf("\n");
exit(0);
}
    //cycle through the entire sentence
int i;
   for (i=0;i<80;i++)
    {
        //if its not a space char shift it
        temp=(int)str[i];
        if(temp!=32)
        {
            //lower case shift where you need to wrap around
            if (temp>=97&&temp<=122&&temp+shiftVal>122)
            {
                int wrap=(shiftVal%26);
                if(temp+wrap>122)
                {
                    str[i]=(char)(97+(temp+wrap-123));
                }
                else
                {
                str[i]=(char)(temp+wrap);
                }
            }
            //Upper case shift where you need to wrap around
            else if(temp>=65&&temp<=90&&temp+shiftVal>90)
            {
                
                int wrap=((shiftVal)%26);
                if(temp+wrap>90)
                {
                    str[i]=(char)(65+(temp+wrap-91));
                }
                else
                {
                str[i]=(char)(temp+wrap);
                }
                
            }
            //third case where you dont need to wrap around
            else if(temp>=65&&temp<=90||temp>=97&&temp<=122)
            {
                
                str[i]=(char)(temp+shiftVal);
            }
        }
        
    }
//print the resulting string
    int t=0;
   while((int)str[t]!=0)
   {
       printf("%c",str[t]);
       t+=1;
   }
}
}


