package model;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseRFile implements IStmt {

	Exp exp;
	
	public CloseRFile(Exp exp_file_id)
	{
		this.exp = exp_file_id;
	}
	
	@Override
	public PrgState execute(PrgState state) {
		
		Integer key = null;

		try {
			key = (Integer) exp.eval(state.getSymTable(),state.getHeap());
		} catch (Exception e) {

		}
		MyIDictionary<Integer, FileTuple<String,BufferedReader>> fileTable = state.getFileTable();
		if(!fileTable.containsKey(key))
		{
			System.out.println("the file descriptor is not valid!");
			return state;
		}
		
		FileTuple<String,BufferedReader> fileTuple = fileTable.lookup(key);
		BufferedReader br = fileTuple.getSecond();
		try {
			br.close();
		} catch (IOException e) {
			
		}
		
		fileTable.remove(key);
		
		
		return null;
	}

}
