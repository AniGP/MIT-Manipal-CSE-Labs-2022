import java.util.*;

class ByTwos implements Series
{
	int start;
	int val;

	ByTwos()
	{
		start=0;
		val=0;
	}

	public int getNext()
	{
		val+=2;
		return val;
	}

	public void reset()
	{
		val = start;
	}

	public void setStart(int x)
	{
		start=x;
		val=x;
	}
}

class SeriesDemo
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		ByTwos ob = new ByTwos();
		
		System.out.println("Enter Limit : ");
		int l = sc.nextInt();

		System.out.println("Enter Start : ");
		int s = sc.nextInt();
			
		for(int i=s; i<l; i++)
		{
			System.out.println("Next : " + ob.getNext());
		}

		System.out.println("Resetting..........");
		ob.reset();

		for(int i=s;i<l;i++)
		{
           System.out.println("Next : " + ob.getNext());
		}

		System.out.println("Enter Value : ");
		int val = sc.nextInt();

		ob.setStart(val);

		for(int i=val;i<l;i++)
		{
           System.out.println("Next : " + ob.getNext());
		}
	}
}



