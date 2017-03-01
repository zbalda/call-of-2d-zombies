package zombies2D;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Rectangle;
import java.util.Random;

public class Bullet {
	
	private int x, y;                 // position
    private double dx, dy;            // velocity
    private static int bulletSpeed = 20;
    private static int bulletDamage = 10;
    public int bulletSize;
    
    Bullet(int x, int y, Point mousePosition){
    	
    	this.x = x + (Player.playerSize / 2);
    	this.y = y + (Player.playerSize / 2);
    	
    	this.dx = 10;
    	this.dy = 10;
    	
    	bulletSize = 5;
    	
    	setVelocity(mousePosition);
    	
    }
    
    public void updateBullet(){
    	
    	x += dx;
    	y += dy;
    	
    }
    
    public void draw(Graphics2D g2d){
    	
    	g2d.setColor(Color.gray);
    	g2d.fillRect(x, y, bulletSize, bulletSize);
    	
    }
    
    public void setVelocity(Point mousePosition){
    
    
    	if(Weapon.rambo == true){
    		Random r = new Random();
    	
    		int tempDX = r.nextInt(25);
    		if(tempDX == 0){
    			tempDX = 5;
    		}
    		boolean tempDXreverse = r.nextBoolean();
    		if(tempDXreverse){
    			tempDX = tempDX * -1;
    		}
    		this.dx = tempDX;
    	
    		int tempDY = r.nextInt(25);
    		if(tempDY == 0){
    			tempDY = 5;
    		}
    		boolean tempDYreverse = r.nextBoolean();
    		if(tempDYreverse){
    			tempDY = tempDY * -1;
    		}
    		this.dy = tempDY;
    	} else { // This method is taken from www.gametutorial.net framework (except the rambo part)
    		// Unit direction vector of the bullet.
    		double directionDx = mousePosition.x - this.x;
    		double directionDy = mousePosition.y - this.y;
    		double lengthOfVector = Math.sqrt(directionDx * directionDx + directionDy * directionDy);
    		directionDx = directionDx / lengthOfVector; // Unit vector
    		directionDy = directionDy / lengthOfVector; // Unit vector
        
    		// Set speed.
    		this.dx = bulletSpeed * directionDx;
    		this.dy = bulletSpeed * directionDy;
    	}
    	
    }
    
    public int getX(){
    	return x;
    }
    
    public int getY(){
    	return y;
    }
    
    public int getDamage(){
    	return bulletDamage;
    }
    
    public Rectangle getBounds(){
		return new Rectangle(x, y, bulletSize, bulletSize);
	}

}
