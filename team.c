//
// EECS2031 team.c
//
// Program for maintaining a personal team.
//
//
// Uses a linked list to hold the team players.
//
// Author: <yong wu>
// Student Info: <214767511>


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

//**********************************************************************
// Linked List Definitions 
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//
//   ADD STATEMENT(S) HERE
typedef struct player {
    char * firstName;
    char * lastName;
    char position;
    int value;
    struct player * nextP;
} player;




//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE
player * insert (char first[], char last[], char pos, int val,player * head);
void delete(char last[],player * head);
void searchPlayer(char last[],player * head);
void searchVal(int val,player * head);
void printTeam(player * head);


//**********************************************************************
// Support Function Declarations
//

void safegets (char s[], int arraySize);        // gets without buffer overflow
void familyNameDuplicate (char familyName[]);   // marker/tester friendly 
void familyNameFound (char familyName[]);       //   functions to print
void familyNameNotFound (char familyName[]);    //     messages to user
void familyNameDeleted (char familyName[]);
void printTeamEmpty (void);
void printTeamTitle(void);
void printNoPlayersWithLowerValue(int value);
int compare(player *p1,player *p2);
//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
const char GOALKEEPER = 'G';
const char DEFENDER = 'D';
const char MIDFIELDER = 'M';
const char STRIKER = 'S';


//**********************************************************************
// Main Program
//

int main (void)
{ 
    const char bannerString[]
        = "Personal Team Maintenance Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
          "  V (search by value), P (print), Q (quit).\n";

    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.
    player *head=NULL;
   
 
    // announce start of program
    printf("%s",bannerString);
    printf("%s",commandList);
    
    char response;
    char input[MAX_LENGTH+1];
    do
    {
        printf("\nCommand?: ");
        safegets(input,MAX_LENGTH+1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
        {
            player * temp;
            char a[1024]={0};
            char b[1024]={0};
            char c[3]={0};
            int d;
            char e[1024]={0};
            // Insert a player entry into the linked list.
            // Maintain the list in correct order (G, D, M, S).
            //   ADD STATEMENT(S) HERE
            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
             printf("  family name: ");
            fgets(a,1024,stdin);
             printf("  first name: ");
             fgets(b,1024,stdin);
             printf("  position: ");
             fgets(c,3,stdin);
             printf("  value: ");
             fgets(e,1024,stdin);
             *c=toupper(*c);
             d=atoi(e);
             if (!(*c=='G'||*c=='D'||*c=='S'||*c=='M'))
             {
                 printf("You have entered an invalid position player was not inserted!\n");
            
             }
             else
             {
             temp=insert(b,a,c[0],d,head);
             if (temp!=NULL)
             {
                 head=temp;
             }
             
             }

        }
        else if (response == 'D')
        {
            // Delete a player from the list.

            printf("\nEnter family name for entry to delete: ");
// if head is null it'll return null
//if head is deleted it will return the next node
            //   ADD STATEMENT(S) HERE
           char a[1024]={0};
           fgets(a,1024,stdin);
           player * freePlayer;
           if(head!=NULL&& strcmp(head->lastName,a)==0)
           {
               strtok(a, "\n");
               familyNameDeleted (a);
               freePlayer=head;
               head=head->nextP;
              //I used malloc to assign memory for first and last names in player struct so freeing that 
              //before I free the pointers to player struct
               free(freePlayer->firstName);
               free(freePlayer->lastName);
               free(freePlayer);
           }
           else if(head!=NULL)
           {
               delete(a,head);
           }
           else
           {
               //didnt realize we had a safegets function. 
               //modifying the string so that the other given functions print in the correct format
               strtok(a, "\n");
               familyNameNotFound (a);
           }

        }
        else if (response == 'S')
        {
            // Search for a player by family name.
           
            printf("\nEnter family name to search for: ");
           
            //   ADD STATEMENT(S) HERE
             char a[1024]={0};
           fgets(a,1024,stdin);
           if (head==NULL)
           {
               strtok(a,"\n");
    familyNameNotFound(a);
    
           }
          
         else{  
         searchPlayer(a,head);
}


        }
        else if (response == 'V')
        {
            // Search for players that are worth less than or equal a value.
            
            printf("\nEnter value: ");

            //   ADD STATEMENT(S) HERE
          int val;
          char a[1024]={0};
           fgets(a,1024,stdin);
           val=atoi(a);
          searchVal(val,head);

        }
        else if (response == 'P')
        {
            // Print the team.
           printTeam(head);

            //   ADD STATEMENT(S) HERE

        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this case below
        }
        else 
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n",commandList);
        }
    } while (response != 'Q');
  
    // Delete the whole linked list that hold the team.
    //   ADD STATEMENT(S) HERE
    //head is always updated to be head->next
    //a temp pointing the actual head is used to free the memory
    // when temp is null the whole list has been deleted
    player*temp=head;
   while (temp!=NULL)
   {
       
       head=head->nextP;
       //I used malloc to assign memory for first and last names in player struct so freeing that 
      //before I free the pointers to player struct
       free(temp->lastName);
       free(temp->firstName);
       free(temp);
       temp=head;
   }

//Im reusing the delete function where it deletes if the player has the same last name


    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
printTeam(head);

    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize-1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name 
// that is already in the book.
void familyNameDuplicate (char familyName[])
{
    printf("\nAn entry for <%s> is already in the team!\n"
           "New entry not entered.\n",familyName);
}

// Function to call when a player with this family name was found in the team.
void familyNameFound (char familyName[])
{
    printf("\nThe player with family name <%s> was found in the team.\n",
             familyName);
}

// Function to call when a player with this family name was not found in the team.
void familyNameNotFound (char familyName[])
{
    printf("\nThe player with family name <%s> is not in the team.\n",
             familyName);
	
}

// Function to call when a family name that is to be deleted
// was found in the team.
void familyNameDeleted (char familyName[])
{
    printf("\nDeleting player with family name <%s> from the team.\n",
             familyName);
}

// Function to call when printing an empty team.
void printTeamEmpty (void)
{
    printf("\nThe team is empty.\n");
}

// Function to call to print title when whole team being printed.
void printTeamTitle (void)
{
    printf("\nMy Team: \n");
}

// Function to call when no player in the team has lower or equal value to the given value
void printNoPlayersWithLowerValue(int value)
{
	printf("\nNo player(s) in the team is worth less than or equal to <%d>.\n", value);
}

//**********************************************************************
// Add your functions below this line.
player * insert (char first[], char last[], char pos, int val,player * head)
{
    
    //have use new memory addresses each time you add a player or they all share the same names.
   char * firstCopy= malloc(sizeof(char)*1024);
    char * lastCopy= malloc(sizeof(char)*1024);
    
    //take the contents from the array from fgets and copy that to a new memory address
    int i=0;
    for(i=0;i<1024;i++)
    {
    *(firstCopy+i)=*(first+i);
    *(lastCopy+i)=*(last+i);
    }

    //initialize a new player as well as create a pointer to traverse the linked list if necessary
    player * nextNull;
    player *newPlayer = (player*)malloc(sizeof(player));
    newPlayer->firstName = firstCopy;
    newPlayer->lastName = lastCopy;
    newPlayer->value = val;
    newPlayer->position = pos;
    newPlayer->nextP = NULL;
    //check for same last name
    player * iter=head;
    while(iter!=NULL)
    {
        if (strcmp(newPlayer->lastName,iter->lastName)==0)
        {
            strtok(newPlayer->lastName, "\n");
            familyNameDuplicate (newPlayer->lastName);
            return NULL;
        }
        iter=iter->nextP;
    }
    if(head==NULL)
    {
        return newPlayer;
    }
   
    if(compare(newPlayer,head)>0)
    {
     
        newPlayer->nextP=head;
        return newPlayer;
    }
    nextNull=head;
    while(nextNull->nextP!=NULL&&compare(nextNull->nextP,newPlayer)>=0)
    {
        
      nextNull=nextNull->nextP;
        
    }
    newPlayer->nextP=nextNull->nextP;
    nextNull->nextP=newPlayer;
    
    return NULL;
}

void delete(char last[],player * head)
{
    player * freePlayer;
    if (head==NULL)
    {
       strtok(last, "\n");
        familyNameNotFound (last);
        return;
    }
   while(head->nextP!=NULL)
   {
       if (strcmp(head->nextP->lastName,last)==0)
       {
           strtok(last, "\n");
           familyNameDeleted (last);
           freePlayer=head->nextP;
           head->nextP=head->nextP->nextP;
           free(freePlayer->firstName);
           free(freePlayer->lastName);
           free(freePlayer);
           return;
       }
       head=head->nextP;
   }
   strtok(last, "\n");
familyNameNotFound (last);
return;
}

void searchPlayer(char a[],player * head)
{
     
   
    while(head!=NULL)
    {
        
    if (strcmp(head->lastName,a)==0)
    {
        strtok(a,"\n");
        familyNameFound(a);
        printf("\n");
        printf("%s",head->lastName);
        printf("%s",head->firstName);
        printf("%c\n",head->position);
        printf("%d",head->value);
        printf("\n");
    return;    
    }
    head=head->nextP;
    }
   
    
    strtok(a, "\n");
    familyNameNotFound (a);
    
}

void printTeam(player * head)
{
    if(head==NULL)
            {
                printTeamEmpty();
                return;
            }
            
            printTeamTitle();
           printf("\n");
            
                player * iter=head;
                while(iter!=NULL)
                {
                    printf("%s",iter->lastName);
                    printf("%s",iter->firstName);
                    printf("%c\n",iter->position);
               printf("%d\n\n",iter->value);
                    
                    
                    
                    iter=iter->nextP;
                }
              
            
}


void searchVal(int val,player * head)
{
    int foundOne=0;
    if (head==NULL)
    {
        printNoPlayersWithLowerValue(val);
        return;
    }
    while(head!=NULL)
    {
    if (head->value<=val)
    {
        foundOne=1;
        printf("\n");
        printf("%s",head->lastName);
        printf("%s",head->firstName);
        printf("%c\n",head->position);
        printf("%d",head->value);
        printf("\n");
        
    }
    head=head->nextP;
    }
    if (foundOne==0)
    {
        printNoPlayersWithLowerValue(val);
    }
}

//function to compare players
int compare(player * p1,player * p2)
{
    int p1v;
    int p2v;
    if((*p1).position=='G')
    {
        p1v=4;
    }
    else if((*p1).position=='D')
    {
        p1v=3;
    }
    else if((*p1).position=='M')
    {
        p1v=2;
    }
    else  
    {
        p1v=1;
    }
    
    if((*p2).position=='G')
    {
        p2v=4;
    }
    else if((*p2).position=='D')
    {
        p2v=3;
    }
    else if((*p2).position=='M')
    {
        p2v=2;
    }
    else  
    {
        p2v=1;
    }
 
    if (p1v>p2v)
    {return 1;}
    else if(p1v==p2v)
    {return 0;}
 return -1;
}
