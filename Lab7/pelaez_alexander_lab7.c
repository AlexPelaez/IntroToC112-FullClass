/*
  * Homegrown strncpy test program
  * Alexander Pelaez
  * Lab 7, CSCI 112
  * 3/27/17
  */
 #include <stdio.h>
 #include <string.h>

 // Function prototypes
 char *myStrnCpy(char *dest, char *source, int n);
 char *myStrnCat(char *dest, char *source, int n);

 char *myStrnCpy(char *dest, char *source, int n)//my copy function
 {
   for (int i = 0; i < n; i++) {//for loops loops from zero to the number sent in by user
     dest[i]=source[i];//dest at i is replaced with source at i
   }
   dest[n]='\0';//dest at n is made null
   return dest;//return the pointer to dest
 }
 char *myStrnCat(char *dest, char *source, int n){//my concationation function

   int destLength = strlen(dest);//length of the dest array
   int i;//declare i
   for (i = 0; i < n && source[i] != '\0'; i++) {// loop from zero to n as long as source is not null
     dest[destLength+i]=source[i];//dest at its length plus i is replaced with source at i
    }
    dest[destLength+i]='\0';// the last char of dest is made null
    return dest;// return the pointer to dest
 }

 int main() {
   // Test your function with various source strings and values of n

   char testSrc[] = "Hello";
   char testDest[40] = "world";
   //char testDest[40];
   int n = 5;

   myStrnCat(testDest, testSrc, n);
   printf("CAT: %s \n", testDest);

   myStrnCpy(testDest, testSrc, n);
   printf("CPY: %s \n", testDest);

   printf("%s \n", testDest);
   return 0;
 }
