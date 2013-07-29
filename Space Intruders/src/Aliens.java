import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Arrays;

import javax.swing.Timer;


public class Aliens extends Thread implements ActionListener{

	private final int RIGHT = 1;
	private final int LEFT = 0;
	
	private ArrayList<Alien> aliens = new ArrayList<Alien>();
	private boolean[][] aliensMatrix = new boolean[10][5];
	private Fenetre fenetre;
	private int direction = this.RIGHT;
	
	public Aliens(Fenetre fenetre){
		
		this.fenetre = fenetre;
		
		//Create the aliens
		for(int i = 0; i < aliensMatrix.length; i++){
			for(int j=0; j<aliensMatrix[i].length;j++){
				//Create an alien at the right position
				Alien a = new Alien(10, (150+(50*i)), 50+(50*j));
				//Set its value to true in the matrix, meaning that it's not dead yet
				this.aliensMatrix[i][j] = true;
				//Display on the screen
				this.fenetre.getContentPane().add(a);
				this.aliens.add(a);
			}
		}
		
		//Create the timer responsible for moving the aliens
		Timer timer = new Timer(100, this);
		timer.start();
		
	}
	
	public void run(){
		while(true){
			
		}
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		this.move();
	}
	
	private void move(){
		
		//First we need to check if we can move
		Alien lastAlienInLine = checkMove(this.direction);
		
		if(lastAlienInLine != null && this.direction == this.RIGHT){
			
			if(lastAlienInLine.getX() <= this.fenetre.getWidth()-100){
				//move right
				for(Alien alien : this.aliens){
					alien.setX( alien.getX()+5 );
					this.fenetre.repaint();
				}
			}else{
				this.direction = this.LEFT;
				
				for(Alien alien : this.aliens){
					alien.setY( alien.getY()+10 );
					this.fenetre.repaint();
				}
				
			}
			
		}
		
		if(lastAlienInLine != null && this.direction == this.LEFT){
			
			if(lastAlienInLine.getX() >= 100){

				//move left
				for(Alien alien : this.aliens){
					alien.setX( alien.getX()-5 );
					this.fenetre.repaint();
				}
			}else{
				this.direction = this.RIGHT;
				
				for(Alien alien : this.aliens){
					alien.setY( alien.getY()+10 );
					this.fenetre.repaint();
				}				
			}
			
		}
		
	}
	
	private Alien checkMove(int direction){
		
		if(direction == RIGHT){
			
			for(int i = this.aliensMatrix.length-1; i >= 0; i--){
				
				for(int j=this.aliensMatrix[i].length-1; j>=0 ;j--){
					
					int rowNumber = i;
					
					while(rowNumber >= 0){
						
						if( this.aliensMatrix[rowNumber][j] == true ) return this.aliens.get(j*aliensMatrix.length+rowNumber);
						
						rowNumber--;
					
					}
				
				}
				
			}
			
		}else{
			
			for(int i = 0; i < this.aliensMatrix.length; i++){
				
				for(int j=0; j < this.aliensMatrix[i].length ;j++){
					
					int rowNumber = i;
					
					while(rowNumber < this.aliensMatrix[i].length ){
						if( this.aliensMatrix[rowNumber][j] == true ) return this.aliens.get(j*aliensMatrix.length+rowNumber);
						
						rowNumber--;
					}
				
				}
				
			}			
			
		}
		
		//should not happen
		return null;
		
	}
	
	
}
