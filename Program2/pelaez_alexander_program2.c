/*
 * Alexander Pelaez
 * Program 2, CSCI 112
 * 3/20/17
 */
#include <stdio.h>

#define MAX_ARRAY_SIZE 50//declare max array size
int getInput(void);
int populateArray(int array[]);                  // Fill array with values from user.
void  printArray( int array[] , int n );              // Print out the array values
void  swap( int array[] , int index1, int index2 );    // Swap two array elements.
void  quickSort( int array[] , int low, int high );    // Sorting algorithm
int   partition( int array[] , int low, int high );    // Find the partition point (pivot)


int
main(void){//main function
  int array[MAX_ARRAY_SIZE];
  int n=populateArray(array);//get size of array and fill array with values
  printf("The initial array contains:\n");
  printArray(array,n);//print first array
  quickSort(array, 0, n-1);//sort the array
  printf("The array is now sorted\n");
    printArray(array,n);//print sorted array
return 0;

}
int populateArray(int array[]){//user menu control fill array with values
  int number=0;
printf("Enter the value of n >\n");
  scanf("%d", &number);// grab data given by user
  if(number<0)//check to make sure number is within bounds
  {
    printf("%2d is less than zero. Please try again.\n",number);
    return populateArray(array);
  }
  if(number>MAX_ARRAY_SIZE)
  {
    printf("%2d exceeds the maximum array size. Please try again.\n",number);
    return populateArray(array);

  }
  
  printf("Enter %2d integers (positive, negative, or zero) >\n", number);
  for(int i=0;i<number;i++)//loop thru and get values from user
  {
  array[i]=getInput();
  }

  return number;
}
void  printArray( int array[], int n ){//loop thru and print array out
for(int i=0;i<n;i++)
  printf("%2d\n", array[i]);

}             // Print out the array values
void  swap( int array[], int index1, int index2 ){
int temp=0;
temp=array[index1];//save one as temp then switch them all around
array[index1]=array[index2];
array[index2]=temp;
}    // Swap two array elements.
void  quickSort( int array[], int low, int high ){

  if (low < high){
          int pivot = partition( array, low, high );//find the pivot possition
             quickSort( array, low, pivot - 1 );//sort each side on the pivot
             quickSort( array, pivot + 1, high );
           }
         }
  // Sorting algorithm
int partition( int array[], int low, int high ){
int pivot = array[high];
int i=low;
for(int j=low;j<high;j++){
  if(array[j]<=pivot)//check array
  {
    swap(array,i,j);//swap where the pivot is in the array
    i=i+1;//counter
  }
}
swap(array, i, high);//swap the pivot and i
return i;//return i
}
int getInput()//get input method returns an int from the user
 {
  int Number=0;
  scanf("%d", &Number);// grab data given by user
 // printf("%.4f\n",value );
  return Number;// return data given by user
 }
