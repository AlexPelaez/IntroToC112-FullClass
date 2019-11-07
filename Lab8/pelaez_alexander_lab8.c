#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

char* reverse(char* str, int* len);


  char* reverse(char* str, int* len)//this is the reverseing function it just grabs the last word in the string 
  {
    int i;
    for (i = *len - 1; i >= 0; i--)//from len-1 to zero
    {
        if (str[i] == ' ')//if the array contains a space at i
        {
            str[i] = '\0';//set it equal to the end of the array
            if (i < *len - 1)//if i is less then len-1
            {
                *len = i - 1;//new len is i-1
                return &str[i + 1];//return the data location of the str[i+1]
            }
        }
    }
    return NULL;//if you dont hit the other return return null
  }


int main(int argc, char *argv[])//main method grabs the value passed from the terminal
    {


      int N = (int) strtol( argv[1], NULL, 10);//change that into an int
      if (N<0||argv[2]!=NULL||argv[1]==NULL) {//check that the value sent to the program is valid
        printf("Please provide valid arguments for this program\n");
        return 0;
      }
      else{




        for(int i = 0; i<N;i++)//loop that many times
        {
            char str[SIZE];//make new char array
            if ( fgets( str, SIZE, stdin ) )//get input from user
            {
              int len = strlen(str);//get the length of the input

              str[len-1]='\0';//change the last char is its an enter

              char* lastWord = reverse(str, &len);//get a pointer to the last word in the array
              while (lastWord != NULL)//while there is a word in the string
             {
                 printf("%s ", lastWord);//print the next last workd
                 lastWord = reverse(str, &len);//then get the new last word and re run through
             }
             if (len > 1)
                 printf("%s\n", str);//prints the last word

                      }

        }

}
        return 0;
    }
