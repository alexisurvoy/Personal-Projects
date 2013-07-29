import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JLayeredPane;


public class Fenetre extends JFrame{
	
	private ArrayList<Fortification> fortifications;
	private ArrayList<Alien> aliens;
	private ArrayList<Missile> missilesSpaceship;
	private ArrayList<Missile> missilesAliens;
	private Vaisseau spaceship;
	
	public Fenetre(){
		//Initialisation des variables privées
		this.fortifications = new ArrayList<Fortification>();
		this.aliens = new ArrayList<Alien>();
		this.missilesAliens = new ArrayList<Missile>();
		this.missilesSpaceship = new ArrayList<Missile>();
		
		//Initialisation de la fenètre
		setTitle("Space Intruders");
		setSize(800,600);
		setLocationRelativeTo(null);
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBackground(Color.BLACK);
		setLayout(new BorderLayout());
		JLayeredPane pane = new JLayeredPane();
		this.setContentPane(pane);

		//Création des fortifications
		fortifs();
		
		//Création des aliens
		Aliens aliens = new Aliens(this);
		
		//Création du vaisseau
		this.spaceship = new Vaisseau();
		this.getContentPane().add(this.spaceship);
		
		//Ajout des écouteurs
		ecouteurDeplacementVaisseau();
		ecouteurClick();
		
		//Curseur invisible
		Toolkit tk = Toolkit.getDefaultToolkit();
		Image img = tk.getImage("images/souris.png");
		Cursor monCurseur = tk.createCustomCursor(img, new Point(11, 11), "souris");
		setCursor(monCurseur);
		
		//Lancement des threads
		aliens.start();
		
		setVisible(true);
	}
	
	private void fortifs(){
		for(int i = 0; i<6;i++){
			Fortification f = new Fortification((120+(i*110)), 450);
			this.getContentPane().add(f);
			this.fortifications.add(f);
			setVisible(true);
		}

	}
	
	private void ecouteurDeplacementVaisseau(){
		this.addMouseMotionListener(new MouseAdapter() {
			public void mouseMoved(MouseEvent e){
				spaceship.deplacer(e);
			}
		});
	}
	
	private void ecouteurClick(){
		final JFrame frame = this;
		this.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e){
				Missile mis = new Missile(Color.WHITE, e.getX()+9,520, 1, frame);
				getContentPane().add(mis);
				missilesSpaceship.add(mis);
				setVisible(true);
			}
		});
	}
	
	public ArrayList<Alien> getAliens(){
		return this.aliens;
	}
	
}
