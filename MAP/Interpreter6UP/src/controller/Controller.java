package controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

import model.*;

import repository.IRepository;

public class Controller {

	IRepository repo;
	ExecutorService executor;
	
	public Controller(IRepository r)
	{
		repo = r;
	}
	IRepository getRepo()
	{
		return repo;
	}
	 
	void oneStepForAllPrg(List<PrgState> prgList) throws InterruptedException {
		//before the execution, print the PrgState List into the log file
		prgList.forEach(prg ->repo.logPrgStateExec(prg));
		
		//prepare the list of callables
		List<Callable<PrgState>> callList = prgList.stream()
			                                      .map((PrgState p) -> (Callable<PrgState>)(() -> {return p.oneStep();}))
			                                      .collect(Collectors.toList());
		//start the execution of the callables
		//it returns the list of new created PrgStates (namely threads)
		List<PrgState> newPrgList  = executor.invokeAll(callList).stream()
													.map(future -> {
																		try {
																			return future.get();
																		}
	                                                                    catch(Exception e) {
	                                                                		System.out.println(e.getMessage());
	                                                                    }
																		return null;
                                                          		 	}
														)
	                                                .filter(p -> p!=null)
	                                                .collect(Collectors.toList());
		
		prgList.addAll(newPrgList);
		
		//after the execution, print the PrgState List into the log file
		prgList.forEach(prg ->repo.logPrgStateExec(prg));  
		
		//Save the current programs in the repository
		repo.setPrgList(prgList);
	}
	
	public void allStep() {
	    executor = Executors.newFixedThreadPool(2);
	    //remove the completed programs
	    List<PrgState>  prgList=removeCompletedPrg(repo.getPrgList());
	    while(prgList.size() > 0){
	         try {
				oneStepForAllPrg(prgList);
			} catch (InterruptedException e) {
				System.out.println(e.getMessage());
			}
	         //remove the completed programs  
	         prgList = removeCompletedPrg(repo.getPrgList());
	     }
	     executor.shutdownNow();
	     //HERE the repository still contains at least one Completed Prg 
	     // and its List<PrgState> is not empty. Note that oneStepForAllPrg calls the method
	     //setPrgList of repository in order to change the repository
	     // update the repository state 
	     repo.setPrgList(prgList); 
	     
	     prgList.forEach(prg ->repo.logPrgStateExec(prg));  
	     
	 }
	
	List<PrgState> removeCompletedPrg(List<PrgState> inPrgList) 
    {
    	  return inPrgList.stream().filter(p -> p.isNotCompleted()).collect(Collectors.toList());
    }
	
    Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues, Map<Integer,Integer> heap)
    {
    		return heap.entrySet().stream()
    				.filter(e->symTableValues.contains(e.getKey()))
    				.collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }
	/*
    public void allStep()
    {
    	PrgState prg = repo.getCrtPrg(); 
    	
    	try{
    		while(true)
    		{
    			System.out.println(prg.toString());
    			oneStep(prg); 
    			
    			prg.getHeap().setContent(
    									conservativeGarbageCollector(
											    		              prg.getSymTable().getContent().values(),   
											    		              prg.getHeap().getContent())
    									);
    		              
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
    		
    		prg.getFileTable().getValues().forEach(v->{
												try {
													v.getSecond().close();
												} catch (IOException e) {
													e.printStackTrace();
												}
											}
    									)
    		
    		prg.getFileTable().getKeys().forEach(v->new CloseRFile(new ConstExp(v)).execute(prg));
    		System.out.println(prg.toString());
    		
      	}
   	}
   */
    
    
}
