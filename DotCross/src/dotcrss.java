import java.util.Scanner;

public class dotcrss {

	public player p1, p2;
	public board b;

	public player takePlayer() {

		String nameString;
		char symbol;

		Scanner s = new Scanner(System.in);
		System.out.print("Enter Name : ");
		
		nameString = s.next();
		System.out.print("Enter Symbol : ");
		symbol = s.next().charAt(0);
		player p = new player(nameString, symbol);

		return p;

	}
   
	public static void main(String[] args) {
		dotcrss d = new dotcrss();
		d.startgame();
	}
	
	public void startgame() {
    	
    	p1 = takePlayer();
    	p2 = takePlayer();
    	
    	Scanner s = new Scanner(System.in);
    	
    	while(p1.symbol == p2.symbol) {
    		System.out.println("Symbol alredy taken !!! try diffrent one.");
    		p2.symbol = s.next().charAt(0);
    	}
    	System.out.println();
    	System.out.println("Lets Play Tic Tak Toe !!!");
    	System.out.println();
    	
    	
    	
        b = new board(p1.symbol,p2.symbol);
    
        boolean turn = true;
        int res = b.INCOMPLETE;
        
        while(res == b.INCOMPLETE || res == b.INVALID) {
        	
        	b.print();
        	
        	if(turn) {
        	
        		
        		int x,y;
        		System.out.println("Player 1: "+p1.name+"'s turn");
        		
        		System.out.print("Enter x: ");
        		x = s.nextInt();
        		
        		System.out.print("Enter y: ");
        		y = s.nextInt();
        		
        		  res = b.move(p1,x,y);
        	        
        	        if(res != b.INVALID) {
        	        	turn = false;
        	        }else {
        	        	System.out.println();
        	        	System.out.println("Invalid !! try again !!!");
        	        	System.out.println();
        	        }
        		
        	        
        		
        	}else {
        		
        		int x,y;
        		System.out.println("Player 2: "+p2.name+"'s turn");
        		
        		System.out.print("Enter x: ");
        		x = s.nextInt();
        		
        		System.out.print("Enter y: ");
        		y = s.nextInt();
        		
        		  res = b.move(p2,x,y);
        	        
        	        if(res != b.INVALID) {
        	        	turn = true;
        	        }else {
        	        	System.out.println();
        	        	System.out.println("Invalid !! try again !!!");
        	        	System.out.println();
        	        }
        	}
        	System.out.println();
        	System.out.println();
        }
        
        b.print();
        
        if(res == b.P1WINS) {
        	System.out.println("player 1: "+p1.name+" wins !");
        }else if(res == b.P2WINS) {
        	System.out.println("player 2: "+p2.name+" wins !");
        }else {
        	System.out.println("Draw...");
        }
        
    
    }

}
