package model;

public class FileTuple<X,Y> extends Tuple<X, Y> {

	public FileTuple(X x, Y y) {
		super(x, y);
	}
	
	@Override
	public boolean equals(Object other)
	{
		if (other == this) {
            return true;
        }

        if (!(other instanceof Tuple)){
            return false;
        }

        Tuple<X,Y> other_ = (Tuple<X,Y>) other;

        return other_.x.equals(this.x) ;
	}
	

}
