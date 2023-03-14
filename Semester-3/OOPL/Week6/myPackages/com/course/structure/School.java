package com.course.structure;
import java.util.*;

public class School extends Building
{
	public int classes;
	public String grade;

	public void setClass(int nclasses)
	{
	   this.classes = nclasses;
	}

	public void setGrade(String grade)
	{
	    this.grade = new String(grade);
	}

	public int getClasses()
	{
        return classes;
	}

	public String getGrade()
	{
        return grade;
	}
}