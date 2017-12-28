package model;

import java.util.Map;

public class Heap<T1, T2> extends MyTable<T1, T2> {

	static int i;
	
	public Heap()
	{
		super();
		i=0;
		
	}
	
	public Map<T1,T2> getContent()
	{
		return this.dict;
		
	}
	public static int getNextLocation()
	{
		i++;
		return i;
	}
	
	
	
}
