package com.loafgames.dinot;

import java.awt.*;
import java.awt.event.*;

import javax.swing.JFrame;

public class HelloWorld extends JFrame {

	private static final long serialVersionUID = 1L;
	private int radius = 20;
	private double xPos = radius;
	private double yPos = radius;
	private double xSpeed = 0;
	private double ySpeed = 0;
	private double speedDecay = 1.0125;
	private Image dbImage;
	private Image smile;
	private Graphics dbg;
	private Graphics smileGraphics;
	private Color smileyColor;
	private int colorGreen = 255;

	public static void main(String[] args) {
		new HelloWorld();
	}

	public HelloWorld() {
		super("Hello World");
		add(new MovingCanvas());
		setResizable(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		pack();
		setVisible(true);
	}

	private class MovingCanvas extends Canvas implements Runnable, KeyListener {
		private static final long serialVersionUID = 1391109630401257463L;

		public MovingCanvas() {
			setBackground(Color.BLACK);
			addKeyListener(this);
			setSize(300, 300);
			Thread th = new Thread(this);
			th.start();
		}

		@Override
		public void run() {
			Thread.currentThread().setPriority(Thread.MIN_PRIORITY);

			while(true) {
				if(xPos > getSize().width - radius) {
					xSpeed *= -1;
					xPos = getSize().width - radius;
					colorGreen -= 60;
					if(colorGreen < 0)
						colorGreen = 0;
				} else if(xPos < radius) {
					xSpeed *= -1;
					xPos = radius;
					colorGreen -= 60;
					if(colorGreen < 0)
						colorGreen = 0;
				}
				if(yPos > getSize().height - radius) {
					ySpeed *= -1;
					yPos = getSize().height - radius;
					colorGreen -= 60;
					if(colorGreen < 0)
						colorGreen = 0;
				} else if(yPos < radius) {
					ySpeed *= -1;
					yPos = radius;
					colorGreen -= 60;
					if(colorGreen < 0)
						colorGreen = 0;
				}

				xPos += xSpeed;
				yPos += ySpeed;
				xSpeed /= speedDecay;
				ySpeed /= speedDecay;
				if(xSpeed < 0.5 && xSpeed > -0.5)
					xSpeed = 0;
				if(ySpeed < 0.5 && ySpeed > -0.5)
					ySpeed = 0;

				smileyColor = new Color(255, colorGreen, 0);
				repaint();
				if(colorGreen < 255) {
					colorGreen += 1;
					if(colorGreen > 255)
						colorGreen = 255;
				}

				try {
					Thread.sleep(20);
				} catch(InterruptedException ex) {}

				Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
			}
		}

		@Override
		public void update(Graphics g) {
			if(dbImage == null) {
				dbImage = createImage(2500, 2500);
				dbg = dbImage.getGraphics();
				smile = createImage(radius, radius / 2);
				smileGraphics = smile.getGraphics();
			}

			dbg.setColor(getBackground());
			dbg.fillRect(0, 0, getSize().width, getSize().height);

			dbg.setColor(getForeground());
			paint(dbg);

			g.drawImage(dbImage, 0, 0, this);
		}

		@Override
		public void paint(Graphics g) {
			int x = (int) Math.round(xPos);
			int y = (int) Math.round(yPos);

			g.setColor(smileyColor);
			g.fillOval(x - radius, y - radius, 2 * radius, 2 * radius);
			g.setColor(Color.BLACK);
			g.fillOval(x - ((radius / 2) + (radius / 6)), y - (radius / 2),
					radius / 2, radius / 2);
			g.fillOval(x + ((radius / 2) - (radius / 3)), y - (radius / 2),
					radius / 2, radius / 2);

			smileGraphics.setColor(smileyColor);
			smileGraphics.fillRect(0, 0, smile.getWidth(this),
					smile.getHeight(this));
			smileGraphics.setColor(Color.BLACK);
			smileGraphics.fillOval(
					0,
					-(smile.getHeight(this))
							+ (int) ((1 - ((double) colorGreen / 255)) * smile
									.getHeight(this)), smile.getWidth(this),
					smile.getHeight(this) * 2);
			g.drawImage(smile, x - (smile.getWidth(this) / 2),
					y + (smile.getHeight(this) / 2), this);
		}

		@Override
		public void keyPressed(KeyEvent e) {
			int key = e.getKeyCode();
			if(key == KeyEvent.VK_LEFT) {
				xSpeed = xSpeed - 3;
			} else if(key == KeyEvent.VK_RIGHT) {
				xSpeed = xSpeed + 3;
			} else if(key == KeyEvent.VK_SPACE) {
				xSpeed = 0;
				ySpeed = 0;
			} else if(key == KeyEvent.VK_UP) {
				ySpeed = ySpeed - 3;
			} else if(key == KeyEvent.VK_DOWN) {
				ySpeed = ySpeed + 3;
			}
		}

		@Override
		public void keyReleased(KeyEvent e) {
		}

		@Override
		public void keyTyped(KeyEvent e) {
		}
	}
}
