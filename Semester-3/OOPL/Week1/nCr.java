import java.util.Scanner;

public class nCr 
{
	public static int fact(int n)
	{
		int i;
		int fact=1;

		for(i=1;i<=n;i++)
		{
			fact=fact*i;
		}

		return fact;
	}

	public static void main(String[] args)
	{
		int n,r;
		Scanner obj = new Scanner(System.in);

		System.out.println("Enter the Value of n : ");
		n = obj.nextInt();

		System.out.println("Enter the Value of r : ");
		r = obj.nextInt();

		System.out.println("nCr = " + fact(n)/(fact(r)*fact(n-r)));
		System.out.println("nPr = " + fact(n)/fact(n-r));

	}
}

