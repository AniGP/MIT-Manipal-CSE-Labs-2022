import java.util.Scanner;

public class Prime
{
	public static boolean isPrime(int n)
	{
		if(n<=1)
		{
			return false;
		}

		else
		{
			for(int i=2;i<Math.sqrt(n);i++)
			{
				if(n%i==0)
				{
					return false;
				}

				else
				{
					return true;
				}
			}
		}

		return true;
	}

	public static void printPrime(int n) 
	{ 
		for(int i = 2; i <= n; i++)  
		{ 
    		if(isPrime(i)) 
        	System.out.print(i + " "); 
		} 
	}

	public static void main(String[] args)
	{
		int n,i;
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter the Value of n : ");
		n = obj.nextInt();

		if(isPrime(n))
		{
			System.out.println(n + " is a Prime Number. ");
		}

		else
		{
			System.out.println(n + "is not a Prime Number.");
		}

		System.out.println("Enter the value upto which Prime Numbers are to be printed : ");
		int num = obj.nextInt();

		 printPrime(num); 
	}
}