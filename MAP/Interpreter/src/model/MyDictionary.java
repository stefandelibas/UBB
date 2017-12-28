package model;

import java.util.Hashtable;
import java.util.Map;
import java.util.Set;

public abstract class MyDictionary<T1, T2> implements MyIDictionary<T1, T2> {

	protected Map<T1,T2> dict;
	 
	public MyDictionary()
	{
		dict = new Hashtable<T1,T2>();
	}
	
	@Override
	public Object put(T1 key, T2 value) {
		return dict.put(key, value);
	}

	@Override
	public Object remove(T1 key) {
		return dict.remove(key);
	}

	@Override
	public int size() {
		return dict.size();
	}

	@Override
	public boolean containsKey(T1 key) {
		return dict.containsKey(key);
	}

	@Override
	public boolean containsValue(T2 value) {
		return dict.containsValue(value);
	}


	@Override
	public T2 lookup(T1 id) {
		return (T2)dict.get(id);
	}

	@Override
	public void update(T1 key,T2 value) {
		dict.replace(key, value);
		
	}
	
	public Map<T1,T2> getTable() {
		return this.dict;
	}

	@Override
	public Map<T1, T2> getContent() {
		
		return this.dict;
	}

	@Override
	public void setContent(Map<T1, T2> mp) {
		this.dict = mp;
		
	}
	public Set<T1> getKeys()
	{
		return dict.keySet();
	}
}
