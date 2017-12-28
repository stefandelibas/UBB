package model;

public class ConstExp extends Exp {

	Integer number;
	public ConstExp(Integer i)
	{
		number = i;
	}

	@Override
	int eval(MyIDictionary<String,Integer> tbl,MyIDictionary<Integer,Integer> heap) 
	{
		return number;
	}

	 @Override
    public String toString()
    {
    	return number.toString();
    }
}
