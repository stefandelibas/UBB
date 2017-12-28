package ui;

import java.io.BufferedReader;
import java.util.Scanner;

import controller.Controller;
import model.*;
import repository.Repository;

public class Main {

	public static void main(String[] args) {
		
		//Scanner scan = new Scanner(System.in);
        //String filePath = scan.next();
        
		
    	MyIDictionary<String, Integer> symTable = new SymTable<String, Integer>();
    	MyIList<Integer> out = new MyList<Integer>();
		MyIDictionary<Integer , FileTuple<String, BufferedReader>> fileTable = new MyTable<Integer, FileTuple<String,BufferedReader >>();
		MyIDictionary<Integer, Integer> heap = new Heap<Integer,Integer>();
		

//-----------------------------------------------------------------------------------------------------------------------	
		//v=2;Print(v)
		MyIStack<IStmt> exeStack1 = new MyStack<IStmt>();
		  IStmt ex1 = new CompStmt(new AssignStmt("v",new ConstExp(2)), new PrintStmt(new VarExp("v")));
	    	exeStack1.push(ex1);
		 PrgState prg1 = new PrgState(exeStack1,symTable,out,fileTable,heap);
		Repository repo1 = new Repository(prg1,"log.txt");
        Controller ctrl1 = new Controller(repo1);
        
//-----------------------------------------------------------------------------------------------------------------------	
    	
    	
//-----------------------------------------------------------------------------------------------------------------------	
		//a=2+3*5;b=a+1;Print(b)
    	MyIStack<IStmt> exeStack2 = new MyStack<IStmt>();
    	PrgState prg2 = new PrgState(exeStack2,symTable,out,fileTable,heap);
		Repository repo2 = new Repository(prg2,"log.txt");
        Controller ctrl2 = new Controller(repo2);
    	
    	IStmt ex2 = new CompStmt(
    							new AssignStmt("a", new ArithExp('+',new ConstExp(2),new ArithExp('*',new ConstExp(3), new ConstExp(5)))),
    							new CompStmt(
    										new AssignStmt("b",new ArithExp('+',new VarExp("a"), new ConstExp(1))),
    										new PrintStmt(new VarExp("b"))
    										)
    							);
		exeStack2.push(ex2);
//-----------------------------------------------------------------------------------------------------------------------	
		
//-----------------------------------------------------------------------------------------------------------------------	    	
		//a=2-2;(If a Then v=2 Else v=3); Print(v)
		MyIStack<IStmt> exeStack3 = new MyStack<IStmt>();
		PrgState prg3 = new PrgState(exeStack3,symTable,out,fileTable,heap);
    	Repository repo3 = new Repository(prg3,"log.txt");
        Controller ctrl3 = new Controller(repo3);
        IStmt ex3 = new CompStmt(
        						new AssignStmt("a", new ArithExp('-',new ConstExp(2), new ConstExp(2))),
        						new CompStmt(
        									new IfStmt(new VarExp("a"),
        												new AssignStmt("v",new ConstExp(2)), 
        												new AssignStmt("v", new ConstExp(3))),
        									new PrintStmt(new VarExp("v"))
        									)
        						);
        exeStack3.push(ex3);
//-----------------------------------------------------------------------------------------------------------------------	
        
//-----------------------------------------------------------------------------------------------------------------------		
        MyIStack<IStmt> exeStack4 = new MyStack<IStmt>();
        PrgState prg4 = new PrgState(exeStack4,symTable,out,fileTable,heap);
    	Repository repo4 = new Repository(prg4,"log.txt");
        Controller ctrl4 = new Controller(repo4);
    	IStmt ex4 = new CompStmt(
    							new CompStmt(
    											new CompStmt(
    														//new ArithExp('+',ve,new ConstExp(2)
    														new OpenRFile("var_f","test.in"),
    														//new ReadFile(new ArithExp('+',new VarExp("var_f"),new ConstExp(2)), "var_c")
    														new ReadFile(new VarExp("var_f"), "var_c")    															
    														),
    											new CompStmt(
    		    										new PrintStmt(new VarExp("var_f")),
    		    										new IfStmt(
    		    														new VarExp("var_c"),
    		    														//new CompStmt(
    		    															//		 new ReadFile(new VarExp("var_f"), "var_c"),
    		    																	 new PrintStmt(new VarExp("var_c"))	
    		    																//	)
    		    																	 ,
    		    														new PrintStmt(new ConstExp(0))
    		    													  )
    		    										
    		    										)
    										),
    							new CloseRFile(new VarExp("var_f"))								  							
    							); 
    						
    	exeStack4.push(ex4);
//-----------------------------------------------------------------------------------------------------------------------	

//-----------------------------------------------------------------------------------------------------------------------	    	
		//v=10;new(v,20);new(a,22);print(v) 
		MyIStack<IStmt> exeStack5 = new MyStack<IStmt>();
		PrgState prg5 = new PrgState(exeStack5,symTable,out,fileTable,heap);
    	Repository repo5 = new Repository(prg5,"log.txt");
        Controller ctrl5 = new Controller(repo5);
        IStmt ex5 = new CompStmt(
        						new CompStmt(
        										new AssignStmt("v",new ConstExp(10)),
        										new New("v",new ConstExp(20))
        									),
        						new CompStmt(
        										new New("a",new ConstExp(22)),
        										new PrintStmt(new VarExp("v"))
        									)
        						);
        exeStack5.push(ex5);
//-----------------------------------------------------------------------------------------------------------------------	

//-----------------------------------------------------------------------------------------------------------------------	    	
  		//v=10;new(v,20);new(a,22);print(100+rH(v));print(100+rH(a))  
  		MyIStack<IStmt> exeStack6 = new MyStack<IStmt>();
  		PrgState prg6 = new PrgState(exeStack6,symTable,out,fileTable,heap);
      	Repository repo6 = new Repository(prg6,"log.txt");
          Controller ctrl6 = new Controller(repo6);
          IStmt ex6 = new CompStmt(
        		  					new CompStmt(
				          						new CompStmt(
				          										new AssignStmt("v",new ConstExp(10)),
				          										new New("v",new ConstExp(20))
				          									),
				          						new CompStmt(
				          										new New("a",new ConstExp(22)),
				          										new PrintStmt(new ArithExp('+',new ConstExp(100),new ReadHeap("v")))
				          									)
        		  								)
        		  					,
        		  					new PrintStmt(new ArithExp('+',new ConstExp(100),new ReadHeap("a")))
        	  						);
          exeStack6.push(ex6);
//-----------------------------------------------------------------------------------------------------------------------
          
//-----------------------------------------------------------------------------------------------------------------------	    	
          //v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a))
		MyIStack<IStmt> exeStack7 = new MyStack<IStmt>();
		PrgState prg7 = new PrgState(exeStack7,symTable,out,fileTable,heap);
		Repository repo7 = new Repository(prg7,"log.txt");
		  Controller ctrl7 = new Controller(repo7);
		  IStmt ex7 = new CompStmt(
					new CompStmt(
      						new CompStmt(
      										new AssignStmt("v",new ConstExp(10)),
      										new New("v",new ConstExp(20))
      									),
      						new CompStmt(
      										new New("a",new ConstExp(22)),
      										new WriteHeap("a",new ConstExp(30))
      									)
								)
					,
					new CompStmt(
								new PrintStmt(new VarExp("a")),
								new PrintStmt(new ReadHeap("a"))
								)
					);
		  exeStack7.push(ex7);
//-----------------------------------------------------------------------------------------------------------------------   
	
//----------------------------------------------------------------------------------------------------------------------- 
		  // v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a));a=0
		MyIStack<IStmt> exeStack8 = new MyStack<IStmt>();
		PrgState prg8 = new PrgState(exeStack8,symTable,out,fileTable,heap);
		Repository repo8 = new Repository(prg8,"log.txt");
		  Controller ctrl8 = new Controller(repo8);
		  IStmt ex8 = new CompStmt(
				  					new CompStmt(
												new CompStmt(
								  						new CompStmt(
								  										new AssignStmt("v",new ConstExp(10)),
								  										new New("v",new ConstExp(20))
								  									),
								  						new CompStmt(
								  										new New("a",new ConstExp(22)),
								  										new WriteHeap("a",new ConstExp(30))
								  									)
															)
												,
												new CompStmt(
															new PrintStmt(new VarExp("a")),
															new PrintStmt(new ReadHeap("a"))
															)
												),
				  					new AssignStmt("a",new ConstExp(0))
				  				);
		  exeStack8.push(ex8);
//-----------------------------------------------------------------------------------------------------------------------    
		 
//-----------------------------------------------------------------------------------------------------------------------	
		//v=10+(2<6);Print(v);a=(10+2)<6;Print(a);
		MyIStack<IStmt> exeStack9 = new MyStack<IStmt>();
		  IStmt ex9 = new CompStmt(
				  					new CompStmt(
				  								new AssignStmt("v",new ArithExp('+',new ConstExp(10),new BooleanExp("<",new ConstExp(2),new ConstExp(6)))),
				  								new PrintStmt(new VarExp("v"))
				  								),
				  					new CompStmt(
				  								new AssignStmt("a",new BooleanExp("<",new ArithExp('+',new ConstExp(10),new ConstExp(2)),new ConstExp(6))),
				  								new PrintStmt(new VarExp("a"))
				  								)
				  				 	);
	    	exeStack9.push(ex9);
		 PrgState prg9 = new PrgState(exeStack9,symTable,out,fileTable,heap);
		Repository repo9 = new Repository(prg9,"log.txt");
        Controller ctrl9 = new Controller(repo9);
        
//-----------------------------------------------------------------------------------------------------------------------	
//-----------------------------------------------------------------------------------------------------------------------	
  		//v=6; (while (v-4) print(v);v=v-1);print(v)
  		MyIStack<IStmt> exeStack10 = new MyStack<IStmt>();
  		IStmt ex10 = new CompStmt(
  				  					new CompStmt(
  				  								new AssignStmt("v",new ConstExp(6)),
  				  								new WhileStmt(
  				  												new ArithExp('-',new VarExp("v"),new ConstExp(4)),
  				  												new CompStmt(
  				  															new PrintStmt(new VarExp("v")),
  				  															new AssignStmt("v",new ArithExp('-',new VarExp("v"),new ConstExp(1)))
  				  															)
  				  											  )
  				  								),
  				  					new PrintStmt(new VarExp("v"))
  				  								
  				  				 	);
  	    	exeStack10.push(ex10);
  		PrgState prg10 = new PrgState(exeStack10,symTable,out,fileTable,heap);
  		Repository repo10 = new Repository(prg10,"log.txt");
        Controller ctrl10 = new Controller(repo10);
          
//-----------------------------------------------------------------------------------------------------------------------	
        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",ex1.toString(),ctrl1));
        menu.addCommand(new RunExample("2",ex2.toString(),ctrl2));
        menu.addCommand(new RunExample("3",ex3.toString(),ctrl3));
        menu.addCommand(new RunExample("4",ex4.toString(),ctrl4));
        menu.addCommand(new RunExample("5",ex5.toString(),ctrl5));
        menu.addCommand(new RunExample("6",ex6.toString(),ctrl6));
        menu.addCommand(new RunExample("7",ex7.toString(),ctrl7));
        menu.addCommand(new RunExample("8",ex8.toString(),ctrl8));
        menu.addCommand(new RunExample("9",ex9.toString(),ctrl9));
        menu.addCommand(new RunExample("10",ex10.toString(),ctrl10));
        menu.show();
        
	}

}
