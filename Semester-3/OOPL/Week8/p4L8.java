import java.util.*;
import java.lang.*;

class ThreadDemo extends Thread
{
	public void run()
	{
	   System.out.println("Inside run method.........");
	}
}

class p4L8
{
	public static void main(String[] args)
	{
	   ThreadDemo t1 = new ThreadDemo();
	   ThreadDemo t2 = new ThreadDemo();
	   ThreadDemo t3 = new ThreadDemo();

	   System.out.println("t1 Thread priority : " + t1.getPriority());
	   System.out.println("t2 Thread priority : " + t2.getPriority());
	   System.out.println("t3 Thread priority : " + t3.getPriority());

	   t1.setPriority(2);
	   t2.setPriority(6);
	   t3.setPriority(8);

	   System.out.println("t1 Thread priority : " + t1.getPriority());
	   System.out.println("t2 Thread priority : " + t2.getPriority());
	   System.out.println("t3 Thread priority : " + t3.getPriority());

	   System.out.println(Thread.currentThread().getName());

	   //System.out.println("Main Thread priority : " + Thread.t.getPriority());

	   //Thread.currentThread.setPriority(10);

	   //System.out.println("Main Thread priority : " + Thread.t.getPriority());
	}
}