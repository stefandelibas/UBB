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
	@Override
	public PrgState getCrtPrg()
	{
		return list.get(index);
	}

	@Override
	public void logPrgStateExec() throws IOException {
		PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
		logFile.append(list.get(index).toString());
		logFile.flush();		
	}
}
