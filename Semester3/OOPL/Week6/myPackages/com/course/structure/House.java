package com.course.structure;
import java.util.*;

public class House extends Building
{
	int beds;
	int baths;

	public void setBeds(int nbeds)
	{
	   this.beds = nbeds;
	}

	public void setBath(int nBaths)
	{
	    this.baths = nBaths;
	}

	public int getBed()
	{
        return beds;
	}

	public int getBath()
	{
        return baths;
	}
}