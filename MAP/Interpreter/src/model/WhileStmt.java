package model;

public class WhileStmt implements IStmt {

	private Exp e;
	private IStmt s;
	public WhileStmt(Exp exp,IStmt stmt)
	{
		e = exp;
		s = stmt;
	}
	@Override
	public PrgState execute(PrgState state) {
		try {
			MyIStack<IStmt> stk = state.getStk();
			if(e.eval(state.getSymTable(), state.getHeap()) != 0)
				{
					IStmt wstmt = new WhileStmt(e,s);
					stk.push(wstmt);
					stk.push(s);
				}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return state;
	}
	public IStmt getStatement() {
		return s;
	}
	public void setStatement(IStmt s) {
		this.s = s;
	}
	@Override
	public String toString()
	{
		return "(while("+e.toString()+")"+s.toString()+")";
	}

}
