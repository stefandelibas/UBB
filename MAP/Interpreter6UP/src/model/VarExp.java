package model;

public class VarExp extends Exp {

	String id;

	public VarExp(String str) 
	{
		id = str;
	}
	
	@Override
	int eval(MyIDictionary<String,Integer> tbl,MyIDictionary<Integer,Integer> heap) throws Exception
	{
		if(tbl.lookup(id) == null)
			throw new Exception();
		return tbl.lookup(id);
	}

	@Override
	public String toString()
	{
		try 
		{
			return id;
		}
		catch (Exception e) {}
		return "variable not recognized";
	}
	
}
