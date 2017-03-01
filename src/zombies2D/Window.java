package zombies2D;

import java.awt.Frame;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

/**
 * Creates frame and set its properties.
 * 
 * adapted from www.gametutorial.net framework
 */

public class Window extends JFrame{

	private static final long serialVersionUID = -1958576646175387742L;

	private Window(){
    	
        this.setTitle("Call of 2D: Zombies"); // set frame title
        this.setUndecorated(true); // disable frame decoration
        this.setExtendedState(Frame.MAXIMIZED_BOTH); // set frame to full screen
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // default close operation
        this.setContentPane(new Framework()); // Framework extends Canvas which extends JPanel
        this.setVisible(true); // make window visible
        
    }

    public static void main(String[] args){
    	
        // Use the event dispatch thread to build the UI for thread-safety
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Window();
            }
        });
    }
}