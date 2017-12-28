package repository;

import java.io.IOException;
import java.util.List;

import model.*;

public interface IRepository {
	
	public List<PrgState> getPrgList();
	public void setPrgList(List<PrgState> ps);	
	void logPrgStateExec(PrgState prg);
}
