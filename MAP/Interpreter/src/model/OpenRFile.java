package model;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class OpenRFile implements IStmt {
	String filename;
	String var_file_id;
	
	public OpenRFile(String var_f,String filename)
	{
		this.filename = filename;
		var_file_id = var_f;
	}
	
	@Override
	public PrgState execute(PrgState state)  {
		MyIDictionary<Integer, FileTuple<String,BufferedReader>> fileTable = state.getFileTable();
		
		if( fileTable.containsValue(new FileTuple<String,BufferedReader>(filename,null)) == true)
			System.out.println("the filename is already in the fileTable");
		BufferedReader br = null;
		try 
		{
			br = new BufferedReader(new FileReader(this.filename));
		} 
		catch (FileNotFoundException e) {
			System.out.println("the filename does not exists");
		}
		int n = MyTable.getNextDescriptor();
		fileTable.put(n,new FileTuple<String,BufferedReader>(filename,br));

		state.getSymTable().put(var_file_id,n); 
		return state;
	}
	@Override
	public String toString()
	{
		return "open(" + this.filename + ")";
	}

}
