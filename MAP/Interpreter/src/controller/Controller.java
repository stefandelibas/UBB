package controller;

import java.util.Collection;
import java.util.Map;
import java.util.stream.Collectors;

import model.*;

import repository.IRepository;

public class Controller {

	IRepository repo;
	public Controller(IRepository r)
	{
		repo = r;
	}
	IRepository getRepo()
	{
		return repo;
	}
	 PrgState oneStep(PrgState state) throws Exception
	 {
	     MyIStack<IStmt> stk=state.getStk();
	     if(stk.isEmpty()) 
	    	 throw new Exception("stack is empty.program terminated!");
	     
	     IStmt crtStmt = stk.pop(); 
	     //System.out.println(crtStmt.toString());
	     return crtStmt.execute(state);
	 }
	 
    public void allStep()
    {
    	PrgState prg = repo.getCrtPrg(); 
    	
    	try{
    		while(true)
    		{
    			System.out.println(prg.toString());
    			oneStep(prg); 
    			
    			prg.getHeap().setContent(conservativeGarbageCollector(
    		              prg.getSymTable().getContent().values(),   
    		              prg.getHeap().getContent()));
    		              
    			//repo.logPrgStateExec(); 
       		}
    	}
    	catch(Exception e) 
    	{
    		System.out.println(prg.toString());
    		System.out.println(e.getMessage());
    		//e.printStackTrace();
    	}
    	finally
    	{
    		prg.getFileTable().getKeys().forEach(v->new CloseRFile(new ConstExp(v)).execute(prg));
    		System.out.println(prg.toString());
    	}
   }
    
    Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues, Map<Integer,Integer> heap)
    {
    		return heap.entrySet().stream().
    				filter(e->symTableValues.contains(e.getKey())).
    				collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }
    
}
