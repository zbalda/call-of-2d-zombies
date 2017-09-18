package zombies2D;

import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Rectangle;
import java.util.ArrayList;

public class Weapon {
	
	public static int ammo;
	
	public long lastCreatedBulletTime;
	public static long bulletFireDelay;
	
	public static boolean rambo;
	
	private ArrayList<Bullet> bullets;
	
	public Weapon(){
		
		ammo = 10;
		
		lastCreatedBulletTime = 0;
		bulletFireDelay = 500000000; // half a second in nano seconds
		
		Weapon.rambo = false;
		
		bullets = new ArrayList<Bullet>(); // bullet objects
		
	}
	
	public void tryShoot(long gameTime, int x, int y, Point mousePosition){

		if(gameTime - lastCreatedBulletTime >= bulletFireDelay){
    		if(ammo > 0){
    			Bullet currentBullet = new Bullet(x, y, mousePosition);
    			bullets.add(currentBullet);
    			ammo--;
    			lastCreatedBulletTime = gameTime;
    		}
		}
		
	}
	
	public void updateBullets(){
		
		for(int i = 0; i < bullets.size(); i++){
			bullets.get(i).updateBullet();
		}
			
	}
	
	public void clampBullets(){
			
		// left clamp - remove if bullet goes out of screen to the left
		int leftRange = 0; // index position starts at zero
		while(leftRange < bullets.size()){ // keep in range
			if(bullets.get(leftRange).getX() < -50){ // if out of screen to the left
				bullets.remove(leftRange); // remove
				leftRange--; // between this and 2 lines from this, we keep it "neutral" since when we remove
			}                // an item, all items to the right of it shift over - which means we don't need to increase the index position
			leftRange++;
		}
		
		// right clamp - remove if bullet goes out of screen to the right
		int rightRange = 0; // index position starts at zero
		while(rightRange < bullets.size()){ // keep in range
			if(bullets.get(rightRange).getX() > Framework.frameWidth + 50){ // if out of screen to the right
				bullets.remove(rightRange); // remove
				rightRange--; // between this and 2 lines from this, we keep it "neutral" since when we remove
			}                 // an item, all items to the right of it shift over - which means we don't need to increase the index position
			rightRange++;
		}
		
		// top clamp - remove if bullet goes out of top of screen
		int topRange = 0; // index position starts at zero
		while(topRange < bullets.size()){ // keep in range
			if(bullets.get(topRange).getY() < -50){ // if out of top of screen
				bullets.remove(topRange); // remove
				topRange--; // between this and 2 lines from this, we keep it "neutral" since when we remove
			}               // an item, all items to the right of it shift over - which means we don't need to increase the index position
			topRange++;
		}
		
		// bottom clamp - remove if bullet goes out of bottom of screen
		int bottomRange = 0; // index position starts at zero
		while(bottomRange < bullets.size()){ // keep in range
			if(bullets.get(bottomRange).getY() > Framework.frameHeight + 50){ // if out of bottom of screen
				bullets.remove(bottomRange); // remove
				bottomRange--; // between this and 2 lines from this, we keep it "neutral" since when we remove
			}                  // an item, all items to the right of it shift over - which means we don't need to increase the index position
			bottomRange++;
		}
	
	}
	
	public void removeBullets(ArrayList<Boolean> bulletsToRemove){
		
		if(bulletsToRemove.size() == bullets.size()){ // should be same, otherwise it would go out of range
			int boundedIndex = 0; // index position starts at zero
			while(boundedIndex < bulletsToRemove.size() && boundedIndex < bullets.size()){ // keep in range
				if(bulletsToRemove.get(boundedIndex) == true){
					bullets.remove(boundedIndex);
					bulletsToRemove.remove(boundedIndex);
					boundedIndex--;
				}
				boundedIndex++;
			}
		}
		
	}
	
	public static void updateWeaponLevel(int waveNumber){
		
		// called inside Waves at start of new wave
		bulletFireDelay = 1000000000 - (waveNumber * 100000000);
		if(bulletFireDelay < 17000000){
			bulletFireDelay = 17000000;
		}
	
	}
	
	public void drawBullets(Graphics2D g2d){
		
		for(int i = 0; i < bullets.size(); i++){
            bullets.get(i).draw(g2d);
        }
		
	}
	
	public ArrayList<Rectangle> getBulletRectangles(){
    	
    	ArrayList<Rectangle> bulletRectangles = new ArrayList<Rectangle>();
    	for(int i = 0; i < bullets.size(); i++){
    		Rectangle tempRectangle = new Rectangle();
    		tempRectangle = bullets.get(i).getBounds();
    		bulletRectangles.add(tempRectangle);
    	}
    	
		return bulletRectangles;
    			
    }
	
	public int getBulletCount(){
		
		return (bullets.size());
		
	}

}
