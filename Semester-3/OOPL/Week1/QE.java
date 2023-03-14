import java.util.Scanner;
import java.lang.*;

class QE
{
	public static void QuadraticEquation(double a, double b, double c)
	{
	   double d;
	   int flag;
	   d = b*b-4*a*c;
	   double root1,root2,imaginary1,imaginary2;


	   if(d>0)
	   {
	   	 flag = 1;
	   }

	   else if(d==0)
	   {
	   	 flag = 2;
	   }

	   else 
	   {
	   	 flag = 3;
	   }

	   switch(flag)
	   {
	   	 
	   	 case 1:
         root1 = (-b + Math.sqrt(d))/(2*a);
	   	 root2 = (-b - Math.sqrt(d))/(2*a);
	   	 System.out.println("The Roots are " + root1 + " and" + root2);
	   	 System.out.println("Real & Distinct.");
	   	 break;
	   

	     case 2:
         root1 = root2 = -b/(2*a);
	   	 System.out.println("The Roots are " + root1 + " and" + root2);
	   	 System.out.println("Real & Equal.");
	   	 break;
	   

	     case 3:
         root1 = root2 = -b/(2*a);
	   	 imaginary1 = d;
	   	 imaginary2 = -d;
         System.out.println("The Roots are " + root1  + imaginary1 + "i and" + root2 + "+"+ imaginary2 + "i");
         System.out.println("Imaginary.");
         break;
	   
	   }

	}
	public static void main(String[] args)
	{
		double a,b,c;
	   
	   Scanner obj = new Scanner(System.in);
	   System.out.println("Enter the Coefficient of x^2 : ");
	   a = obj.nextDouble();

	   System.out.println("Enter the Coefficient of x : ");
	   b = obj.nextDouble();

	   System.out.println("Enter the Constant : ");
	   c = obj.nextDouble();

	   QuadraticEquation(a,b,c);

    }
}