package model;

public class WriteHeap implements IStmt {

	private String var;
	private Exp e;
	
	public WriteHeap(String var,Exp e)
	{
		this.var = var;
		this.e = e;
	}

	@Override
	public PrgState execute(PrgState state) {
		MyIDictionary<Integer, Integer> heap = state.getHeap();
		Integer pos = state.getSymTable().lookup(var);
		
		if(pos == null)
			try {
				throw new Exception("invalid address");
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		if(!state.getHeap().containsKey(pos))
			try {
				throw new Exception("invalid address");
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		else
			try {
				heap.update(pos, e.eval(state.getSymTable(), heap));
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		return state;
	}
	
	@Override
	public String toString()
	{
		return "writeHeap(" + var + "," + e.toString() + ")";
	}
}
