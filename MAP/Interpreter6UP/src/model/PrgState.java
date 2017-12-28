package model;

import java.io.BufferedReader;

public class PrgState {

	private MyIStack<IStmt> exeStack;
	private MyIDictionary<String, Integer> symTable;
	private MyIList<Integer> out;
	private MyIDictionary<Integer, FileTuple<String,BufferedReader>> fileTable;
	private MyIDictionary<Integer, Integer> heap;
	Integer id;
	IStmt originalProgram; 
   
	public PrgState(MyIStack<IStmt> stk, MyIDictionary<String,Integer> symtbl,MyIList<Integer> o,MyIDictionary<Integer, FileTuple<String,BufferedReader>> t, MyIDictionary<Integer, Integer> h,Integer i)
	{
		exeStack = stk;
		symTable = symtbl;
		out = o;
		fileTable = t;
		id = i;
		heap = h;
	}
	public Integer getId()
	{
		return this.id;
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
	
	public boolean isNotCompleted()
	{
		return !this.exeStack.isEmpty();
	}
	public PrgState oneStep() throws Exception
	{
		if(this.exeStack.isEmpty())
			throw new Exception("program terminated!");
		IStmt  crtStmt = exeStack.pop(); 
		return crtStmt.execute(this);
	}
	
	@Override
	public String toString()
	{
		return "\nid = " + id + 
				"\nExeStack:\n" + exeStack.toString() + 	
				"\nSymTable:\n"+ symTable.toString() +
				"\nOut:\n"+ out.toString() +
				"\nFileTable:\n"+ fileTable.toString() +
				"\nHeap:\n"+ heap.toString() +
				"\n------------------\n";
	}
}
