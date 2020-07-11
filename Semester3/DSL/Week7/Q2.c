#include<stdio.h>
#include<stdlib.h>
#define N 7

typedef struct
{
	int arr[N];
	int left1,right1,left2,right2;
}cQ;

void insertcq1(cQ *q,int num)
{
	int initial=0;
	int MAX = N/2+1;
	if(q->left1==-1)
	{
		q->left1=q->right1=initial;
		q->arr[q->right1]=num;
	}
	else
		if((q->right1+1)%MAX!=q->left1)
		{
			q->right1=(q->right1+1)%MAX;
			q->arr[q->right1]=num;
		}
	else
		printf("cQ1 overload!\n");
}
void insertcq2(cQ *q,int num)
{
	int initial=N/2+1;
	int MAX = N;
	if(q->left2==initial-1)
	{
		q->left2=q->right2=initial;
		q->arr[q->right2]=num;
	}
	else
		if(((q->right2+1-initial)%(MAX-initial)+initial)!=q->left2)
		{
			q->right2=((q->right2+1-initial)%(MAX-initial)+initial);
			q->arr[q->right2]=num;
		}
	else
		printf("cQ2 overload!\n");
}

int deletecq1(cQ *q)
{
	int initial=0;
	int MAX = N/2+1;
	if(q->left1==initial-1)
	{
		printf("cQ1 is empty!\n");
		return -9999;
	}
	else
	if(q->left1==q->right1)
	{
		int x = q->arr[q->left1];
		q->left1=q->right1=initial-1;
		return x;
	}
	else
	{
		int x = q->arr[q->left1];
		q->left1=(q->left1+1)%MAX;
		return x;
	}
}
int deletecq2(cQ *q)
{
	int initial=N/2+1;
	int MAX = N;
	if(q->left2==initial-1)
	{
		printf("cQ2 is empty!\n");
		return -9999;
	}
	else
	if(q->left2==q->right2)
	{
		int x = q->arr[q->left2];
		q->left2=q->right2=initial-1;
		return x;
	}
	else
	{
		int x = q->arr[q->left2];
		q->left2=((q->left2+1-initial)%(MAX-initial)+initial);
		return x;
	}
}

void display(cQ q)
{
	int MAX1 = N/2+1;
	int MAX2= N;

	printf("cQ 1 :\n");
	int i=q.left1;
	if(i!=-1)
	{for(;i!=q.right1;i=(i+1)%MAX1)
		printf("%d ",q.arr[i] );
	printf("%d ",q.arr[i] );

	printf("\n");
}
	else
		printf("cq 1 is empty!\n");


	printf("cQ 2 :\n");
	i=q.left2;
	if(i!=N/2)
	{
		for(;i!=q.right2;i=((i-N/2)%(MAX2-(N/2+1))+(N/2+1)))
		printf("%d ",q.arr[i] );
	printf("%d ",q.arr[i] );

	printf("\n");
}
else printf("cq 2 is empty!\n");
}

int main()
{
	cQ q;
	q.left1=q.right1=-1;
	q.left2=q.right2=N/2;
	int choice;
	int val;
	printf("1. Insert1\n2. Delete1\n3. Insert2\n4. Delete2\n5. Display\n6. Exit\n");
	do
	{
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter num : ");
			scanf("%d",&val);
			insertcq1(&q,val);
			break;
			case 2:
			val=deletecq1(&q);
			if(val!=-9999)
				printf("The element deleted from cq 1 is : %d\n",val );
			break;
			case 3:
			printf("Enter num : ");
			scanf("%d",&val);
			insertcq2(&q,val);
			break;
			case 4:
			val=deletecq2(&q);
			if(val!=-9999)
				printf("The element deleted from cq 2 is : %d\n",val );
			break;
			case 5:
			display(q);
			break;
			case 6:
			printf("Exit\n");
		}
	}while(choice!=6);
	return 0;
}
