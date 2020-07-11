import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;
import javafx.stage.*;
import javafx.scene.paint.Color;

public class Lab11q1 extends Application
{
	public static void main(String args[])
	{
		launch(args);
	}

	public void start(Stage myStage)
	{
		myStage.setTitle("This the first JavaFX Application");
		FlowPane rootnode=new FlowPane();

		Scene myScene=new Scene(rootnode,500,200);
		myStage.setScene(myScene);
		Label l1=new Label("Welcome to JavaFX programming");
		Label l2=new Label("Welcome to JavaFX programming");

		l1.setTextFill(Color.MAGENTA);

		rootnode.setHgap(40);
		rootnode.setVgap(60);
		rootnode.getChildren().addAll(l1,l2);
		myStage.show();
	}
}