import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;
import javafx.stage.*;


public class Lab11q3 extends Application
{
	Label lbl1,lbl2,lbl3,lbl4;
	TextField tf1;
	PasswordField tf2;
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		myStage.setTitle("JavaFX Welcome");
		GridPane rootnode=new GridPane();
		rootnode.setMinSize(500,300);
		rootnode.setVgap(50);
		rootnode.setHgap(25);
		rootnode.setAlignment(Pos.CENTER);
		Scene myScene=new Scene(rootnode);
		myStage.setScene(myScene);

		lbl1=new Label("Welcome");
		lbl2=new Label("User Name");
		lbl3=new Label("Password");
		lbl4=new Label("");

		tf1=new TextField();
		tf2=new PasswordField();

		Button btn=new Button("Sign In");
		rootnode.add(lbl1,0,0);
		rootnode.add(lbl2,0,1);
		rootnode.add(lbl3,0,2);
		rootnode.add(tf1,1,1);
		rootnode.add(tf2,1,2);
		rootnode.add(lbl4,0,3);
		rootnode.add(btn,2,3);
		btn.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				lbl4.setText("Welcome "+tf1.getText());
			}
		});
		myStage.show();
	}
}
