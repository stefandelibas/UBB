package model;

public class CompStmt implements IStmt {

	IStmt first;
    IStmt snd;
    public CompStmt(IStmt f, IStmt s) {
		first = f;
		snd = s;
	}

    @Override
	public String toString()
    {
    	return "("+first.toString() + ";" + snd.toString()+")";
    }

    @Override
	public PrgState execute(PrgState state)
    {
		MyIStack<IStmt> stk = state.getStk();
	    stk.push(snd);
	    stk.push(first);
	    return state;
	}

}
