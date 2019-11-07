/*
 * Alexander Pelaez
 * Project 1, CSCI 112
 * 2/5/17
 */
 #include <stdio.h>
 #include <float.h>
 #include <math.h>
 #define TRUE 1// define true and false
 #define FALSE 2

 int getInput(void);
 int isValid(int);
 void printPattern(int);
 int
 main(void)
 {
  int valid=FALSE;
  int input;
  while (valid==FALSE)//get if the input is valid or not if not keep running
  {
    input=getInput();

    if(isValid(input)==TRUE)//when true break the loop
    {
       //printf("valid\n");
      valid=TRUE;

    }

  }
  printPattern(input);//print the tirangle
  return 0;
 }
 void printPattern(int input)
 {
   if(input==1)// if the input is one print 1
   {
     printf("1");
     printf("\n");
   }
   else{//if the input is not 1


   int count=0;
   for (size_t i = 1; i <= input; i=i+2) {//top of triangle and middle line
     printf("%*s", (int)(input-i), "");//white space
     while (count!=i) {
       count++;
       printf("%d ", count);//print the numbers on the line

     }
     count =0;//reset for next line
     printf("\n");
   }
   count =0;
   for (size_t i = input-2; i > 1; i=i-2) {//bottom of triangle
     printf("%*s", (int)(i-input), "");//white space
     while (count!=i) {
       count++;
       printf("%d ", count);//print numbers

     }
     count =0;
     printf("\n");
   }
   printf("%*s", (int)(input), " 1");//print the last one on the last line and indent
   printf("\n");
 }
 }
 int getInput(void)// get number from user
 {
  int value;// declare varible
  printf("Enter an odd number less than or equal to 9 and greater than 0 >\n");// ask user to input value
  scanf("%d", &value);// grab data given by user
  return value;// return data given by user
 }

 int isValid(int input) {//checks if the input value is within bounds of the input peramerters and returns true or false ints
   if(isgreater(input,9.0))
   {
     printf("You have entered a number more than 9. Please try again.\n");
     return FALSE;
   }
   else if(isless(input,1.0))
   {
     printf("You have entered a number less than 1. Please try again.\n");
     return FALSE;
   }
   if(input%2==0)
   {
     printf(" Enter an odd number less than or equal to 9 and greater than 0 >\n");
     return FALSE;
   }
   else
   {
       return TRUE;
   }
 }
