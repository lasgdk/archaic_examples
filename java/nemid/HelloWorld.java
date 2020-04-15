import java.applet.*;
import java.awt.*;
import java.io.*;
import java.net.*;


public class HelloWorld extends Applet
{

   StringBuffer buffer;

    public void init() {
        buffer = new StringBuffer();
        addItem("initializing... ");
    }

    public void start() {
        addItem("starting... ");
		writeFile("picture","/tmp/bornepornoterror.txt");
		
		

		
		}

    public void stop() {
        addItem("stopping... ");
    }

    public void destroy() {
        addItem("preparing for unloading...");
    }

    private void addItem(String newWord) {
        System.out.println(newWord);
        buffer.append(newWord);
        repaint();
    }

    public void paint(Graphics g) {
	//Draw a Rectangle around the applet's display area.
        g.drawRect(0, 0, 
		   getWidth() - 1,
		   getHeight() - 1);
		g.drawString("FuskerApplet",20,40);
	    g.drawString("Gemmer et billede i /tmp...",20,60);

	//Draw the current string inside the rectangle.
        g.drawString(buffer.toString(), 5, 15);
    }

  public boolean writeFile(String text, String fileID) {
    try {
      File file = new File(fileID);
      FileWriter fWriter = new FileWriter(file);
      fWriter.write(text);
      fWriter.close();
      return true;
    } catch(IOException e) {
      return false;
    }
  }


}
