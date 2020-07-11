import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.scene.control.*;
import javafx.scene.paint.*;
import javafx.scene.canvas.*;
import javafx.event.*;

public class JavaFxScrolltext extends Application implements Runnable 
{

  String msg;
  Thread t1 = null; 
  GraphicsContext gc;
  TextField tf;
  Canvas canvas;
  
  public static void main(String[] args) 
  {
    Application.launch(args);
  }
    
  @Override
  public void start(Stage stage) 
  {
    canvas = new Canvas(300,250);
    gc = canvas.getGraphicsContext2D();
    tf=new TextField();
    FlowPane root=new FlowPane(10,10);
    root.getChildren().addAll(tf,canvas);
    Scene scene = new Scene(root);
    stage.setScene(scene);
    stage.setTitle("A Responsive UI");
    stage.show();
      
    tf.setOnAction(new EventHandler<ActionEvent>() 
    {
      public void handle(ActionEvent ae) 
      {
		    startTask();
      }});   
    }
    
    public void startTask() 
    {
      t1=new Thread(this);
      t1.start();
    }
    
    public void run() 
    { 
      msg=tf.getText();
      char ch;
       
      for(;;) 
      { 

        try 
        {
   	
          // Update the Label on the JavaFx Application Thread
          Platform.runLater(new Runnable() 
          {
            public void run()
            {
		          gc.setFill(Color.WHITE);
		          
               /*  x - the X position of the upper left corner of the rectangle.
		            y - the Y position of the upper left corner of the rectangle.
		            w - the width of the rectangle.
		            h - the height of the rectangle*/
   	            
                gc.fillRect(25,25,200,400);
   	          
               // font can be set setFont(new Font("Arial",20));
                gc.strokeText(msg, 50, 80);}});
                Thread.sleep(500);
                ch = msg.charAt(0);
                msg = msg.substring(1, msg.length());
                msg += ch;
            }
            
            catch (InterruptedException e) 
            {
		          e.printStackTrace();
            }
          }
        }
      }