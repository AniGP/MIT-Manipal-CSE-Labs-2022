#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char name[50];
	int roll;
	float cgpa;
}STUDENT;

void read(STUDENT* s,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter Name : \n");
		scanf("%s",(s+i)->name);
		printf("Enter Roll Number : ");
		scanf("%d",&(s+i)->roll);
		printf("Enter your CGPA \n");
		scanf("%f",&(s+i)->cgpa);
	}
}
void disp(STUDENT* s,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Name: %s\n",(s+i)->name);
		printf("Roll Number: %d\n",(s+i)->roll);
		printf("CGPA : %2f\n",(s+i)->cgpa);
	}
}
void sort(STUDENT *s,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((s+i)->roll>(s+j)->roll)
			{
				STUDENT t=*(s+i);
				*(s+i)=*(s+j);
				*(s+j)=t;
			}
		}
	}
}
int main()
{
	//STUDENT student;
	//read(&student,1);
	//disp(&student,1);
	
	int n;
	scanf("%d",&n);
	STUDENT *s=(STUDENT*)calloc(n,sizeof(STUDENT));
	read(s,n);
	sort(s,n);
	disp(s,n);

}
