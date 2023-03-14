import java.util.*;

class NumericFns<T extends Number>
{
	T num;

	NumericFns(T n)
	{
		num = n;
	}

	double reciprocal()
	{
		return 1/num.doubleValue();
	}

	double fraction()
	{
		return (num.doubleValue() - num.intValue());
	}

	boolean absEqual(NumericFns<?> ob)
	{
		if(Math.abs(num.doubleValue()) == Math.abs(ob.num.doubleValue()))
		{
			return true;
		}

		return false;
	}
}

class p4
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter Integer : ");
		int i = sc.nextInt();

		System.out.println("Enter Double Integer : ");
		double d = sc.nextDouble();

		NumericFns<Integer> iOb = new NumericFns<Integer>(i);
		NumericFns<Double> dOb = new NumericFns<Double>(d);

		System.out.println("Testing iOb and dOb.....");
		
		if(iOb.absEqual(dOb))
		{
			System.out.println("Absolute values are equal.");
		}

		else
		{
			System.out.println("Absolute values are not equal.");
		}
	}
}