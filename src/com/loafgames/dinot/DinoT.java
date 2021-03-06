package com.loafgames.dinot;
import org.newdawn.slick.AppGameContainer;
import org.newdawn.slick.BasicGame;
import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.SlickException;

public class DinoT extends BasicGame
{
	public DinoT()
	{
		super("DinoT");
	}
	
	@Override
	public void init(GameContainer container) throws SlickException{}
	
	@Override
	public void update(GameContainer container, int delta) throws SlickException{}
	
	@Override
	 public void render(GameContainer container, Graphics g) throws SlickException
	 {
		g.drawString("Hello, Slick world!", 0, 100);
	 }
	
	 public static void main(String[] args)
	 {
		try
		{
			AppGameContainer app = new AppGameContainer(new DinoT());
			app.start();
		}
		catch(SlickException e)
		{
			 e.printStackTrace();
		}
	}
}