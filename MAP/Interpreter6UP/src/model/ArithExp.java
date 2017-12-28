package model;

public class ArithExp extends Exp {

    Exp e1;
    Exp e2;
    char op;
    
    public ArithExp(char op,Exp e2,Exp e1)
    {
    	this.e1 = e1;
    	this.e2 = e2;
    	this.op = op;
    }
	@Override
	int eval(MyIDictionary<String,Integer> tbl,MyIDictionary<Integer,Integer> heap) throws Exception 
	{
		switch(op)
		{
			case '+':
				return (e1.eval(tbl,heap) + e2.eval(tbl,heap));
			case '-':
				return (e1.eval(tbl,heap) - e2.eval(tbl,heap));
			case '*':
				return (e1.eval(tbl,heap) * e2.eval(tbl,heap));
			case '/':
				if(e2.eval(tbl,heap) != 0)
					return (e1.eval(tbl,heap) / e2.eval(tbl,heap));
				else
					throw new Exception("Division by zero. Not permitted!");
		}
		return 0;
	}

	public String toString()
	{
		switch(op)
		{
			case '+':
				return e1.toString() + "+" + e2.toString();
			case '-':
				return e1.toString() + "-" + e2.toString();
			case '*':
				return e1.toString() + "*" + e2.toString();
			case '/':
				return e1.toString() + "/" + e2.toString();
			default:
				return "";
		}
	}

}
