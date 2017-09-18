package zombies2D;

public class PositionHistory {
	
	private int x, y;                 // position
    private double dx, dy;            // velocity
    
    PositionHistory(int x, int y, double dx, double dy){
    	
    	this.x = x;
    	this.y = y;
    	
    	this.dx = dx;
    	this.dy = dy;
    	
    }
    
    public int getX(){
    	return x;
    }
    
    public int getY(){
    	return y;
    }
    
    public double getDx(){
    	return dx;
    }
    
    public double getDy(){
    	return dy;
    }

}
