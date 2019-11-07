 #include <stdio.h>
//declare functions
int getInput(void);
int getOdd(int[]);
int getEven(int[]);
 int
 main(void) {
   //varibles used
   int barcode[12];
   int odd;
   int even;
   int added;
   int key;

   printf("Enter a bar code to check. Press enter after each number >");
   for (int i=0; i < 12; i++){
       barcode[i] = getInput();
     }
     printf("You entered the code: ");//print out entered barcode
     for (int k = 0; k < 12; k++){
    printf("%2d", barcode[k]);
    }
    printf("\n");//seprate math
    odd = getOdd(barcode);
    even = getEven(barcode);
    added=odd+even;
    key = added % 10;
    if(key==0)//if the key is zero dont sub from ten
    {

    }
    else{
      key=10-key;
    }//print outs
    printf("STEP 1: Sum of odds times 3 is %2d\n", odd);
    printf("STEP 2: Sum of the even digits is %2d\n", even);
    printf("STEP 3: Total sum is %2d\n", added);
    printf("STEP 4: Calculated check digit is %2d\n", key);
    if(key==barcode[11])//if the code is valid
    {
        printf("STEP 5: Check digit and last digit match\n");
        printf("Barcode is VALID.\n");
    }
    else{//if invalid
      printf("STEP 5: Check digit and last digit do not match\n");
      printf(" Barcode is INVALID.\n");
    }

 }
 int getOdd(int table[])//gets the sum of the odd numbers
 {
   int sum=0;
   for (int i=0; i < 12; i=i+2){
       sum = sum+table[i];
     }
     return sum*3;
 }
 int getEven(int table[])//gets sum of even numbers
 {
   int sum=0;
   for (int i=1; i < 11; i=i+2){
       sum = sum+table[i];
     }
     return sum;
 }
 int getInput()//grabs users input
  {
  int input;
   scanf("%d", &input);// grab data given by user
  // printf("%.4f\n",value );
   return input;// return data given by user
  }
