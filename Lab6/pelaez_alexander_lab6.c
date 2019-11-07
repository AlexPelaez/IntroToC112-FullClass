/*
 * Alexander Pelaez
 * Lab 6, CSCI 112
 * 3/6/17
 */
#include <stdio.h>
#include <float.h>
 #include <math.h>
int userMenu();
void equation1(float *);
void equation2(float *);
void equation3(float *);
void equation4(float *);

float getPosIn(void);
float getPosFin(void);
float getVelIn(void);
float getVelFin(void);
float getAcc(void);
float getTime(void);

int main (void)
    {
        // Print welcome message
        printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

        // Variable for the user choice menu.
        int userChoice;

        do
        {
            userChoice = userMenu();  // print menu, validate choice is between 1 and 5

            // You will pass the address of this variable to your equation functions.
            float result;               // Variable to hold calculated result

            // Handle menu choice selected by user
            switch( userChoice )
            {
                case 1:
                equation1(&result);
                break;

                case 2:
                equation2(&result);
                break;
                case 3:
               equation3(&result);
                break;

                case 4:

               equation4(&result);
                break;

                case 5:
                    // exit program if user selected QUIT
                    printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
                    return 0;
                    break;
            }

printf("Your result is %.4f.\n\n", result);



        } while ( userChoice != 5 );

        return 0; // exit with no error
    }
    float getPosIn(void){//get inital position
      float num=0;
      printf("Enter inital position >\n");
      scanf("%f", &num);
      return num;
    }
    float getPosFin(void){//get final postion
      float num=0;
      printf("Enter final position >\n");
      scanf("%f", &num);
      return num;
    }
    float getVelIn(void){// get inital velocity
      float num=0;
        printf("Enter inital velocity >\n");
        scanf("%f", &num);
        return num;
    }
    float getVelFin(void){//get final velocity
      float num=0;
        printf("Enter final velocity >\n");
        scanf("%f", &num);
        return num;
    }
    float getAcc(void){//get acceleration
      float num=0;
      printf("Enter acceleration >\n");
      scanf("%f", &num);
      return num;
    }
    float getTime(void){//get time
      float num=0;
      printf("Enter time >\n");
      scanf("%f", &num);
      return num;

    }
int userMenu(){//user menu control
  int number=0;
  printf("Choose a motion equation 1-4 or choose 5 to OUIT >\n");
  scanf("%u", &number);// grab data given by user
  if(number<1)
  {
    printf("Invalid Option. Please try again.\n");
    userMenu();
  }
  if(number>5)
  {
    printf("Invalid Option. Please try again.\n");
    userMenu();
  }
  return number;
}
void equation1(float *anws){//equation 1 function
  printf("1\n");
//  float anws=0;
  float iV = getVelIn();//get each number from user same for each equation just diffrent numbers
  float acc =getAcc();
  float ti = getTime();
  *anws=iV+(acc*ti);//assign the memory location with pointer *anws with the anwser to the equation
//  printf("Your result is %.4f.\n\n", anws);

}
void equation2(float *anws){//equation 2 function
  printf("2\n");
//  float anws=0;
  float iP =getPosIn();
  float iV=getVelIn();
  float ti = getTime();
  float acc = getAcc();
  *anws=iP+iV*ti+(1/2)*acc*pow(ti,2);
  //  printf("Your result is %.4f.\n\n", anws);
}
void equation3(float *anws){//equation 3 function
  printf("3\n");
//  float anws=0;
  float iV = getVelIn();
  float acc = getAcc();
  float fP = getPosFin();
  float iP = getPosIn();
  *anws=sqrt(pow(iV,2)+2*acc*(fP-iP));
//  printf("Your result is %.4f.\n\n", anws);

}
void equation4(float *anws){//equation 4 function
  printf("4\n");
//  float anws=0;
  float iP =getPosIn();
  float fV = getVelFin();
  float iV = getVelIn();
  float ti = getTime();
  *anws=iP+(1/2)*(fV+iV)*ti;
//  printf("Your result is %.4f.\n\n", anws);

}
