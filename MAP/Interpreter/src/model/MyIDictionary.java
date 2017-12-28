package model;

import java.util.Map;
import java.util.Set;

public interface MyIDictionary<T1,T2> {
	
	public Object put(T1 key,T2 value);
	
	public Object remove(T1 key);
	
	void update(T1 key,T2 value);
	
	int size();
	
	boolean containsKey(T1 key);
	
	boolean containsValue(T2 value);

	public T2 lookup(T1 id);
	
	public Map<T1,T2> getContent();
	
	public void setContent(Map<T1,T2> mp);

	public Map<T1,T2> getTable();

	public Set<T1> getKeys();

}
