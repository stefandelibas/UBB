package model;

public abstract class Exp {

	abstract int eval(MyIDictionary<String,Integer> tbl,MyIDictionary<Integer,Integer> heap) throws Exception ;
}
