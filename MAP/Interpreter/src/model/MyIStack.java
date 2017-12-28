package model;

public interface MyIStack<T> {
	T pop();
	
	void push(T v);
	
	boolean isEmpty();

	T peek();
	
	
}
