/*
 * Alexander Pelaez
 * Lab 2, CSCI 112
 * 1/30/17
 */
 #include <stdio.h>
//declare methods
double getInput(void);
double getNext(double, double);
int
main(void)// main method
{

double value1 = getInput();//gets users first input
double value2 = getInput();//gets users second input

double temp=0;// set temp as zero

temp= getNext(value1, value2);//run get next, send over value1 and value2
value1=value2;//replace values
value2=temp;
temp= getNext(value1, value2);//repete to find 4th number
value1=value2;//repete
value2=temp;
temp= getNext(value1, value2);//repete to find 5th value
printf("%.2f\n", temp);//print fifth value
return (0);
}
double getNext(double val1,double val2)// get next value in sequence
{
  double v1 = val1;//grab varibles
  double v2 = val2;//grab varibles
  double nextValue;// declare varible
 nextValue = val2*3+val1/2;// math of the sequence
  return nextValue;// return the next value
}
double getInput(void)
{
 double value;// declare varible
 printf("Enter a value >\n");// ask user to input value
 scanf("%lf", &value);// grab data given by user
// printf("%.4f\n",value );
 return value;// return data given by user
}
