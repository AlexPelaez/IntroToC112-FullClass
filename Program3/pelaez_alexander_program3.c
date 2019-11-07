#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 25
typedef struct student {//declare the structure used
   int  id;
   char  lName[NAME_SIZE];
   char  fName[NAME_SIZE];
   float *grade;
   float gpa;

}stu;

int main(void);//declare the functions used
struct student * scanStudent(struct student *stu,int numIn,int numGrade);
void printStudent(struct student *stu, int numIn, int numGrade);
void freeMem(struct student *stu, int numStu);
struct student * scanStudent(struct student *stu,int numIn,int numGrade)//method to take student input
{
stu[numIn].grade = (float *) (calloc(numGrade, sizeof(float)));//allocate memory for an array of floating point numbers
float count=0;//start a count
scanf("%d ",&stu[numIn].id);//scan and add the id number to the student
scanf("%s ",stu[numIn].lName);//scan and add the last name
scanf("%s ",stu[numIn].fName);//scan and add the first name
for(int i=0; i<numGrade;i++)//loop thru the grades
{
scanf("%f",&stu[numIn].grade[i]);//scan the grade and add it at spot i
count=count+stu[numIn].grade[i];//add that number to the count
}
stu[numIn].gpa = count/numGrade;//divide the count by the number of grades and add that to the gpa
return stu;//return a pointer to a student structure
}
void printStudent(struct student *stu, int numIn, int numGr)//prints student info
{
printf("ID: %d, Name: %s %s, GPA: %.2f\n",stu[numIn].id,stu[numIn].fName, stu[numIn].lName, stu[numIn].gpa);//prints the students id, first and last name and gpa
printf("Grades: ");
for(int i=0; i<numGr;i++)//loops thru number of grades added
{
  printf("%.1f ", stu[numIn].grade[i]);//prints the grades
}
printf("\n");//formating
}
void freeMem(struct student *stu, int numStu)
{
  for(int i = 0; i<numStu;i++)
  {
    free(stu[i].grade);
    stu[i].grade=NULL;
  }
  free(stu);
    stu = NULL;
}
int main(void)//main function
{
  int numStu=0;
  int numGrade=0;
  struct student **st=( student *) (calloc(numStu, sizeof( student)));
  scanf("%d\n",&numStu);//grab number of students and number of grades being added
  scanf("%d",&numGrade);
  printf("Number of students: %d\n", numStu);//print that data out
  printf("Number of grades (each): %d\n", numGrade);

  //struct student stu[numStu];
  for(int i = 0; i<numStu;i++)//loop N times
  {
  st[i]= scanStudent(st,i,numGrade);//scan thru students and return a pointer to a students data
  }
  for(int i = 0; i<numStu;i++)//loop N times
  {
  printStudent(st[i],i,numGrade);//print the students info out
  }
  freeMem(*st,numStu);//free up memmory
return 0;

}
