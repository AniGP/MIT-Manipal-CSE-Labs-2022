import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.*;
import javafx.scene.image.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.paint.*;
import javafx.scene.text.*;
import javafx.geometry.*;
import javafx.event.*;
import java.util.*;

public class q1 extends Application
{
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		myStage.setTitle("Calculator");
		GridPane grid = new GridPane();
		Label l1 = new Label("Enter a no.:");
		Label l2 = new Label("Enter a no.:");
		Text t1 = new Text();
		Text t2 = new Text();
		Text t3 = new Text();
		Text t4 = new Text();
		// l1.setFont(new Font(15));
		// l2.setFont(new Font(15));
		// t1.setFont(new Font(15));
		// t2.setFont(new Font(15));
		// t3.setFont(new Font(15));
		// t4.setFont(new Font(15));
		TextField tf1 = new TextField();
		tf1.setText("");
		TextField tf2 = new TextField();
		tf2.setText("");
		Button b1 = new Button("Calc");

		grid.addRow(0,l1,tf1);
		grid.addRow(1,l2,tf2);
		grid.add(b1,3,3);
		grid.add(t1,1,4);
		grid.add(t2,1,5);
		grid.add(t3,1,6);
		grid.add(t4,1,7);
		grid.setVgap(5);
		grid.setHgap(5);
		b1.setOnAction(new EventHandler <ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				int x = Integer.parseInt(tf1.getText());
				int y = Integer.parseInt(tf2.getText());
				t1.setText("Sum = "+(x+y));
				t2.setText("Product = "+(x*y));
				t3.setText("Difference = "+Math.abs(x-y));
				t4.setText("Quotient = "+(Math.max(x,y)/Math.min(x,y)));
			}
		});
		Scene s = new Scene(grid, 600, 400);
		myStage.setScene(s);
		myStage.show();
	}
}