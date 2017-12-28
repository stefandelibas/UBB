package model;

public class IfStmt implements IStmt {

	Exp exp;
    IStmt thenS;
    IStmt elseS;
    
	public IfStmt(Exp e, IStmt t, IStmt el) 
	{
		exp = e; 
		thenS = t;
		elseS = el;
	}
	
	@Override
	public PrgState execute(PrgState state) 
	{
		MyIStack<IStmt> stk = state.getStk();
		try
		{
		if(exp.eval(state.getSymTable(),state.getHeap()) != 0)
			stk.push(thenS);
		else
			stk.push(elseS);
		}
		catch(Exception e){}
		return state;
	}
    
    public String toString()
    {
    	return "IF("+ exp.toString()+") THEN(" +thenS.toString()+")ELSE("+elseS.toString()+")";
    }


}
