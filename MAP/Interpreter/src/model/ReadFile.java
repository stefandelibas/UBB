package model;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements IStmt {

	String var_name;
	Exp exp;
	
	public ReadFile(Exp exp_file_id,String var_name)
	{
		this.exp = exp_file_id;
		this.var_name = var_name;
	}
	
	@Override
	public PrgState execute(PrgState state) {
		
		Integer key = null;
		Integer value = null;
		try {
			key = (Integer) exp.eval(state.getSymTable(),state.getHeap());
		} catch (Exception e) {
			
		}
		
		MyIDictionary<Integer, FileTuple<String,BufferedReader>> fileTable = state.getFileTable();
		
		
		if(fileTable.containsKey(key) == false)
		{
			System.out.println("the file descriptor is not valid!");
			return state;
		}
		
		FileTuple<String,BufferedReader> fileTuple = fileTable.lookup(key);
		
		BufferedReader br = fileTuple.getSecond();
		
		try {
			String str = br.readLine();
			if(str != null)
				value = Integer.parseInt(str);
			else
			{
				MyIDictionary<String,Integer> symTbl= state.getSymTable();
				symTbl.put(var_name,0); 
				return state;
			}
		} catch (IOException e) {
			
		}
		
		
		MyIDictionary<String,Integer> symTbl= state.getSymTable();
        try
        {
        	if (symTbl.containsKey(var_name) == true)
            	symTbl.update(var_name, value);
            
            else 
            	symTbl.put(var_name,value); 
            return state;
        }
        catch(Exception e)
        {
        	System.out.println(e);
        	return state;
        }
	}

}
