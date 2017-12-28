package model;

public class New implements IStmt {
	
	private String var;
	private Exp e;
	
	public New(String var,Exp e)
	{
		this.var = var;
		this.e = e;
	}

	@Override
	public PrgState execute(PrgState state) {
		MyIDictionary<Integer, Integer> heap = state.getHeap();
		Integer pos = Heap.getNextLocation();
		try {
			heap.put(pos, this.e.eval(state.getSymTable(),state.getHeap()));
		} catch (Exception e) {
			e.printStackTrace();
		}
		if(state.getSymTable().containsKey(this.var))
			state.getSymTable().update(this.var, pos);
		else
			state.getSymTable().put(this.var, pos);
		return null;
	}
	
	@Override
	public String toString()
	{
		return "new(" + var + "," + e.toString() + ")";
	}

}
