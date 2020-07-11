import java.util.*;
import java.text.*;

class Person
{
	private String name;
	private GregorianCalendar dob;

	public Person()
	{
		name = "";
		dob = new GregorianCalendar();
	}

	public void setName(String n)
	{
       name = n;
	}

	public void setDOB(GregorianCalendar DOB)
	{
		dob =  DOB;
	}

	public String getName()
	{
		return name;
	}

	public GregorianCalendar getDOB()
	{
		return dob;
	}

	public void input()
	{
		Scanner sc = new Scanner(System.in);

		System.out.println("Name : ");
		name = sc.nextLine();

		System.out.println("Enter DOB (yyyy/mm/dd) : ");
		dob = new GregorianCalendar(sc.nextInt(),sc.nextInt()-1,sc.nextInt());
	}

	public void display()
	{
		SimpleDateFormat dateFormat = new SimpleDateFormat("MMM,dd,yyyy");
		System.out.println("Name : " + name + "||" + "DOB : " + dateFormat.format(dob.getTime()));
	}
}

class CollegeGraduate extends Person
{
	private double gpa;
	private int grad;

	public CollegeGraduate()
	{
		super();
		gpa = 0.0;
		grad = 0;
	}

	public double getGPA()
	{
		return gpa;
	}

	public int getGrad()
	{
		return grad;
	}

	public void input()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Name : ");
		setName(sc.nextLine());

		System.out.println("DOB(yyyy/mm/dd) : ");
		GregorianCalendar db = new GregorianCalendar(sc.nextInt(),sc.nextInt()-1,sc.nextInt());
        
        setDOB(db);

        System.out.println("Year of Graduation : ");
        grad = sc.nextInt();
    }

    public void display()
    {
    	super.display();
    	System.out.println("GPA : " + gpa + "Graduation : " + grad);
    }
}

public class PersonTest
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int ch;
		System.out.println("1.)Person || 2.)CollegeGraduate || 3.)Quit || Choice ");
		ch = sc.nextInt();

		switch(ch)
		{
			case 1:

			Person person = new Person();
			person.input();
			person.display();
			break;

			case 2:
			CollegeGraduate cg = new CollegeGraduate();
			cg.input();
			cg.display();

			default:
			break;
		}
	}
}