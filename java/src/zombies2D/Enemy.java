package zombies2D;

import java.awt.Rectangle;

public class Enemy {
    
    public int health;
    public Boolean alive;
    
    public int lvl;
    
    public int x, y;                 // position
    public double dx, dy;            // velocity
    public double speed;             // speed
    public int size;                 // size of enemy

    public Enemy(int x, int y, int health){
        
    	this.health = health;
    	this.alive = true;
    	
    	this.x = x;
        this.y = y;
        
        this.dx = 0;
        this.dy = 0;

    }
    
    public void updatePosition() { // should be abstract method?
    	
    	x += dx;
    	y += dy;
    	
	}
    
    public int getX(){
    	return x;
    }
    
    public int getY(){
    	return y;
    }
    
    public void damage(int amt){
    	health = health - amt;
    }
    
    public boolean getAliveStatus(){
    	
    	if(health <= 0){
    		alive = false;
    	}
    	return alive;
    	
    }
    
    public Rectangle getBounds(){
		return new Rectangle(x, y, size, size);
	}
    
}