package model;

public class PrintStmt implements IStmt {

	Exp exp;
	
	public PrintStmt(Exp e)
	{
		exp = e;
	}
	
	@Override
	public String toString()
	{
		return "print(" +exp.toString()+")";
	}
	
	@Override
	public PrgState execute(PrgState state) {
		MyIList<Integer> out = state.getOut();
		try {
			out.add(exp.eval(state.getSymTable(),state.getHeap()));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			
		}
		return null;
	}

}
