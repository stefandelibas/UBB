package repository;

import java.io.IOException;
import java.util.Vector;

import model.*;

public interface IRepository {
	
	PrgState getCrtPrg();
	
	void logPrgStateExec()throws IOException;
}
