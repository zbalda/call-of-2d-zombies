package zombies2D;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;

import zombies2D.Framework.GameState;

/**
 * Actual Game
 * 
 * loosely adapted from www.gametutorial.net framework
 */

public class Game {
	
	private Player player; // handles player, position history, weapon, and bullets
    private Waves waves; // handles waves, wave number, spawning, updating players, and kills
    
    public static int score;
    
    private BufferedImage backgroundImg;
    
    private BufferedImage mouseCursorImg;
    private int mouseCursorImgWidth;
    private int mouseCursorImgHeight;
    
    private Font F1stats;
    private Font gameStatsLeft;
    private Font gameStatsRight;
    private Font gameTitle;
    private Font gameOver;
    private Font healthTitle;
    private Font endGameInstructions;
    public static boolean displayF1stats;

    public Game(){
    	
        Framework.gameState = Framework.GameState.GAME_CONTENT_LOADING;
        
        Thread threadForInitGame = new Thread() {
            @Override
            public void run(){
            	
                Initialize(); // Sets variables and objects for the game
                LoadContent(); // Loads game files (images, sounds, ...)
                
                Framework.gameState = Framework.GameState.PLAYING;
            }
        };
        threadForInitGame.start();
        
    }
    
    private void Initialize(){ // Set variables and objects for the game
    			
        player = new Player(Framework.frameWidth / 4, Framework.frameHeight / 4); // handles player, position history, weapon, and bullets
        waves = new Waves(); // handles enemies, waves, wave number, spawning, and kills
        
        score = 0;
        
        
        F1stats = new Font("arial", Font.PLAIN, 12);
        gameStatsLeft = new Font("arial", Font.BOLD, 30);
        gameStatsRight = new Font("arial", Font.BOLD, 30);
        gameTitle = new Font("arial", Font.BOLD, 40);
        gameOver = new Font("arial", Font.BOLD, 50);
        healthTitle = new Font("arial", Font.BOLD, 40);
        endGameInstructions = new Font("arial", Font.PLAIN, 20);
        displayF1stats = false;
        
    }
    
    private void LoadContent(){
    	
        try {
            URL backgroundImgUrl = this.getClass().getResource("/resources/playerViewBasic.png");
            backgroundImg = ImageIO.read(backgroundImgUrl); // Background image
            
            URL mouseCursorImgUrl = this.getClass().getResource("/resources/sightHair.png");
            mouseCursorImg = ImageIO.read(mouseCursorImgUrl); // Mouse Cursor image
            
            mouseCursorImgWidth = mouseCursorImg.getWidth() / 2;
            mouseCursorImgHeight = mouseCursorImg.getHeight() / 2;
        } catch (IOException ex) {
            Logger.getLogger(Game.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    public void RestartGame(){
    	
        player = new Player(Framework.frameWidth / 4, Framework.frameHeight / 4);
        waves = new Waves();
        
        score = 0;
        
    }
    
    
    public void UpdateGame(long gameTime, Point mousePosition) throws IOException{
    	
    	if(player.getAliveStatus() == true){
    		
    		player.Update();
    		player.UpdateWeapon(gameTime, mousePosition);
    		
    		waves.UpdateWaves(gameTime); // incomplete
    		waves.UpdateEnemies(player.getPositionHist()); // incomplete
    		
    		CollisionDetection(gameTime);
    		
    	} else {
    		Framework.gameState = GameState.GAMEOVER;			
    	}
    			
    }
    
    public void CollisionDetection(long gameTime){
    	
    	// Enemy rectangles
    	ArrayList<Rectangle> basicEnemyRectangles = new ArrayList<Rectangle>();
    	basicEnemyRectangles = waves.getBasicEnemyRectangles();
    	ArrayList<Rectangle> smartEnemyRectangles = new ArrayList<Rectangle>();
    	smartEnemyRectangles = waves.getSmartEnemyRectangles();
    	ArrayList<Rectangle> largeEnemyRectangles = new ArrayList<Rectangle>();
    	largeEnemyRectangles = waves.getLargeEnemyRectangles();
    	
    	// Bullet rectangles
    	ArrayList<Rectangle> bulletRectangles = new ArrayList<Rectangle>();
    	bulletRectangles = player.getBulletRectangles();
    	
    	// Player rectangle
    	Rectangle playerRectangle = player.getBounds();
    	
    	// Bullet remove booleans
    	ArrayList<Boolean> bulletsToRemove = new ArrayList<Boolean>();
    	for(int i = 0; i < bulletRectangles.size(); i++){
    		bulletsToRemove.add(false);
    	}
    	
    	// Enemy damage booleans
    	ArrayList<Boolean> basicEnemiesToDamage = new ArrayList<Boolean>();
    	ArrayList<Boolean> smartEnemiesToDamage = new ArrayList<Boolean>();
    	ArrayList<Boolean> largeEnemiesToDamage = new ArrayList<Boolean>();
    	
    	for(int i = 0; i < basicEnemyRectangles.size(); i++){
    		basicEnemiesToDamage.add(false);
    	}
    	for(int i = 0; i < smartEnemyRectangles.size(); i++){
    		smartEnemiesToDamage.add(false);
    	}
    	for(int i = 0; i < largeEnemyRectangles.size(); i++){
    		largeEnemiesToDamage.add(false);
    	}
    	
    	// bullet enemy collision tracking  	
    	for(int a = 0; a < bulletRectangles.size(); a++){
    		for(int b = 0; b < basicEnemyRectangles.size(); b++){
    			if(basicEnemyRectangles.get(b).intersects(bulletRectangles.get(a))){
    				bulletsToRemove.set(a, true);
    				basicEnemiesToDamage.set(b, true);
    			}
    		}
    		for(int b = 0; b < smartEnemyRectangles.size(); b++){
    			if(smartEnemyRectangles.get(b).intersects(bulletRectangles.get(a))){
    				bulletsToRemove.set(a, true);
    				smartEnemiesToDamage.set(b, true);
    			}
    		}
    		for(int b = 0; b < largeEnemyRectangles.size(); b++){
    			if(largeEnemyRectangles.get(b).intersects(bulletRectangles.get(a))){
    				bulletsToRemove.set(a, true);
    				largeEnemiesToDamage.set(b, true);
    			}
    		}
    	}
    	
    	// enemy updating
    	waves.damageEnemies(basicEnemiesToDamage, smartEnemiesToDamage, largeEnemiesToDamage);
    	
    	// bullet updating
    	player.removeBullets(bulletsToRemove);
    	
    	
    	// player enemy collision detection and updating
    	for(int i = 0; i < basicEnemyRectangles.size(); i++){
			if(basicEnemyRectangles.get(i).intersects(playerRectangle)){
				player.tryDamagePlayer(gameTime);
			}
		}
    	for(int i = 0; i < smartEnemyRectangles.size(); i++){
			if(smartEnemyRectangles.get(i).intersects(playerRectangle)){
				player.tryDamagePlayer(gameTime);
			}
		}
    	for(int i = 0; i < largeEnemyRectangles.size(); i++){
			if(largeEnemyRectangles.get(i).intersects(playerRectangle)){
				player.tryDamagePlayer(gameTime);
			}
		}
    	
    	/*
    	 * for each bullet, check if bullet collides with enemy
    	 *     if bullet does collide, subtract health from enemy, getAliveStatus to possibly remove enemy, and remove bullet
    	 * for each enemy, check if enemy collides with player
    	 *     if enemy collides with player, subtract from player health, getAliveStatus from player to possible end game
    	 *  
    	 *  call update method for player first
    	 *  then call update methods for bullets and enemies
    	 */
    	
    	player.getAliveStatus();
    	
    }
    
    
    public void Draw(Graphics2D g2d, Point mousePosition, long gameTime){
    	
        if(player.getAliveStatus() == true){
        	g2d.drawImage(backgroundImg, 0, 0, Framework.frameWidth, Framework.frameHeight, null);
        
        	player.DrawBullets(g2d);
        	waves.DrawEnemies(g2d);
        	player.DrawPlayer(g2d);
        
        	DrawGameStatistics(g2d, mousePosition, gameTime);
        	drawMouseCursor(g2d, mousePosition);
        }
        
    }
    
    public void DrawGameStatistics(Graphics2D g2d, Point mousePosition, long gameTime){
    	
    	if(displayF1stats == true){
    		g2d.setFont(F1stats);
    		g2d.drawString(Framework.frameWidth + " x " + Framework.frameHeight + " Display", 50, 50);
    		double roundedPlayerDX = Math.round((player.getDX() * 100)) / 100;
    		double roundedPlayerDY = Math.round((player.getDY() * 100)) / 100;
    		g2d.drawString("PLAYER: X " + player.getX() + " Y " + player.getY(), 50, 80);
    		g2d.drawString("PLAYER: DX " + roundedPlayerDX + " DY " + roundedPlayerDY, 50, 110);
    		g2d.drawString("MOUSE: X " + mousePosition.x + " Y " + mousePosition.y, 50, 140);
    		g2d.drawString("Total Enemies: " + waves.getTotalEnemies(), 50, 170);
    		g2d.drawString("Enemies To Be Spawned: " + Waves.totalEnemiesToBeSpawned, 50, 200);
    		g2d.drawString("Bullet Count: " + player.getBulletCount(), 50, 230);
    	}
    	
    	// gameStats
    	g2d.setFont(gameStatsLeft);
    	g2d.drawString("Wave " + Waves.waveNumber, 50, Framework.frameHeight - 100);
    	g2d.drawString("Kills " + player.getTotalKills(), 50, Framework.frameHeight - 50);
    	g2d.setFont(gameStatsRight);
    	int width = g2d.getFontMetrics().stringWidth(("Ammo " + Weapon.ammo));
    	g2d.drawString("Ammo " + Weapon.ammo, Framework.frameWidth - (width + 50), Framework.frameHeight - 100);
    	g2d.drawString("Score " + score, Framework.frameWidth - (width + 50), Framework.frameHeight - 50);
    	
    	g2d.setFont(healthTitle);
    	g2d.setColor(Color.RED);
    	g2d.drawString("HEALTH " + player.getHealth(), Framework.frameWidth - 300, 80);
    	g2d.setColor(Color.BLACK);
        
    }
    
    private void drawMouseCursor(Graphics2D g2d, Point mousePosition){
    	
    	g2d.drawImage(mouseCursorImg, mousePosition.x - mouseCursorImgWidth, mousePosition.y - mouseCursorImgHeight, null);
    	
    }
    
    public void DrawGameOver(Graphics2D g2d){
    	
    	g2d.drawImage(backgroundImg, 0, 0, Framework.frameWidth, Framework.frameHeight, null);
        
    	player.DrawBullets(g2d);
    	waves.DrawEnemies(g2d);
    	player.DrawPlayer(g2d);
    	
    	g2d.setFont(gameTitle);
    	g2d.drawString("Call of 2D Zombies", Framework.frameWidth / 2 - 180, Framework.frameHeight / 3 - 30);
    	g2d.setFont(gameOver);
    	g2d.drawString("GAME OVER", Framework.frameWidth / 2 - 150, Framework.frameHeight / 3 + 80);
    	
    	g2d.setFont(gameStatsLeft);
    	g2d.drawString("Wave: " + Waves.waveNumber, Framework.frameWidth / 2 - 50, Framework.frameHeight / 2);
    	g2d.drawString("Kills: " + player.getTotalKills(), Framework.frameWidth / 2- 50, Framework.frameHeight / 2 + 40);
    	g2d.drawString("Score: " + score, Framework.frameWidth / 2 - 50, Framework.frameHeight / 2 + 80);
    	
    	g2d.setFont(endGameInstructions);
    	g2d.drawString("Use WASD or arrow keys to move", (Framework.frameWidth / 2) - 150, (int)(Framework.frameHeight * .7) + 150);
        g2d.drawString("Use left mouse button to shoot", (Framework.frameWidth / 2) - 136, (int)(Framework.frameHeight * .7) + 200);
        g2d.drawString("Press enter to restart", (Framework.frameWidth / 2) - 100, (int)(Framework.frameHeight * .7) + 100);                
        g2d.drawString("Press ESC any time to exit the game", (Framework.frameWidth / 2) - 167, (int)(Framework.frameHeight * .7) + 50);
    	
    }

}
    