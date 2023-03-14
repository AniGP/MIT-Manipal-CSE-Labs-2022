import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.event.*;
import javafx.geometry.*;

public class gcd extends Application
{
	public static void main(String[] args)
	{
		launch(args);
	}
	
	public void start(Stage myStage)
	{
		myStage.setTitle("GCD");
		FlowPane root = new FlowPane(100 , 100);
		Scene myScene = new Scene(root , 500 , 300);
		
		Label lbl1 = new Label("Enter a Number : ");
		Label Result = new Label("");
		TextField tf1 = new TextField("Enter the number");
		
		Label lbl2 = new Label("Enter another Number : ");
		TextField tf2 = new TextField("Enter the number");
		
		EventHandler<ActionEvent> event = new EventHandler<ActionEvent>() 
		{
		
			public void handle(ActionEvent e)
			{
				int n1 = Integer.parseInt(tf1.getText());
				int n2 = Integer.parseInt(tf2.getText());
				int gcd = 1;
			
				for(int i = 1; i <= n1 && i <= n2; ++i)
				{
					if(n1 % i==0 && n2 % i==0)
						gcd = i;
				} 
			
				Result.setText(""+"GCD of "+n1+" and "+n2+" = "+gcd);
			}
		};
		
		tf2.setOnAction(event);
		root.getChildren().add(lbl1);
		root.getChildren().add(tf1);
		root.getChildren().add(lbl2);
		root.getChildren().add(tf2);
		root.getChildren().add(Result);
		myStage.setScene(myScene);
		myStage.show();
	}
}