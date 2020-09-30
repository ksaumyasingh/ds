#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	char name[20];
	int roll;
	char city[10];
}student;
void main()
{
	int total,i;
	student * listOfStudents;
	/*printf("enter the total no of students");
	scanf("%d",&total);
	listOfStudents=(student *)malloc(total*sizeof(student));
	for(i=0;i<total;i++)
	{
		printf("enter the name,roll,adress of %dth student",i+1);
		scanf("%s%d%s",listOfStudents[i].name,&(listOfStudents[i].roll),listOfStudents[i].city);
	}
	for(i=0;i<total;i++)
		printf(" %dst student= %s , %d , %s",i+1,listOfStudents[i].name,listOfStudents[i].roll,listOfStudents[i].city);
	printf("%d",sizeof(student));*/
 
	
	printf(" struct=%d\n",sizeof(student));
	printf(" char=%d\n",sizeof(listOfStudents->name));
	printf(" int=%d\n",sizeof(listOfStudents->roll));
    printf(" int=%d\n",sizeof(listOfStudents->city));

	

}
