import java.util.Scanner;

class CurrentDate
{
	int day;
	int month;
	int year;
	boolean checkLeap(int year)
	{
        return (((year % 4 == 0) & (year % 100 != 0)) | 
            (year % 400 == 0)); 
	}
	void createDate(int day,int month,int year) throws InvalidDayException,InvalidMonthException
	{
		this.year=year;

		if(month<=12 & month>=1)
		{
			this.month=month;
		}
		else throw new InvalidMonthException();


		if(checkLeap(year))
		{
			if(month==2 & day<=29 & day>=1)
			{
				this.day=day;
			}
			else 
			{
				throw new InvalidDayException(true);
			}
		}
		else 
		{
			if((month==2 & day<=28 & day>=1)|(month!=2 & day<=30 & day>=1)) 
			{
			this.day=day;
			}
			else
			{
				throw new InvalidDayException(false);
			}
		}
	}

	public String toString()
	{
		return "Day : " + day + "Month : " + month + " Year: " + year;
	}
}

class InvalidDayException extends Exception
{
	InvalidDayException(boolean b)
	{
		if(b)
			System.out.println("Year is Leap Year, and day is not in bound.");
		else
			System.out.println("Year is not Leap Year, and day is not in bound.");
	}
}
class InvalidMonthException extends Exception
{
	InvalidMonthException()
	{
		System.out.println("Month isn't between bounds.");
	}
}



class mdate
{
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Date, Month and Year : ");
		
		int day=sc.nextInt();
		int month=sc.nextInt();
		int year=sc.nextInt();
		
		CurrentDate cd=new CurrentDate();
		
		try
		{

			cd.createDate(day,month,year);
			System.out.println(cd);
		}
		
		catch(InvalidDayException e){
		}
		
		catch(InvalidMonthException e){
		}

	}
}