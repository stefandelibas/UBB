package model;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements MyIList<T> {

	
	List<T> list;
	
	public MyList()
	{
		list = new ArrayList<T>();
	}
	
	@Override
	public void add(T i) {
		list.add(i);

	}

	@Override
	public void remove(T i) {
		list.remove(i);

	}

	@Override
	public String toString()
	{
		String str="";
		for(T t:list)
			str = str + " " + t;
		return str;
	}
}
