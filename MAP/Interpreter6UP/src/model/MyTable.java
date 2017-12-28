package model;

import java.util.Map;
import java.util.Map.Entry;

public class MyTable<T1,T2> extends MyDictionary<T1,T2> {

	static int i;
	
	public MyTable()
	{
		super();
		i = 1;
	}

	public static int getNextDescriptor()
	{
		i++;
		return i;
	}
	
	
	@Override
	public String toString()
	{
		String str = "";
		Map<T1,T2> d = dict;
		for ( Entry<T1, T2> entry : d.entrySet() ) {
		    T1 key = (T1) entry.getKey();
		    T2 value = (T2) entry.getValue();
		    str = str + key.toString() + "->" + value.toString() + "\n";
		}
		return str;
	}
	
	
}
