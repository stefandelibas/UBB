package model;

import java.util.Stack;

public class MyStack<T> implements MyIStack<T> {
	
	Stack<T> stk;
	
	public MyStack()
	{
		stk = new Stack<T>();
	}

	@Override
	public T pop() {
		return stk.pop();
	}

	@Override
	public void push(T v) {
		stk.push(v);
		
	}

	@Override
	public boolean isEmpty() {
		return stk.empty();
	}

	@Override
	public T peek() {
		return stk.peek();
	}
	
	@Override
	public String toString()
	{
		String str="";
		for(T e:stk)
			str = str + " " + e.toString();
		return str;
	}

}
