package zombies2D;

import java.awt.Color;
import java.awt.Graphics2D;
import java.util.ArrayList;
import java.util.Random;

public class SmartEnemy extends Enemy {

	public SmartEnemy(int x, int y, int health) {
		
		super(x, y, health);
		speed = 3;
		size = 30;
		
	}
	
	public void calculateNewDirection(ArrayList<PositionHistory> posHist){ // This method is adapted from www.gametutorial.net framework
		
		int followX = Framework.frameWidth / 2; // x point that enemy will follow
		int followY = Framework.frameHeight / 2; // y point that enemy will follow
		
		Random r = new Random();
		int delay = 1 + r.nextInt(5);
		if(!(posHist.isEmpty()) && (posHist.size() > delay)){
			followX = posHist.get((posHist.size() - delay)).getX();
			followY = posHist.get((posHist.size() - delay)).getY();
		}
		
        double directionDx = followX - this.x;
        double directionDy = followY - this.y;
        double lengthOfVector = Math.sqrt(directionDx * directionDx + directionDy * directionDy);
        directionDx = directionDx / lengthOfVector; // Unit vector
        directionDy = directionDy / lengthOfVector; // Unit vector
        
        // Set speed.
        this.dx = speed * directionDx;
        this.dy = speed * directionDy;
		
    }

	public void draw(Graphics2D g2d){
    	
    	g2d.setColor(Color.ORANGE);
    	g2d.fillRect(x, y, size, size);
    	
    }

}
