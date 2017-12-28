package model;

import java.util.Hashtable;

import controller.Controller;
import repository.Repository;

public class ForkStmt implements IStmt {

	IStmt stmt;
	public ForkStmt(IStmt s)
	{
		this.stmt = s;
	}
	@Override
	public PrgState execute(PrgState state) {
		MyIStack<IStmt> exeStack = new MyStack<IStmt>();
    	Hashtable<String,Integer> ht = new Hashtable<String,Integer>(state.getSymTable().getContent());
    	MyIDictionary<String, Integer> symTable = new SymTable<String, Integer>(ht);
    	exeStack.push(this.stmt);
		PrgState newState = new PrgState(exeStack,symTable,state.getOut(),state.getFileTable(),state.getHeap(),state.getId()*10);
		return newState;
	}
	
	@Override 
	public String toString()
	{
		return "fork(" + stmt.toString() + ")";
	}

}
