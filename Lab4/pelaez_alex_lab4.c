
/*
 * Alexander Pelaez
 * Lab 4, CSCI 112
 * 2/22/17
 */
 #include <stdio.h>
 #include <float.h>
 #include <math.h>


 #define TRUE 1// define true and false
 #define FALSE 2
 #define PI 3.14159
 #define LOOP_LIMIT 90
 int Number;//enum varible
 typedef enum {
        Sine,
        Cosine,
        Tangent,
        QUIT,
    } menu_t;
//get the users input
int getInput(void);
int getInput()
 {
  Number=0;
  scanf("%u", &Number);// grab data given by user
 // printf("%.4f\n",value );
  return Number;// return data given by user
 }
 //print sin function
 void printSin(){
 	int count = 0;
 	while(count <= LOOP_LIMIT){
 		double x = PI*count/180;
 		double output = sin(x);
 		printf("\tsin(%d) = %.4f\n",count,output);
 		count += 15;
 	}
 }
 //print cosine function
 void printCos(){
 	int count = 0;
 	while(count <= LOOP_LIMIT){
 		double x = PI*count/180;
 		double output = cos(x);
 		printf("\tcos(%d) = %.4f\n",count,output);
 		count += 15;
 	}
 }
 //print tangent function
 void printTan(){
 	int count = 0;
 	while(count <= LOOP_LIMIT){
 		double x = PI*count/180;
 		double output = tan(x);
 		if(count==90){
 			printf("\ttan(%d) = UNDEFINED\n",count);
 		}
 		else if(count==270){
 			printf("\ttan(%d) = UNDEFINED\n",count);
 		}
 		else{
 			printf("\ttan(%d) = %.4f\n",count,output);
 		}
 		count += 15;
 	}
 }
 int
 main(void) {
//main method prints continues to run menu and then send to other functions
   int isValid = 0;
 	while(isValid==0){
 		printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
 		printf("Enter your choice > ");
 		menu_t check = getInput();
 		//the switch statement option
 		switch(check){
 			case Sine:
    printSin();

 			break;

 			case Cosine:
      printCos();

 			break;

 			case Tangent:
      printTan();
 			break;

 			case QUIT:
 			printf("You chose QUIT. Thank you, come again!");
 			isValid = 1;
 			break;

 			default:
 			printf("%d is an invalid option. Please try again.\n",Number); // PRINTS LARGE NUM FOR -1
 			break;
 	}
}
}
