#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fibbonacci(int n) 
{
   if(n == 0)
   {
      return 0;
   } 

   else if(n == 1) 
   {
      return 1;
   } 

   else 
   {
      return (fibbonacci(n-1) + fibbonacci(n-2));
   }
}

void isPalin(char str[],int index)
{
	int len;
	len = strlen(str)-(index + 1);

	if(str[index] == str[len])
	{
	   if(index+1 == len || index == len)
	   {
	      printf("Palindrome.");
	      return;
	   }

	   isPalin(str,index+1);
	}

	else
	{
	   printf("Not a Palindrome.");
	}
}

void tower(int n,char frompeg,char topeg,char auxpeg)
{
	if(n==1)
	{
	  printf("\nMove disk 1 from peg %c to peg %c\n",frompeg,topeg);

	  return;
	}

	tower(n-1,frompeg,auxpeg,topeg);

	printf("\nMove disk %d from peg %c to peg %c\n",n,frompeg,topeg);

	tower(n-1,auxpeg,topeg,frompeg);
}

void copy(char str1[], char str2[], int index)
{
    str2[index] = str1[index];
    // printf ("INDEX IS %d\n", index);
    if (str1[index] == '\0')
    {
        return;
    }
    copy(str1, str2, index + 1);
}



int main()
{
	int ch;
	int n;
	char str[20];
	int num;
	char str1[20], str2[20];

	printf("\n 1.) Fibonacci \n");
	printf("\n 2.) Palindrome\n");
	printf("\n 3.) Hanoi\n");
	printf("\n 4.) Copy\n");

	printf("Enter your Choice : \n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
        
       	printf("Enter n : \n");
       	scanf("%d",&n);
       
       	printf("Fibbonacci of %d: " , n);

       	for(i = 0;i<n;i++)
       	{
      		printf("%d ",fibbonacci(i));
      	}
        
	    break;

	    case 2:

	    printf("Enter a Word : ");
	    scanf("%s",str);
	    isPalin(str,0);
	    break;

	    case 3:

	    printf("Enter no. of disks : \n");
	    scanf("%d",&num);
        printf("Sequence of moves involved : \n");
	    tower(num,'a','c','b');
	    break;

	    case 4:

	    printf("Enter string to copy: ");
        scanf("%s", str1);
        copy(str1, str2, 0);
        //printf("Copying success.\n");
        printf("The first string is: %s\n", str1);
        printf("The second string is: %s\n", str2);
	    break;

	    default:

	    printf("Invalid.");
	    break;
    }

    return 0;

}