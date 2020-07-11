import java.util.Scanner;

class Phone
{
	String brand;
	int memCapacity;
	interface Callable
	{
		public void makeAudioCall(String cellNum);
		public void makeVideoCall(String cellNum);
	}
}
class BasicPhone extends Phone implements Phone.Callable
{
	//BasicPhone(){;}
	BasicPhone(String brand,int memCapacity)
	{
		this.brand=brand;
		this.memCapacity=memCapacity;
	}
	public void makeVideoCall(String cellNum)
	{
		System.out.println("VC intiated in "+cellNum+" of "+brand+" BasicPhone with capacity "+memCapacity);
	}
	public void makeAudioCall(String cellNum)
	{
		System.out.println("AC intiated in "+cellNum+" of "+brand+" BasicPhone with capacity "+memCapacity);
	}
}
class Smartphone extends Phone implements Phone.Callable
{
	Smartphone(String brand,int memCapacity)
	{
		this.brand=brand;
		this.memCapacity=memCapacity;
	}
	public void makeVideoCall(String cellNum)
	{
		System.out.println("VC intiated to" +cellNum+" of "+brand+" SmartPhone with capacity "+memCapacity);
	}
	public void makeAudioCall(String cellNum)
	{
		System.out.println("AC intiated in "+cellNum+" of "+brand+" SmartPhone with capacity "+memCapacity);
	}
}
class mphone
{
	public static void main(String[] args) 
	{
		System.out.println("Enter Brand and memory of Basic Phone");
		Scanner sc=new Scanner(System.in);
		
		String basicbrand=sc.nextLine();
		int basiccap=sc.nextInt();

		System.out.println("Enter Brand and memory of Smartphone");
		sc.nextLine();
		String smartbrand=sc.nextLine();
		int smartcap=sc.nextInt();

		BasicPhone bp=new BasicPhone(basicbrand,basiccap);
		Smartphone sp=new Smartphone(smartbrand,smartcap);

		System.out.println("Enter Phone Number");
		sc.nextLine();
		String ph_numb=sc.nextLine();


		bp.makeAudioCall(ph_numb);
		bp.makeVideoCall(ph_numb);
		sp.makeVideoCall(ph_numb);
		sp.makeAudioCall(ph_numb);
	}
}