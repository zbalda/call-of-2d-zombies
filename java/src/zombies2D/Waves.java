package zombies2D;

import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

public class Waves {

	public Random random;
	
	public static int waveNumber;
	
	public static int totalEnemiesToBeSpawned;
	public static int basicEnemiesToBeSpawned;
	public static int smartEnemiesToBeSpawned;
	public static int largeEnemiesToBeSpawned;
	
	public int basicEnemyHealth;
	public int smartEnemyHealth;
	public int largeEnemyHealth;
	
	public int ammoToAdd;
	public int newWaveExtraAmmo;
	
	private ArrayList<BasicEnemy> bEnemies;
    private ArrayList<SmartEnemy> sEnemies;
    private ArrayList<LargeEnemy> lEnemies;
    
    public long timeOfLastCreatedBasicEnemy;
    public long timeOfLastCreatedSmartEnemy;
    public long timeOfLastCreatedLargeEnemy;
    
    public long timeBetweenBasicEnemySpawns;
    public long timeBetweenSmartEnemySpawns;
    public long timeBetweenLargeEnemySpawns;
	
	public final long delay = 8000;
	public long delayStart;
	
    public static enum WaveState{CALCULATING_NEW_WAVE, DELAY, SPAWNING, FINISHING} // wave states
    public static WaveState waveState; // current wave state
    
    public Waves() {
    	
    	random = new Random();
    	
    	waveNumber = 0;
    	
    	totalEnemiesToBeSpawned = 0;
    	basicEnemiesToBeSpawned = 0;
    	smartEnemiesToBeSpawned = 0;
    	largeEnemiesToBeSpawned = 0;
    	
    	basicEnemyHealth = 12;
    	smartEnemyHealth = 10;
    	largeEnemyHealth = 22;
    	
    	ammoToAdd = 0;
    	newWaveExtraAmmo = 100;
    	
    	bEnemies = new ArrayList<BasicEnemy>();
        sEnemies = new ArrayList<SmartEnemy>();
        lEnemies = new ArrayList<LargeEnemy>();
        
        timeOfLastCreatedBasicEnemy = System.currentTimeMillis();
        timeOfLastCreatedSmartEnemy = System.currentTimeMillis();
        timeOfLastCreatedLargeEnemy = System.currentTimeMillis();
        
        timeBetweenBasicEnemySpawns = 4500;
        timeBetweenSmartEnemySpawns = 6000;
        timeBetweenLargeEnemySpawns = 8500;
    	
    	delayStart = 0;
    	
    	waveState = WaveState.CALCULATING_NEW_WAVE;
    	
    }
    
    public void UpdateWaves(long gameTime){
    
    	switch (waveState){
        	case CALCULATING_NEW_WAVE:
        		waveNumber++;
        		
        		basicEnemiesToBeSpawned = 10 + waveNumber * waveNumber; 
        		smartEnemiesToBeSpawned = 10 + waveNumber * 4;
        		largeEnemiesToBeSpawned = 2 + waveNumber * 3;
        		
        		basicEnemyHealth += 5;
            	smartEnemyHealth += 6;
            	largeEnemyHealth += 5;
            	
            	ammoToAdd = ((basicEnemiesToBeSpawned * basicEnemyHealth)+ 
            				 (smartEnemiesToBeSpawned * smartEnemyHealth)+ 
            				 (largeEnemiesToBeSpawned * largeEnemyHealth))+
            				(newWaveExtraAmmo);
            	Weapon.ammo += ammoToAdd;
        		
        		Weapon.updateWeaponLevel(waveNumber);
        		updateTimeBetweenEnemySpawns(waveNumber);
        		
        		delayStart = System.currentTimeMillis();
        		waveState = WaveState.DELAY;
        		
        		break;
        	case DELAY:
        		if(System.currentTimeMillis() - delayStart >= delay){
        			waveState = WaveState.SPAWNING;
        		}
        		break;
        	case SPAWNING:
        		if(basicEnemiesToBeSpawned > 0){
        			tryBasicEnemySpawn(); // spawns the enemies if enough time has passed
        		}
        		if(smartEnemiesToBeSpawned > 0){
        			trySmartEnemySpawn();
        		}
        		if(largeEnemiesToBeSpawned > 0){
        			tryLargeEnemySpawn();
        		}
        		
        		totalEnemiesToBeSpawned = (basicEnemiesToBeSpawned +
        				 					smartEnemiesToBeSpawned +
        				 					largeEnemiesToBeSpawned);
        		if(totalEnemiesToBeSpawned <= 0){
        			waveState = WaveState.FINISHING;
        		}
        		break;
        	case FINISHING:
        		if((bEnemies.size() + sEnemies.size() + lEnemies.size()) <= 0){
        			waveState = WaveState.CALCULATING_NEW_WAVE;
        			Game.score += (1000 + waveNumber * 100);
        		}
        		break;
        	default:
        		break;
    	}
    	
    }
    
    public void updateTimeBetweenEnemySpawns(int waveNumber){
    	
    	timeBetweenBasicEnemySpawns = 4500 - 100 * waveNumber;
    	if(timeBetweenBasicEnemySpawns < 100){
    		timeBetweenBasicEnemySpawns = 100;
    	}
        timeBetweenSmartEnemySpawns = 6000 - 100 * waveNumber;
        if(timeBetweenSmartEnemySpawns < 100){
    		timeBetweenSmartEnemySpawns = 100;
    	}
        timeBetweenLargeEnemySpawns = 8500 - 100 * waveNumber;
        if(timeBetweenLargeEnemySpawns < 100){
    		timeBetweenLargeEnemySpawns = 100;
    	}
        
    }
    
    public void tryBasicEnemySpawn(){
    	
    	if((System.currentTimeMillis() - timeOfLastCreatedBasicEnemy) >= timeBetweenBasicEnemySpawns){
    		basicEnemiesToBeSpawned--;
    		
    		int x = random.nextInt(4); // 0 is left, 1 is right, 2 is top, 3 is bottom
    		
    		int xSpawn = 500; // default x
    		int ySpawn = 500; // default y
    		
    		if(x == 0){ // spawn left side
    			xSpawn = -70;
    			ySpawn = random.nextInt((Framework.frameHeight + 70));
    		} else if(x == 1){ // spawn right side
    			xSpawn = Framework.frameWidth + 1;
    			ySpawn = random.nextInt((Framework.frameHeight + 70));
    		} else if(x == 2){ // spawn top
    			xSpawn = random.nextInt((Framework.frameWidth));
    			ySpawn = -70;
    		} else if(x == 3){ // spawn bottom
    			xSpawn = random.nextInt((Framework.frameWidth));
    			ySpawn = Framework.frameHeight + 1;
    		}

    		BasicEnemy tempBasicEnemy = new BasicEnemy(xSpawn, ySpawn, basicEnemyHealth);
    		bEnemies.add(tempBasicEnemy);
        	timeOfLastCreatedBasicEnemy = System.currentTimeMillis();
    	}
    	
    }
    
    public void trySmartEnemySpawn(){
    	
    	if((System.currentTimeMillis() - timeOfLastCreatedSmartEnemy) >= timeBetweenSmartEnemySpawns){
    		smartEnemiesToBeSpawned--;
    		
    		int x = random.nextInt(4); // 0 is left, 1 is right, 2 is top, 3 is bottom
    		
    		int xSpawn = 500; // default x
    		int ySpawn = 500; // default y
    		
    		if(x == 0){ // spawn left side
    			xSpawn = -70;
    			ySpawn = random.nextInt((Framework.frameHeight + 70));
    		} else if(x == 1){ // spawn right side
    			xSpawn = Framework.frameWidth + 1;
    			ySpawn = random.nextInt((Framework.frameHeight + 70));
    		} else if(x == 2){ // spawn top
    			xSpawn = random.nextInt((Framework.frameWidth));
    			ySpawn = -70;
    		} else if(x == 3){ // spawn bottom
    			xSpawn = random.nextInt((Framework.frameWidth));
    			ySpawn = Framework.frameHeight + 1;
    		}

    		SmartEnemy tempSmartEnemy = new SmartEnemy(xSpawn, ySpawn, smartEnemyHealth);
    		sEnemies.add(tempSmartEnemy);
        	timeOfLastCreatedSmartEnemy = System.currentTimeMillis();
    	}
    	
    }
    
    public void tryLargeEnemySpawn(){
    	
    	if((System.currentTimeMillis() - timeOfLastCreatedLargeEnemy) >= timeBetweenLargeEnemySpawns){
    		largeEnemiesToBeSpawned--;
    		
    		int x = random.nextInt(4); // 0 is left, 1 is right, 2 is top, 3 is bottom
    		
    		int xSpawn = 500; // default x
    		int ySpawn = 500; // default y
    		
    		if(x == 0){ // spawn left side
    			xSpawn = -70;
    			ySpawn = random.nextInt((Framework.frameHeight + 70));
    		} else if(x == 1){ // spawn right side
    			xSpawn = Framework.frameWidth + 1;
    			ySpawn = random.nextInt((Framework.frameHeight + 70));
    		} else if(x == 2){ // spawn top
    			xSpawn = random.nextInt((Framework.frameWidth));
    			ySpawn = -70;
    		} else if(x == 3){ // spawn bottom
    			xSpawn = random.nextInt((Framework.frameWidth));
    			ySpawn = Framework.frameHeight + 1;
    		}

    		LargeEnemy tempLargeEnemy = new LargeEnemy(xSpawn, ySpawn, largeEnemyHealth);
    		lEnemies.add(tempLargeEnemy);
        	timeOfLastCreatedLargeEnemy = System.currentTimeMillis();
    	}
    	
    }
    
    public void UpdateEnemies(ArrayList<PositionHistory> posHist) throws IOException{
    	
    	for(int i = 0; i < bEnemies.size(); i++){
			bEnemies.get(i).calculateNewDirection(posHist);
			bEnemies.get(i).updatePosition();
		}
    	
    	for(int i = 0; i < sEnemies.size(); i++){
    		sEnemies.get(i).calculateNewDirection(posHist); // Calculate new velocity direction (based on player position)
			sEnemies.get(i).updatePosition();
		}
    	
    	for(int i = 0; i < lEnemies.size(); i++){
    		lEnemies.get(i).calculateNewDirection(posHist); // Calculate new velocity direction (based on player position)
    		lEnemies.get(i).updatePosition();
		}
    	
    }
    
    public void damageEnemies(ArrayList<Boolean> basicEnemiesToDamage, ArrayList<Boolean> smartEnemiesToDamage, ArrayList<Boolean> largeEnemiesToDamage){

    	if(basicEnemiesToDamage.size() == bEnemies.size()){ // should be same, otherwise it would go out of range
    		int bEnemiesBoundedIndex = 0; // index position starts at zero
    		while(bEnemiesBoundedIndex < basicEnemiesToDamage.size() && bEnemiesBoundedIndex < bEnemies.size()){ // keep in range
    			if(basicEnemiesToDamage.get(bEnemiesBoundedIndex) == true){ // if this enemy should be damaged
    				bEnemies.get(bEnemiesBoundedIndex).damage(10); // damage enemy
    				if(bEnemies.get(bEnemiesBoundedIndex).getAliveStatus() == false){ // if enemy is dead
    					bEnemies.remove(bEnemiesBoundedIndex); // remove enemy
    					basicEnemiesToDamage.remove(bEnemiesBoundedIndex); // keep parallel
    					Game.score += 100;
    					Player.totalKills++;
    					bEnemiesBoundedIndex--; // keep in bounds
    				}
    			}
    			bEnemiesBoundedIndex++;
    		}
    	}
    	
    	if(smartEnemiesToDamage.size() == sEnemies.size()){ // should be same, otherwise it would go out of range
    		int sEnemiesBoundedIndex = 0; // index position starts at zero
    		while(sEnemiesBoundedIndex < smartEnemiesToDamage.size() && sEnemiesBoundedIndex < sEnemies.size()){ // keep in range
    			if(smartEnemiesToDamage.get(sEnemiesBoundedIndex) == true){ // if this enemy should be damaged
    				sEnemies.get(sEnemiesBoundedIndex).damage(10); // damage enemy
    				if(sEnemies.get(sEnemiesBoundedIndex).getAliveStatus() == false){ // if enemy is dead
    					sEnemies.remove(sEnemiesBoundedIndex); // remove enemy
    					smartEnemiesToDamage.remove(sEnemiesBoundedIndex);
    					Game.score += 150;
    					Player.totalKills++;
    					sEnemiesBoundedIndex--; // keep in bounds
    				}
    			}
    			sEnemiesBoundedIndex++;
    		}
    	}
    	
    	if(largeEnemiesToDamage.size() == lEnemies.size()){ // should be same, otherwise it would go out of range
    		int lEnemiesBoundedIndex = 0; // index position starts at zero
    		while(lEnemiesBoundedIndex < largeEnemiesToDamage.size() && lEnemiesBoundedIndex < lEnemies.size()){ // keep in range
    			if(largeEnemiesToDamage.get(lEnemiesBoundedIndex) == true){ // if this enemy should be damaged
    				lEnemies.get(lEnemiesBoundedIndex).damage(10); // damage enemy
    				if(lEnemies.get(lEnemiesBoundedIndex).getAliveStatus() == false){ // if enemy is dead
    					lEnemies.remove(lEnemiesBoundedIndex); // remove enemy
    					largeEnemiesToDamage.remove(lEnemiesBoundedIndex);
    					Game.score += 200;
    					Player.totalKills++;
    					lEnemiesBoundedIndex--; // keep in bounds
    				}
    			}
    			lEnemiesBoundedIndex++;
    		}
    	}
    		
    }
    
    public void DrawEnemies(Graphics2D g2d){
    	
    	for(int i = 0; i < bEnemies.size(); i++){
            bEnemies.get(i).draw(g2d);
        }
    	
    	for(int i = 0; i < sEnemies.size(); i++){
            sEnemies.get(i).draw(g2d);
    	}
    	
    	for(int i = 0; i < lEnemies.size(); i++){
            lEnemies.get(i).draw(g2d);
    	}
    	
    }
    
    public int getWaveNumber(){
    	return waveNumber;
    }
    
    public int getTotalEnemies(){
    	
    	int total = (bEnemies.size() + sEnemies.size() + lEnemies.size());
    	return total;
    	
    }
    
    public ArrayList<Rectangle> getBasicEnemyRectangles(){
    	
    	ArrayList<Rectangle> basicEnemyRectangles = new ArrayList<Rectangle>();
    	for(int i = 0; i < bEnemies.size(); i++){
    		Rectangle tempRectangle = new Rectangle();
    		tempRectangle = bEnemies.get(i).getBounds();
    		basicEnemyRectangles.add(tempRectangle);
    	}
    	
		return basicEnemyRectangles;
    			
    }
    
    public ArrayList<Rectangle> getSmartEnemyRectangles(){
    	
    	ArrayList<Rectangle> smartEnemyRectangles = new ArrayList<Rectangle>();
    	for(int i = 0; i < sEnemies.size(); i++){
    		Rectangle tempRectangle = new Rectangle();
    		tempRectangle = sEnemies.get(i).getBounds();
    		smartEnemyRectangles.add(tempRectangle);
    	}
    	
		return smartEnemyRectangles;
    			
    }

    public ArrayList<Rectangle> getLargeEnemyRectangles(){
	
    	ArrayList<Rectangle> largeEnemyRectangles = new ArrayList<Rectangle>();
    	for(int i = 0; i < lEnemies.size(); i++){
    		Rectangle tempRectangle = new Rectangle();
    		tempRectangle = lEnemies.get(i).getBounds();
    		largeEnemyRectangles.add(tempRectangle);
    	}
    	
    	return largeEnemyRectangles;
			
    }
    	
}
