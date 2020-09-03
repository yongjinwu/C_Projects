

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int i;
    char temp;
    int str1[26];
    int str2[26];
    //initialize both arrays' count of each character to 0
    for(i=0;i<26;i++)
    {
        str1[i]=0;
        str2[i]=0;
    }
    //read character and increment array elements for the first string
    printf("Enter first word: ");
    for(;;)
    {
        temp=getchar();
        if(isalpha(temp))
        {
            //character 'a' has ascii value of 97 
            //97-97=0 which is the position in the array that stores the count for 'a'
            //same for all other lower case letters
            str1[(int)(tolower(temp))-97]+=1;
            
            
        }
        //exit the loop reading the first string when user hits enter
        if(temp=='\n')
        {
            break;
        }
    }
    printf("Enter second word: ");
    //read characters and increment array elements for the second string
    for(;;)
    {
        //uses the same loop as above
         temp=getchar();
        if(isalpha(temp))
        {
            str2[(int)(tolower(temp))-97]+=1;
            
        }
        if(temp=='\n')
        {
            break;
        }
    }
    //loop to compare the two arrays
        for(i=0;i<26;i++)
        {
            if(str1[i]!=str2[i])
            {
                printf("The words are not anagrams.");
                exit(0);
            }
        }
        printf("The words are anagrams.");
    

    return 0;
}



