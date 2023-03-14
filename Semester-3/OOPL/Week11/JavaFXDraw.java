import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.scene.paint.*;
import javafx.scene.canvas.*;
import javafx.scene.input.MouseEvent;
import javafx.geometry.*;

public class JavaFXDraw extends Application 
{
  
  GraphicsContext gc;
  String st="";
  
  public static void main(String[] args) 
  {
    // Start the JavaFX application by calling launch().
    launch(args);
  }
  // Override the start() method.
  public void start(Stage myStage) 
  {
    // Give the stage a title.
    myStage.setTitle("Draw Shapes");

    FlowPane rootNode = new FlowPane(10, 10);


    Scene myScene = new Scene(rootNode, 800, 500);

    myStage.setScene(myScene);
    Canvas canvas = new Canvas(500,800);
    gc = canvas.getGraphicsContext2D();


    // Create the radio buttons.
    RadioButton rbc = new RadioButton("circle");
    RadioButton rbr = new RadioButton("rectangle");
    RadioButton rbl = new RadioButton("line");
    ToggleGroup tg = new ToggleGroup();
    rbc.setToggleGroup(tg);
    rbr.setToggleGroup(tg);
    rbl.setToggleGroup(tg);

    rbc.setOnAction(new MyHandler()); 
    rbr.setOnAction(new MyHandler()); 
    rbl.setOnAction(new MyHandler()); 
    rootNode.getChildren().addAll(rbc, rbr, rbl, canvas);
    myStage.show();
    canvas.addEventFilter(MouseEvent.MOUSE_DRAGGED, new EventHandler<MouseEvent>() 
    {
      double x,y,x1,y1;
      
      public void handle(MouseEvent mouseEvent) 
      {
        if(mouseEvent.getEventType() == MouseEvent.MOUSE_CLICKED)
        {
            
          x=mouseEvent.getX();
          y=mouseEvent.getY();
        }
        
        if(mouseEvent.getEventType() == MouseEvent.MOUSE_DRAGGED )
        {
          x1=mouseEvent.getX();
          y1=mouseEvent.getY();
          
          gc.setFill(Color.WHITE);
	        gc.fillRect(0,0,500,500);
          
          if("line".equals(st))
          {
             
	          gc.strokeLine(x,y,x1,y1);
            gc.strokeText("line drawn",25,450);
          }
          
          else if("rectangle".equals(st))
          {
	         gc.strokeRect(x,y,x1-x,y1-y);
           gc.setFill(Color.RED);
           gc.strokeText("Area of rectangle=" + (x1-x)*(y1-y),25,450);
          }
          
          else 
          {
            gc.strokeOval(x,y,x1-x,x1-x);
            gc.strokeText("Area of circle=" + 3.14*(x1-x)*(x1-x)/(37.8*37.8),25,450);
          }
        }
      }
    });
  }
  
  class MyHandler implements EventHandler<ActionEvent>
  {
    public void handle(ActionEvent ae) 
    {
	    // getSource() returns a java.lang.Object. Downcast back to Button.
      st=((RadioButton)ae.getSource()).getText();
    }
  }
}