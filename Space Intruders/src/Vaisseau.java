import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseEvent;

import javax.swing.ImageIcon;
import javax.swing.JPanel;


public class Vaisseau extends JPanel{
	
	private int _posX;
	private int _posY;
	
	public Vaisseau(){
		this._posX = 385;
		this._posY = 520;
		this.setBounds(this._posX, this._posY, 35, 35);
		this.setPreferredSize(new Dimension(35,35));
	}
	
	public void paintComponent(Graphics g){
		ImageIcon image = new ImageIcon("images/spaceship.png");
		Image spaceship = image.getImage();
		
		g.drawImage(spaceship, 0, 0, this);
		this.setBounds(_posX, _posY, 35, 35);
	}
	
	public void deplacer(MouseEvent e){
		this._posX = e.getX();
		repaint();
	}

}
