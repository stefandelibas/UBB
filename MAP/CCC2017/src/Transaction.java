
public class Transaction {
	public Client c1;
	public Client c2;
	public Integer sum;
	public Long time;
	

	public Transaction(Client c12, Client c22, Integer sumt, Long tm) {
		this.c1=c12;
		this.c2=c22;
		sum=sumt;
		time=tm;
	}
	public void executeTransaction() throws Exception
	{				System.out.println(c1.name+c1.balance);

		System.out.println("\t"+sum);

		if(c1.balance + (c1.lim) < sum)
			return;
		c2.balance = c2.balance + sum;
		c1.balance = c1.balance - sum;
		//System.out.println(c1.name+c1.balance);

	}
	
	
}
