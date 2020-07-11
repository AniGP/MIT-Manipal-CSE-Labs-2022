import java.util.*;

public interface Series 
{
	
	int getNext ();
	void reset ();
	void setStart (int strt);
	
}

public class ByTwos implements Series 
{

	private int k;
	
	public void setStart (int strt) 
	{
		k = strt;
	}

	public int getNext () 
	{
		k += 2;
		return k;
	}
	
	public void reset () 
	{
		k = 0;
	}
}

public class ByTwosTest
 {

	public static void main (String [] args) 
	{
	
		Series s = new ByTwos();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n\tEnter start value: ");
		int start = sc.nextInt();
		s.setStart(start);
		
		int ch;	
		
		do 
		{
			System.out.print("\n\t1. Next term\n\t2. Reset to start\n\tElse exit\n\tChoice: ");
			ch = sc.nextInt();
			
			if (ch == 1)
			{
				System.out.println("\n\tNext element: " + s.getNext());
			}
			else if (ch == 2) 
			{
				System.out.println("\n\tResetting to start...");
				s.setStart(start);
			}
			else
			{
				System.exit(0);
			}

		} while (ch > 0 && ch < 3);
		
	}
}