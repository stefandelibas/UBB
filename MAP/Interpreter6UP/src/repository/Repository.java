package repository;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import model.*;

public class Repository implements IRepository {

	List<PrgState> list;
	int index;
	String logFilePath;
	public Repository(PrgState prg,String filePath)
	{
		list = new ArrayList<PrgState>();
		list.add(prg);
		index = 0;
		this.logFilePath = filePath;
	}

	private void add(PrgState ps)
	{
		list.add(ps);
	}
	
	
	
	public List<PrgState> getPrgList()
	{
		return this.list;
	}
	public void setPrgList(List<PrgState> ps)
	{
		this.list = ps;
	}
	
	

	@Override
	public void logPrgStateExec(PrgState prg) {
		PrintWriter logFile = null;
		try {
			logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
		} catch (IOException e) {			
		}
		logFile.append(prg.toString());
		logFile.flush();		
	}
}
