package model;

public class AssignStmt implements IStmt {

    String id;
    Exp exp;
    
    public AssignStmt(String str,Exp e)
    {
    	id = str;
    	exp = e;
    }
    
    @Override
    public String toString()
    {
    	return id + "=" + exp.toString();
    }

	@Override
	public PrgState execute(PrgState state)
	{
        
        MyIDictionary<String,Integer> symTbl= state.getSymTable();
        int val = 0;
        try
        {
        	val = exp.eval(state.getSymTable(),state.getHeap());
        	if (symTbl.containsKey(id) == true)
            	symTbl.update(id, val);
            
            else 
            	symTbl.put(id,val); 
            return state;
        }
        catch(Exception e)
        {
        	System.out.println(e);
        	return null;
        }
        
	}

}
