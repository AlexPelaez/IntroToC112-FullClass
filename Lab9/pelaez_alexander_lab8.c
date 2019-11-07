#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct element {
   int  an[50];
   char  name[50];
   char  cs[50];
   char  class[50];
   float aw;
   int tron[7];
}elem;
#define SIZE 300
#define MAX_ELEMENTS 20
struct element * scanElement(struct element *elem,int numIn);
void printElement(struct element *elem, int numIn);

struct element * scanElement(struct element *elem, int numIn)
{
  char str[SIZE];//declare varibles
  char temp[SIZE];
  char temp2[SIZE];
  int lineLen;
  int wordLen;
  int i;
  int count = 0;
  int tf = 1;
  int ce=0;
  int tronCount=0;
  int period = 1;
  if ( fgets( str, SIZE, stdin ) )//get input from user
  {
    lineLen = strlen(str);
    str[lineLen]='\0';
    lineLen=strlen(str);//get the length of the input
    for(i=0;i<=lineLen;i++)//loop to that length
    {
      //printf("here\n" );
      if(str[i]==' ')//if its a space
      {
        //printf("space\n" );
        temp[count]='\0';//end the temp var
        if(tf==1)
        {
          tf=0;
          if(ce==0)//to get atomic number
          {
              //printf("ce=0\n" );
              ce++;//incriment the input thing
              int tempVar = (int) strtol( &temp[0], NULL, 10);//change it to a number
              elem[numIn].an[0] = tempVar;//add it to the struct
              strncpy ( temp, temp2, SIZE );//reset the temp array
              count=0;//reset the temp array count
          }
          else if(ce==1)//to get elemn name
          {
            ce++;
            //printf("ce=1\n" );
            wordLen=strlen(temp);//get the lenght of temp
            strncpy(elem[numIn].name,temp,wordLen);//copy temp into the struct
            elem[numIn].name[wordLen]='\0';//end the string
            strncpy ( temp, temp2, SIZE );//reset temp array
            count=0;//reset the temp array count
          }
          else if(ce==2)//to get cs of elem
          {
            ce++;
            //printf("ce=2\n" );
            wordLen=strlen(temp);
            strncpy(elem[numIn].cs,temp,wordLen);//copy temp into the struct
            elem[numIn].name[wordLen+1]='\0';//end the string
            strncpy ( temp, temp2, SIZE );
            count=0;
          }
          else if(ce==3)// to get class type of element
          {
            //same as the last one
            ce++;
            wordLen=strlen(temp);
            //printf("here%d\n", wordLen);
            strncpy(elem[numIn].class,temp,wordLen);
            elem[numIn].name[wordLen+1]='\0';
            strncpy ( temp, temp2, SIZE );
          //printf("ce=3\n" );
          count=0;
          }
          else if(ce==4)//to get atomic weight
          {
            if(period==1)//before period
            {
            wordLen=strlen(temp);
            float tempVar = (int) strtol( &temp[0], NULL, 10);//change it to a number
            elem[numIn].aw = tempVar;//add it and reset the temp
            strncpy ( temp, temp2, SIZE );
            //printf("ce=4\n" );
            count=0;
            period=0;//mark that there was a period
            }
            else if(period==0)//after the period
            {
            ce++;
            wordLen=strlen(temp);//get the length
            float tempVar = (int) strtol( &temp[0], NULL, 10);//chage it to a number
            elem[numIn].aw = elem[numIn].aw+tempVar;//add it to the struct
            elem[numIn].aw = (elem[numIn].aw)/1000;//divide by 1000 to get the decimal right
              strncpy ( temp, temp2, SIZE );
            count=0;
            }
          }
          else if(ce==5)//to get the electrons
          {
          //printf("ce=5\n" );
          //the same as the first one
          int tempVar = (int) strtol( &temp[0], NULL, 10);
          elem[numIn].tron[tronCount]=tempVar;
          strncpy ( temp, temp2, SIZE );
          tronCount++;
          count=0;
          }
        }
      }
      else if(str[i]=='.')//if the char checked is a period
      {
        period=1;
      }
      else if(isalnum(str[i]))//if the char checked is a letter or number
      {
      //  printf("letter or num\n" );
        temp[count]=str[i];//add to temp
        count++;//add to the lenght of temp counter
        tf=1;
      }
    }
  }
  return elem;
}
void printElement(struct element *elem, int numIn)//print emement function
{
printf("---------------\n");
printf("| %d\t%.4f\n",elem[numIn].an[0],elem[numIn].aw);
printf("| %s\t%s\n",elem[numIn].cs, elem[numIn].name);
printf("| %d %d %d %d %d %d %d\n",elem[numIn].tron[0],elem[numIn].tron[1],elem[numIn].tron[2],elem[numIn].tron[3],elem[numIn].tron[4],elem[numIn].tron[5],elem[numIn].tron[6]);
printf("---------------\n");


}
int main(int argc, char *argv[])//main method grabs the value passed from the terminal
{
      if(argc <2){printf("You must provide exactly one argument to this program.\n" ); return 0;}
      int N = (int) strtol( argv[1], NULL, 10);//change that into an int
      if (N<0||N>MAX_ELEMENTS) {//check that the value sent to the program is valid
        printf("You must provide an integer greater than 0 and less than or equal to 20.\n");
        return 0;
      }
      else
      {
        struct element elem[N];
        for(int i = 0; i<N;i++)//loop N times
        {
          scanElement(elem,i);
        }
        printf("%d total elements.\n", N);
        if(N>1)
        {
          int tempHolderM=0;
          int tempHolderMin=0;
          int max=0;
          int min = 0;
          for(int i=0;i<N;i++)//check atomic numbers
          {
            if(max<elem[i].an[0])
            {
              tempHolderM=i;
              max=elem[i].an[0];
            }
            if(min>elem[i].an[0])
            {
              tempHolderMin=i;
              min = elem[i].an[0];

            }
          }

          printf("%s had the smallest atomic number.\n",elem[tempHolderMin].name);
          printf("%s had the largest atomic number.\n",elem[tempHolderM].name);
        }
        for(int i = 0; i<N;i++)//loop N times
        {
          printElement(elem,i);
        }
      }
        return 0;
}
