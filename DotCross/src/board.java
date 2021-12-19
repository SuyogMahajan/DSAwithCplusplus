
public class board {

	private int boardSize = 3;
	private char board[][];
	private int cnt = 0;
	private char p1, p2;

	public static final int P1WINS = 1;
	public static final int P2WINS = 2;
	public static final int DRAW = 3;
	public static final int INVALID = 4;
	public static final int INCOMPLETE = 5;

	public board(char p1, char p2) {
		board = new char[boardSize][boardSize];

		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				board[i][j] = ' ';
			}
		}
		this.p1 = p1;
		this.p2 = p2;
	}
	
	public void print() {
		
		for(int i = 0;i<boardSize;i++) {
			System.out.println("---------------");
			for(int j = 0;j<boardSize;j++) {
				System.out.print("| "+board[i][j]+" |");
			}
			System.out.println();
		}
		System.out.println("---------------");
	}
	
	public int move(player p,int x,int y) {
		
		if(x < 0 || x >= boardSize ||y < 0 || y >= boardSize||board[x][y] != ' ' ) {
			return INVALID;
		}
		
		char c = p.symbol;
	    board[x][y] = c;
	    cnt ++;
	    int i = 0;
	    
	    for(;i< boardSize;i++) {
	     if(c != board[i][y]) {
	    	 break;
	     }
	    }
	    
	    // condition
	    if(i == boardSize) {
	    	return p1 == c ? P1WINS : P2WINS;
	    }
	    
	    i = 0;	    
	    for(;i<boardSize;i++) {
		     if(c != board[x][i]) {
		    	 break;
		     }
		    }
	    
	    //condition
        if(i == boardSize) {
        	return p1 == c ? P1WINS : P2WINS;
	    }
	    
		i = 0;
		int j = 0;
		
		while(i < boardSize && j < boardSize) {
			if(board[i][j] != c) {
			 break;	
			}
			i++;
			j++;	
		}
        
		if(i == boardSize && j == boardSize) return p1 == c ? P1WINS : P2WINS;
		
		i = 0;
		j = boardSize-1;
		
		while(i < boardSize && j >= 0) {
			if(board[i][j] != c) {
			 break;	
			}
			i++;
			j--;	
		}
		
		if(i == boardSize && j < 0) return p1 == c ? P1WINS : P2WINS;
		
		if(cnt == boardSize*boardSize) return DRAW;
		
		return INCOMPLETE;
	}

}
