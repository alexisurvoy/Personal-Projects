import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JPanel;


public class Alien extends JPanel{
	
	private int _valeur, _vitesse, _posX, _posY, collision;
	
	public Alien(int valeur, int posX, int posY){
		
		this._vitesse = 10;
		this._posX = posX;
		this._posY = posY;
		this._valeur = valeur;
		this.collision = 0;
		
		this.setBounds(_posX, _posY, 24, 25);
		this.setPreferredSize(new Dimension(24,25));
	}

	public void paintComponent(Graphics g){
		if(this.collision == 1){
			ImageIcon image = new ImageIcon("images/invader.png");
			Image invader = image.getImage();
			
			g.drawImage(invader, 0, 0, this);
			System.out.println(this.getParent());
		}else{
			ImageIcon image = new ImageIcon("images/invader.png");
			Image invader = image.getImage();
			
			g.drawImage(invader, 0, 0, this);
		}
	}
	
	public void setX(int newX){
		this._posX = newX;
	}
	
	public void setY(int newY){
		this._posY = newY;
	}
	
	public int getX(){
		return this._posX;
	}
	
	public int getY(){
		return this._posY;
	}
	
	public void supprimer(){
		this.collision = 1;
		repaint();
	}
	
}
