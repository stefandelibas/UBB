package model;

public class ReadHeap extends Exp {

	private String var;

	public ReadHeap(String var)
	{
		this.var = var;
	}
	
	@Override
	int eval(MyIDictionary<String, Integer> tbl,MyIDictionary<Integer, Integer> heap) throws Exception {
		
		Integer pos = tbl.lookup(var);
		if(pos == null)
			throw new Exception("invalid variable name, not in symtable");
		Integer value = heap.lookup(pos);
		if(value  == null)
			throw new Exception("invalid address, not in heap");
		return value;

	}
	
	@Override
	public String toString()
	{
		return "rh(" + this.var + ")";
	}

	

}
