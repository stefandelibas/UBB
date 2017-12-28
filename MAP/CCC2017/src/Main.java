
public class Main {

	public static void main(String[] args) throws Exception  {
		Repository repo = new Repository();
		
		try
		{
			repo.readFromFile();
		}
		catch(Exception e)
		{
			System.out.print("error1");
			
		}
		
		
		
		for(Transaction t:repo.transactions)
		{
			t.executeTransaction();
		}
		try {
			repo.storeToFile();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}

}
