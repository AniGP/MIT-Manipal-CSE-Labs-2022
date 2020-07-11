import java.util.Scanner;

class NumberFormat
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a Number : ");
		String n = sc.next();
		String num = "";
		int c = 0;
		
		for(int i = n.length()-1 ; i >= 0 ; i --)
		{
			char ch = n.charAt(i);
			num = ch + "" + num;
			c++;
		
		if(c%3==0)
		{
    		num = ","+num;
		}

		System.out.println("Formatted Number = " + num);
	}
}