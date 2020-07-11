import java.util.Scanner;
import java.io.*;

class Mixer
{
	Scanner sc = new Scanner(System.in);
	
	int n;
	
	int arr[] = new int[100];
	
	public void accept()
	{
		System.out.println("Enter Number of Elements : ");
		n = sc.nextInt();
		
		System.out.println("Enter Array Elements in Ascending Order without any Repetiion in the Elements : ");
		
		for(int i = 0 ; i < n ; i++)
		{
			arr[i] = sc.nextInt();
		}
	}
	
	public Mixer mix(Mixer A, Mixer B)
	{
		Mixer ob = new Mixer();
		ob.n = A.n + B.n;
		int x = 0;
		for(int i = 0 ; i < ob.n ; i++)
		{
			if(i < A.n)
			{
				ob.arr[i] = A.arr[i];
			}
			
			else
			{
				ob.arr[i] = B.arr[x];
				x++;
			}
		}
		
		display(ob);
		
		return ob;
	}
	
	public void display(Mixer ob)
	{
		for(int i = 0 ; i < ob.n ; i++)
		{
			System.out.print(ob.arr[i]+" ");
		}
	
		System.out.println();
	}
}

public class MixerDemo
{
	public static void main(String args[])
	{
		Mixer A = new Mixer();
		Mixer B = new Mixer();
		Mixer ob = new Mixer();
		
		A.accept();
		B.accept();
		
		ob.mix(A,B);
	}
}