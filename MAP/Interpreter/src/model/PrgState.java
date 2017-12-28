package model;

import java.io.BufferedReader;

public class PrgState {

	private MyIStack<IStmt> exeStack;
	private MyIDictionary<String, Integer> symTable;
	private MyIList<Integer> out;
	private MyIDictionary<Integer, FileTuple<String,BufferedReader>> fileTable;
	private MyIDictionary<Integer, Integer> heap;
	IStmt originalProgram; 
   
	public PrgState(MyIStack<IStmt> stk, MyIDictionary<String,Integer> symtbl,MyIList<Integer> o,MyIDictionary<Integer, FileTuple<String,BufferedReader>> t, MyIDictionary<Integer, Integer> h)
	{
		exeStack = stk;
		symTable = symtbl;
		out = o;
		fileTable = t;
		heap = h;
	}
	public MyIDictionary<Integer, FileTuple<String, BufferedReader>> getFileTable()
	{
		return fileTable;
	}
	public MyIStack<IStmt> getStk()
	{
		return exeStack;
	}
	public MyIDictionary<String, Integer> getSymTable()
	{
		return symTable;
	}
	public MyIList<Integer> getOut()
	{
		return out;
	}
	
	public  MyIDictionary<Integer, Integer> getHeap()
	{
		return this.heap;
	}
	
	@Override
	public String toString()
	{
		return "\nExeStack:\n" + exeStack.toString() + "\n" +
				"\nSymTable:\n"+ symTable.toString() + "\n" +
				"\nOut:\n"+ out.toString() +
				"\nFileTable:\n"+ fileTable.toString() +
				"\nHeap:\n"+ heap.toString() +
				"\n------------------\n";
	}
}
