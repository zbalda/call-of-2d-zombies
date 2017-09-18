package zombies2D;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import javax.swing.JPanel;

/**
 * Create a JPanel on which we draw and listen for keyboard and mouse events.
 * 
 * adapted from www.gametutorial.net framework
 */

public abstract class Canvas extends JPanel implements KeyListener, MouseListener {
	
	private static final long serialVersionUID = -5347482919461627663L;
	
	private static boolean[] keyboardState = new boolean[525]; // A boolean array of key states: true or false, pressed or not pressed
    private static boolean[] mouseState = new boolean[3]; // A boolean array of mouse states: true of false, pressed or not pressed
    
    public Canvas(){
    	
        this.setDoubleBuffered(true); // double buffered
        this.setFocusable(true);
        this.setBackground(Color.black);
        
        BufferedImage blankCursorImg = new BufferedImage(16, 16, BufferedImage.TYPE_INT_ARGB);
        Cursor blankCursor = Toolkit.getDefaultToolkit().createCustomCursor(blankCursorImg, new Point(0, 0), null);
        this.setCursor(blankCursor); // remove mouse cursor from screen
        
        this.addKeyListener(this); // keyboard listener  added to JPanel to receive key events
        this.addMouseListener(this); // mouse listener added to JPanel to receive mouse events
        
    }
    
    
    // This method is overridden in Framework.java and is used for drawing to the screen.
    public abstract void Draw(Graphics2D g2d);
    
    @Override
    public void paintComponent(Graphics g){
    	
        Graphics2D g2d = (Graphics2D)g;        
        super.paintComponent(g2d);        
        Draw(g2d);
        
    }
    
    // KEY STATES AND KEYBOARD EVENT HANDLING
    
    // Key states
    public static boolean keyboardKeyState(int key){
        return keyboardState[key]; // returns true or false for keyboardState in index position key
    }
    
    // Event handling for keyboard listener
    @Override
    public void keyPressed(KeyEvent e){
        keyboardState[e.getKeyCode()] = true;
    }
    
    @Override
    public void keyReleased(KeyEvent e){
        keyboardState[e.getKeyCode()] = false;
        keyReleasedFramework(e);
    }
    
    @Override
    public void keyTyped(KeyEvent e){}
    
    public abstract void keyReleasedFramework(KeyEvent e);
    
    // MOUSE STATES AND MOUSE EVENT HANDLING
    
    // Mouse states
    public static boolean mouseButtonState(int button){
        return mouseState[button - 1]; // returns true or false for mouseState in index position
    }
    
    // Setting mouse status
    private void mouseKeyStatus(MouseEvent e, boolean status){
    	
        if(e.getButton() == MouseEvent.BUTTON1)
            mouseState[0] = status;
        else if(e.getButton() == MouseEvent.BUTTON2)
            mouseState[1] = status;
        else if(e.getButton() == MouseEvent.BUTTON3)
            mouseState[2] = status;
        
    }
    
    // Event handling for mouse listener
    @Override
    public void mousePressed(MouseEvent e){
        mouseKeyStatus(e, true);
    }
    
    @Override
    public void mouseReleased(MouseEvent e){
        mouseKeyStatus(e, false);
    }
    
    @Override
    public void mouseClicked(MouseEvent e) { }
    
    @Override
    public void mouseEntered(MouseEvent e) { }
    
    @Override
    public void mouseExited(MouseEvent e) { }
    
}
