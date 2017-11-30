package zombies2D;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;

/**
 * Framework that controls the game (Game.java) that created it, update it and draw it on the screen.
 *
 * adapted from www.gametutorial.net framework
 */

public class Framework extends Canvas {

	private static final long serialVersionUID = -8040167743186258742L;

	public static int frameWidth;
    public static int frameHeight;
    public static final long secInNanosec = 1000000000L; // 1 second = 1,000,000,000 nanoseconds
    public static final long milisecInNanosec = 1000000L; // 1 millisecond = 1,000,000 nanoseconds
    private final int GAME_FPS = 60; // how many times it updates and draws per second
    private final long GAME_UPDATE_PERIOD = secInNanosec / GAME_FPS; // pauses between updates in nanoseconds
    public static enum GameState{STARTING, VISUALIZING, GAME_CONTENT_LOADING, MAIN_MENU, OPTIONS, PLAYING, GAMEOVER, DESTROYED} // game states
    public static GameState gameState; // current game state
    private long gameTime; // elapsed game time in nanoseconds
    private long lastTime; // used for calculating elapsed time

    private Game game; // actual game and game objects

    private Font menuTitle;
    private Font menuInstructions;
    private BufferedImage menuImg; // menu image

    public Framework (){

    	super();
        gameState = GameState.VISUALIZING;
        Thread gameThread = new Thread() { // new thread for game loop
            @Override
            public void run(){
                GameLoop();
            }
        };
        gameThread.start();

    }

    private void Initialize(){

    	menuTitle = new Font("arial", Font.BOLD, 80);
    	menuInstructions = new Font("arial", Font.PLAIN, 20);

    }

    private void LoadContent(){
        try {
            URL menuImgUrl = this.getClass().getResource("/resources/playerViewBasic.png");
            menuImg = ImageIO.read(menuImgUrl);
        } catch (IOException ex) {
            Logger.getLogger(Framework.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private void GameLoop(){ // In specific intervals of time (GAME_UPDATE_PERIOD) the game/logic is updated and then the game is drawn on the screen.
        // This two variables are used in VISUALIZING state of the game. We used them to wait some time so that we get correct frame/window resolution.
        long visualizingTime = 0, lastVisualizingTime = System.nanoTime();

        // This variables are used for calculating the time that defines for how long we should put threat to sleep to meet the GAME_FPS.
        long beginTime, timeTaken, timeLeft;

        while(true)
        {
            beginTime = System.nanoTime();

            switch (gameState)
            {
                case PLAYING:
                    gameTime += System.nanoTime() - lastTime;

            				try {
            					game.UpdateGame(gameTime, mousePosition());
            				} catch (IOException e) {
            					// TODO Auto-generated catch block
            					e.printStackTrace();
            				}

                    lastTime = System.nanoTime();

                break;
                case GAMEOVER:
                    //...
                break;
                case MAIN_MENU:
                    //...
                break;
                case OPTIONS:
                    //...
                break;
                case GAME_CONTENT_LOADING:
                    //...
                break;
                case STARTING:
                    // Sets variables and objects.
                    Initialize();
                    // Load files - images, sounds, ...
                    LoadContent();

                    // When all things that are called above finished, we change game status to main menu
                    gameState = GameState.MAIN_MENU;
                break;
                case VISUALIZING:
                    // On Ubuntu OS this.getWidth() method doesn't return the correct value immediately
                	// e.g. for frame that should be 800px width, returns 0 then 790 and at last 798px
                    // So we wait one second for the window/frame to be set to its correct size. Just in case we
                    // also insert 'this.getWidth() > 1' condition in case when the window/frame size wasn't set in time
                    if(this.getWidth() > 1 && visualizingTime > secInNanosec)
                    {
                        frameWidth = this.getWidth();
                        frameHeight = this.getHeight();

                        // When we get size of frame we change status.
                        gameState = GameState.STARTING;
                    }
                    else
                    {
                        visualizingTime += System.nanoTime() - lastVisualizingTime;
                        lastVisualizingTime = System.nanoTime();
                    }

                    // Temporary for bug fixing

                break;
			default:
				break;
            }

            // Repaint the screen.
            repaint();

            // Here we calculate the time that defines for how long we should put threat to sleep to meet the GAME_FPS.
            timeTaken = System.nanoTime() - beginTime;
            timeLeft = (GAME_UPDATE_PERIOD - timeTaken) / milisecInNanosec; // In milliseconds
            // If the time is less than 10 milliseconds, then we will put thread to sleep for 10 millisecond so that some other thread can do some work.
            if (timeLeft < 10)
                timeLeft = 10; //set a minimum
            try {
                 //Provides the necessary delay and also yields control so that other thread can do work.
                 Thread.sleep(timeLeft);
            } catch (InterruptedException ex) { }
        }
    }

    @Override
    public void Draw(Graphics2D g2d){ // Draw the game to the screen. It is called through repaint() method in GameLoop() method.
        switch (gameState){
            case PLAYING:
                game.Draw(g2d, mousePosition(), gameTime);
            break;
            case GAMEOVER:
                game.DrawGameOver(g2d);
            break;
            case MAIN_MENU:
                g2d.drawImage(menuImg, 0, 0, frameWidth, frameHeight, null);
                g2d.setFont(menuTitle);
                g2d.drawString("Call of 2D Zombies", (frameWidth / 2) - 360, frameHeight / 3);
                g2d.setFont(menuInstructions);
                g2d.drawString("Use WASD or arrow keys to move", (frameWidth / 2) - 145, (int)(frameHeight * .7) - 50);
                g2d.drawString("Use left mouse button to shoot", (frameWidth / 2) - 138, (int)(frameHeight * .7));
                g2d.drawString("Click with left mouse button to start the game", (frameWidth / 2) - 200, (int)(frameHeight * .7) + 50);
                g2d.drawString("Press ESC any time to exit the game", (frameWidth / 2) - 170, (int)(frameHeight * .7) + 100);
                g2d.setColor(Color.white);
            break;
            case OPTIONS:
                //...
            break;
            case GAME_CONTENT_LOADING:
                g2d.setColor(Color.white);
                g2d.drawString("GAME is LOADING", frameWidth / 2 - 50, frameHeight / 2);
            break;
		default:
			break;
        }
    }


    private void newGame(){
        gameTime = 0;
        lastTime = System.nanoTime();
        game = new Game();
    }

    private void restartGame(){
        gameTime = 0;
        lastTime = System.nanoTime();
        game.RestartGame();
        gameState = GameState.PLAYING; // We change game status so that the game can start
    }

    private Point mousePosition(){
        try {
            Point mp = this.getMousePosition();
            if(mp != null) { return this.getMousePosition(); } // returns the position of the mouse pointer in game frame/window.
            else { return new Point(0, 0); }
        } catch (Exception e){
            return new Point(0, 0); // if position is null, return 0, 0 coordinates
        }
    }

    @Override
    public void keyReleasedFramework(KeyEvent e){ // called when a key is released
        switch (gameState){
            case GAMEOVER:
                if(e.getKeyCode() == KeyEvent.VK_ESCAPE)
                    System.exit(0);
                else if(e.getKeyCode() == KeyEvent.VK_SPACE || e.getKeyCode() == KeyEvent.VK_ENTER)
                    restartGame();
            break;
            case PLAYING:
            	if(e.getKeyCode() == KeyEvent.VK_F1){
            		if(Game.displayF1stats == false){
            			Game.displayF1stats = true;
            		} else if(Game.displayF1stats == true){
            			Game.displayF1stats = false;
            		}
            	}
            case MAIN_MENU:
                if(e.getKeyCode() == KeyEvent.VK_ESCAPE)
                    System.exit(0);
            break;
		default:
			break;
        }
    }

    @Override
    public void mouseClicked(MouseEvent e){ // called when a mouse button is clicked
        switch (gameState){
            case MAIN_MENU:
                if(e.getButton() == MouseEvent.BUTTON1)
                    newGame();
            break;
		default:
			break;
        }
    }
}
