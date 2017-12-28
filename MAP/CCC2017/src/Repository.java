import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Repository {

	List<Client> clients = new ArrayList<Client>();
	List<Transaction> transactions = new ArrayList<Transaction>();
	Integer nacc;
	public Repository()
	{}
	
	public Client getClient1(String name)
	{
		for(int i=0;i<clients.size();i++)
		{
			
			if(clients.get(i).name.equals(name))
			{
				return clients.get(i);
			}
		}
		return null;
	}
	public Client getClient(String acc)
	{
		for(int i=0;i<clients.size();i++)
		{
			
			if(clients.get(i).accnr.equals(acc))
			{
				return clients.get(i);
			}
		}
		return null;
	}
	public boolean findCh(String str,char c)
	{
		for(int i =0;i<str.length();i++)
		{
			if(str.charAt(i) == c)
				return true;
		}
		return false;
	}
	public int validateAccount(Client c)
	{
		String acc=c.accnr;
		if(!acc.substring(0,3).equals("CAT"))
			return 0;

		String ceva = acc.substring(5);
		Integer sum=0;
		for(int i =0;i<ceva.length();i++)
		{
			char ch = ceva.charAt(i);
			//System.out.println(ch);

			if(Character.isUpperCase(ch))
			{
				char lch = Character.toLowerCase(ch);
				if(findCh(ceva,lch) == false)
					return 0;
			}
			else
				if(Character.isLowerCase(ch))
				{
					char uch = Character.toUpperCase(ch);
					if(findCh(ceva,uch) == false)
					{
						return 0;
					}
				}
						
		}
		for(int i=0;i<ceva.length();i++)
		{
			char ch = ceva.charAt(i);
			sum = sum + (int)ch;
			//System.out.println(ch+" "+(int)ch);
		}
		
		String ccc= "CAT00";
		for(int i=0;i<ccc.length();i++)
		{
			char ch = ccc.charAt(i);
			sum = sum + (int)ch;
			//System.out.println(ch+" "+(int)ch);
		}
		
		System.out.println(sum);

		String checkstr = acc.substring(3,5);
		//System.out.println(checkstr);
		Integer checksum = Integer.parseInt(checkstr);
		//System.out.println(checksum);

		if(checksum != 98-(sum%97))
			return 0;
		
		return 1;
	}
	public void storeToFile() throws IOException
	{
		
		BufferedWriter bw=new BufferedWriter(new FileWriter("out.txt"));
		StringBuilder sb = new StringBuilder();
		String line = Integer.toString(nacc);
		sb.append(line);
        sb.append(System.lineSeparator());
        for(int i=0;i<nacc;i++)
        {
        	String c = clients.get(i).name+ " "+ Integer.toString(clients.get(i).balance);
        	sb.append(c);
        	if(i != nacc-1)
        		sb.append(System.lineSeparator());
        }
        String everything = sb.toString();
        bw.write(everything);
		bw.close();     
        
	}
	public void readFromFile() throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		String line = br.readLine();
		Integer nc = Integer.parseInt(line);
		nacc = nc;
		
		for(int i=0;i<nc;i++)
		{
			line = br.readLine();
			String[] parts = line.split(" ");
			Integer sumc = Integer.parseInt(parts[2]);
			String accnr=parts[1];
			Integer lim = Integer.parseInt(parts[3]);
			
			
			Client c = new Client(parts[0],sumc,accnr,lim);
			if(validateAccount(c) == 1)
			{	
				System.out.println(c.name);
				clients.add(c);
			}
			else nacc--;
			
		}
		line = br.readLine();
		Integer nt = Integer.parseInt(line);
		
		for(int i=0;i<nt;i++)
		{
			line = br.readLine();
			
			String[] parts = line.split(" ");
			String accnr1=parts[0];
			String accnr2=parts[1];
			Integer sumt = Integer.parseInt(parts[2]);
			Long tm = Long.parseLong(parts[3]);
			//System.out.println(accnr1+" "+accnr2+" "+sumt+" "+tm+"\n");
			
			if(getClient(accnr1) == null || getClient(accnr2) == null)
				return;
			Client c1 = getClient(parts[0]);
			Client c2 = getClient(parts[1]);
			Transaction t = new Transaction(c1,c2,sumt,tm);		
			transactions.add(t);
		}
		
		br.close();
	}
}
