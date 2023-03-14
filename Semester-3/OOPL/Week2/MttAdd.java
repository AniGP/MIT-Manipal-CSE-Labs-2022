import java.util.Scanner;

class MttAdd
{
	static int[][] add(int a[][], int b[][])
	{
		int i,j;
		int c[][] = new int[3][3];

		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				c[i][j] = a[i][j]+b[i][j];
			}

		}

		return c;
	}

	public static void main(String[] args)
	{
		int i,j;
		int a[][] = new int[3][3];
		int b[][] = new int[3][3];
		int c[][] = new int[3][3];
		Scanner obj = new Scanner(System.in);

		System.out.println("Enter Elements for M1 : \n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				a[i][j] = obj.nextInt();

			}
		}

		System.out.println("Enter Elements for M2 : \n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				b[i][j] = obj.nextInt();

			}
		}

		c = add(a,b);

		System.out.println("Sum : \n");

		for(i=0;i<c.length;i++)
		{
			for(j=0;j<c[i].length;j++)
			{
				System.out.println(c[i][j] + " ");
			}

			System.out.println(" ");
		}
	}
}


