/*
 * Alexander Pelaez
 * Lab 3, CSCI 112
 * 2/9/17
 */
 #include <stdio.h>
 #include <float.h>
 #include <math.h>
//declare methods

int getN(void);
double getInput(void);

int
main(void)// main method
{
int valN=getN();
double sum=0;
double sumSqu=0;
double lowest;
double highest;
double range=0;
double avg;
double std_dev;
lowest = DBL_MAX, highest = -DBL_MAX;
for (size_t i = 0; i < valN; i++)
  {
    double current =0.0;
    current =getInput();
    if (isgreater(current,highest)) {
      highest=current;
      //printf("Highest Number: %.2f\n", highest);
    }
    if(isless(current,lowest))
    {
      lowest=current;
    //  printf("Lowest N umber: %.2f\n", lowest);
    }
    sum=sum+current;
    sumSqu=sumSqu+pow(current,2);
  }
  range=highest-lowest;
  if (valN==0) {
    avg=0;
    std_dev=0;
  }
  else{
    avg=sum/valN;
    std_dev=sqrt ((sumSqu/valN)-pow(avg,2));
  }
  printf("Highest Number: %.3f\n", highest);
  printf("Lowest Number: %.3f\n", lowest);
  printf("Average is: %.3f\n", avg);
  printf("Range is: %.3f\n", range);
  printf("Lowest N umber: %.3f\n", std_dev);
}

int getN(void)//grabs how many values will be taken
{
  int inN=0;
  do {
    printf("Enter a value for N that is >= 0:\n");
    scanf("%d", &inN);
    if(inN<0)
    {
      printf("You must enter a number greater than 0\n" );
    }
    else{
      break;
    }
  } while(inN<0);
  return inN;
}
double getInput(void)
{
 double value;// declare varible
 printf("Enter a number:\n");// ask user to input value
 scanf("%lf", &value);// grab data given by user
// printf("%.4f\n",value );
 return value;// return data given by user
}
