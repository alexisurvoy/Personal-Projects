import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Iterator;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;


public class Missile extends JPanel{
	private int _sens;
	private int _posX;
	private int _posY;
	private int _vitesseMissile;
	private Color _couleur;
	private Timer timer;
	private ArrayList<Alien> aliens;
	private Iterator it;
	private JFrame _frame;
	private int collision = 0;
	
	public Missile(Color couleur, int posX, int posY, int sens, JFrame frame){
		this._posX = posX;
		this._posY = posY;
		this._vitesseMissile = 50;
		this._couleur = couleur;
		this._sens = sens;
		this._frame = frame;

		this.setBounds(_posX, _posY-(sens*10), 2, 10);
		this.setPreferredSize(new Dimension(2, 10));
		
		this.timer = createTimer();
		this.timer.start();
	}
	
	public void deplacer(){
		//On récupère la liste des aliens affichés
		this.aliens = ((Fenetre) this._frame).getAliens();
		this.it = this.aliens.iterator();
		
		//Si le missile sort des limites, on le supprime
		if(this.getBounds().y <= (-10) || this.getBounds().y >= (588)){
			this.timer.stop();					//Arret du timer des déplacements
			this.getParent().remove(this);
		}else{
			while(it.hasNext()){
				Alien ali = (Alien) it.next();
				if(this.getBounds().intersects(ali.getBounds())){
					ali.supprimer();
					this.collision = 1;
					this.timer.stop();
					repaint();
				}
			}
		}
		
		
		if(this._sens == 1){
			this._posY -= 10;
		}else{
			this._posY += 10;
		}
		repaint();
	}
	
	public void paintComponent(Graphics g){
		if(collision == 1){
			g.setColor(Color.BLACK);
			g.fillRect(0, 0, 2, 10);
			this.getParent().remove(this);
		}else{
			g.setColor(this._couleur);
			g.fillRect(0, 0, 2, 10);
		}
		
		this.setBounds(_posX, _posY-(this._sens*10), 2, 10);
	}
	
	private Timer createTimer (){
	    ActionListener action = new ActionListener (){
	        public void actionPerformed (ActionEvent event){
	        	deplacer(); 
	        }
	      };
	    return new Timer (this._vitesseMissile, action);
	  }  
	
}
