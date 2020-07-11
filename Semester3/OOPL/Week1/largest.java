import java.util.Scanner;

class largest
{
   public static int largest3(int a,int b, int c)
   {
   	   return (a>b?(a>c?a:c):(b>c?b:c));
   }

   public static void main(String[] args)
   {
	   Scanner obj = new Scanner(System.in);
	   int a,b,c,ans;

	   System.out.println("Enter 1st Number : ");
	   a = obj.nextInt();

       System.out.println("Enter 2nd Number : ");
	   b = obj.nextInt();
    
       System.out.println("Enter 3rd Number : ");
	   c = obj.nextInt();

	   ans = largest3(a,b,c);

	   System.out.println("Largest Number is : " + ans);
    }
}


