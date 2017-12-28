package model;

public class BooleanExp extends Exp {

	Exp e1;
    Exp e2;
    String op;
    
    public BooleanExp(String op,Exp e2,Exp e1)
    {
    	this.e1 = e1;
    	this.e2 = e2;
    	this.op = op;
    }
    private int BooleanToInt(boolean b)
    {
    	if(b == true)
    		return 0;
    	return 1;
    }
	@Override
	int eval(MyIDictionary<String,Integer> tbl,MyIDictionary<Integer,Integer> heap) throws Exception 
	{
		switch(op)
		{
			case ">":
				return BooleanToInt(e1.eval(tbl,heap) > e2.eval(tbl,heap));
			case ">=":
				return BooleanToInt(e1.eval(tbl,heap) >= e2.eval(tbl,heap));
			case "<":
				return BooleanToInt(e1.eval(tbl,heap) < e2.eval(tbl,heap));
			case "<=":
				return BooleanToInt(e1.eval(tbl,heap) <= e2.eval(tbl,heap));
			case "==":
				return BooleanToInt(e1.eval(tbl,heap) == e2.eval(tbl,heap));
			case "!=":
				return BooleanToInt(e1.eval(tbl,heap) != e2.eval(tbl,heap));
				
				
		}
		return 0;
	}

	public String toString()
	{
		switch(op)
		{
			case ">":
				return e1.toString() + ">" + e2.toString();
			case ">=":
				return e1.toString() + ">=" + e2.toString();
			case "<":
				return e1.toString() + "<" + e2.toString();
			case "<=":
				return e1.toString() + "<=" + e2.toString();
			case "==":
				return e1.toString() + "==" + e2.toString();
			case "!=":
				return e1.toString() + "!=" + e2.toString();
			default:
				return "";
		}
	}

}
