import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;

import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.border.Border;


public class Fortification extends JPanel{
	private int _hauteur = 25;
	private int _largeur = 35;
	private int _posX;
	private int _posY;
	
	public Fortification(int posX, int posY){
		this._posX = posX;
		this._posY = posY;

		//Création de la fortification
		this.setBounds(this._posX, this._posY, 35, 25);
		this.setPreferredSize(new Dimension(35,25));
	}
	
	public void detruire(int valeur){
		this.setHauteur(this._hauteur - valeur);
	}
	
	public void setHauteur(int newHauteur){
		this._hauteur = newHauteur;
	}
	
	public void paintComponent(Graphics g){
		g.setColor(Color.BLUE);
		g.fillRect(0, 0, this._largeur, this._hauteur);
	}

}
