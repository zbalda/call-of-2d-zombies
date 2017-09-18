package zombies2D;

import java.util.ArrayList;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

public class Player {
    
    private final int healthAtStart;
    private int health;
    private Boolean alive;
    
    public long lastDamageTime;
    public long damageWaitTime;
    
    public static int totalKills;
    
    private ArrayList<PositionHistory> posHist;
    
    private int x, y;                 // position
    private double dx, dy;            // velocity
    private double ddxMove, ddyMove;  // moving acceleration
    private double ddxStop, ddyStop;  // stopping deceleration
    
    public static int playerSize;
    
    private Weapon weapon; // handles weapon bullets and level

    public Player(int x, int y){
        
    	this.healthAtStart = 100;
    	this.health = healthAtStart;
    	this.alive = true;
    	
    	lastDamageTime = 0;
    	damageWaitTime = 30000000;
    	
    	Player.totalKills = 0;
    	
    	this.posHist = new ArrayList<PositionHistory>();
    	
    	this.x = x;
        this.y = y;
        
        this.dx = 0; // positive dx moves right, negative dx moves left
        this.dy = 0; // positive dy moves down, negative dy moves up
        
        this.ddxMove = 0.2;
        this.ddyMove = 0.2;
        this.ddxStop = 0.2;
        this.ddyStop = 0.2;
        
        Player.playerSize = 50;
        
        weapon = new Weapon(); // handles bullets and weapon level

    }
    
    public void Update(){
    	
    	updateVelocity();
    	updatePosition();
    	updatePositionHistory();
		 
    }
    
    public void updateVelocity(){
        
    	// Horizontal movement
        if(dx >= -6 && dx <= 6){
        	if(Canvas.keyboardKeyState(KeyEvent.VK_D) || Canvas.keyboardKeyState(KeyEvent.VK_RIGHT)){
        		dx += ddxMove;
        	} else if(Canvas.keyboardKeyState(KeyEvent.VK_A) || Canvas.keyboardKeyState(KeyEvent.VK_LEFT)){
        		dx -= ddxMove;
        	} else {
        		if(dx >= -0.2 && dx <= 0.2){
        			dx = 0;
        		} else if(dx < -0.2 || dx > 0.2){
        			if(dx < -0.2){
        				dx += ddxStop;
        			} else if(dx > 0.2){
        				dx -= ddxStop;
        			}
        		}
        	}
        } else if(dx > 6){
        	dx = 6;
        } else if(dx < -6){
        	dx = -6;
        } else {
        	dx = 0;
        	dy = 0;
        }

        // Vertical movement
        if(dy >= -6 && dy <= 6){
        	if(Canvas.keyboardKeyState(KeyEvent.VK_W) || Canvas.keyboardKeyState(KeyEvent.VK_UP)){
        		dy -= ddyMove;
        	} else if(Canvas.keyboardKeyState(KeyEvent.VK_S) || Canvas.keyboardKeyState(KeyEvent.VK_DOWN)){
        		dy += ddyMove;
        	} else {
        		if(dy >= -0.2 && dy <= 0.2){
        			dy = 0;
        		} else if(dy < -0.2 || dy > 0.2){
        			if(dy < -0.2){
        				dy += ddyStop;
        			} else if(dy > 0.2){
        				dy -= ddyStop;
        			}
        		}
        	}
        } else if(dy > 6){
        	dy = 6;
        } else if(dy < -6){
        	dy = -6;
        } else {
        	dx = 0;
        	dy = 0;
        }
        
        // Vertical wall collision (left and right walls)
        if(x <= 0){
        	if(dx < 0){
        		dx = dx * -1;
        	}
        } else if (x > Framework.frameWidth - playerSize){
        	if(dx > 0){
        		dx = dx * -1;
        	}
        }
        
        // Horizontal wall collision (top and bottom walls)
        if(y <= 0){
        	if(dy < 0){
        		dy = dy * -1;
        	}
        } else if (y > Framework.frameHeight - playerSize){
        	if(dy > 0){
        		dy = dy * -1;
        	}
        }
        
    }
    
    public void updatePosition(){

        this.x += dx;
        this.y += dy;
        
    }
    
    public void updatePositionHistory(){

    	PositionHistory currentPosition = new PositionHistory(x, y, dx, dy);
    	posHist.add(currentPosition);
    	if(posHist.size() > 60){
    	    posHist.remove(0);
    	}
    
    }
    
    public void UpdateWeapon(long gameTime, Point mousePosition){
    	
    	if(Canvas.mouseButtonState(MouseEvent.BUTTON1)){
    		weapon.tryShoot(gameTime, x, y, mousePosition);
    	}
    	
    	weapon.updateBullets();
    	weapon.clampBullets();
    	
    }
    
    public void tryDamagePlayer(long gameTime){
    	if((gameTime - lastDamageTime) > damageWaitTime){
    		health--;
    		lastDamageTime = gameTime;
    	}
    }
    
    public boolean getAliveStatus(){
    	
    	if(health <= 0){
    		alive = false;
    		Game.displayF1stats = false;
    	}
    	return alive;
    	
    }
    
    public ArrayList<PositionHistory> getPositionHist(){
    	return posHist;
    }
    
    public void removeBullets(ArrayList<Boolean> bulletsToRemove){
		weapon.removeBullets(bulletsToRemove);
	}
    
    public void DrawBullets(Graphics2D g2d){
    	
    	weapon.drawBullets(g2d);
    	
    }

	public void DrawPlayer(Graphics2D g2d){
    	
    	 g2d.setColor(Color.black);
    	 g2d.fillRect(x, y, playerSize, playerSize);
        
    }
	
	public Rectangle getBounds(){
		
		return new Rectangle(x, y, playerSize, playerSize);
		
	}
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	public double getDX(){
		return dx;
	}
	
	public double getDY(){
		return dy;
	}
	
	public int getTotalKills(){
		return totalKills;
	}
	
	public int getHealth(){
		return health;
	}
	
	public int getBulletCount(){
		return weapon.getBulletCount();
	}
	
	public ArrayList<Rectangle> getBulletRectangles(){
		return weapon.getBulletRectangles();
	}
    
}
