import java.io.*;
import java.util.Scanner;

class Stack
{
	static Scanner input;
	static int index=-1;

	public static void main(String[] args)
	{
		input=new Scanner(System.in);
		System.out.println("Enter stack size : ");
		int size=input.nextInt();
		int stack[]=new int[size];
		
		while(true)
		{
			System.out.println("1.)Push\n2.)Pop\n Exit");
			int ch=input.nextInt();
		
			switch(ch)
			{
				case 1:

				push(stack,size);
				break;
		
				case 2:

				pop(stack, size);
				break;
				
				default:
				System.out.println("Invalid option.");
			}
		}
	}
	
	static void push(int[] stack, int size)
	{
		int x;
		
		do
		{
			if(index==size-1)
			{
				System.out.println("Cannot push more elements.\nStack is full.");
				return;
			}
		
			System.out.println("Enter element to push into stack or -1 to exit :");
			x=input.nextInt();

			stack[++index]=x;
		}while(x!=-1);
		
		display(stack,size);
	}

	static void pop(int[] stack, int size)
	{
		char x;
		
		if(index==-1)
		{
			System.out.println("Cannot pop.\nStack is empty.");
			return;
		}
		
		System.out.print("Popping...........");
		
		System.out.println(stack[index--]);
		
		display(stack,size);
	}
	
	static void display(int[] stack, int size)
	{
		for(int i = 0 ; i < size ; i++)
		{
			System.out.println(stack[i]);
		}
	}
}