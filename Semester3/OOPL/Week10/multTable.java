import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.text.*;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;
public class multTable extends Application
{
	@Override
	public void start(Stage mainStage)
	{
		Label l1 = new Label("Enter number :");
		Label l2 = new Label("Enter limit : ");
		GridPane grid = new GridPane();
		TextField tf = new TextField();
		TextField tf1 = new TextField();
		Button b1= new Button("Result");
		Canvas canvas = new Canvas(200,200);
		GraphicsContext gc = canvas.getGraphicsContext2D();
		b1.setOnAction(new EventHandler <ActionEvent>()
		{
			@Override
			public void handle(ActionEvent arg0)
			{
				gc.clearRect(0,0,400,200);
				gc.setFont(new Font(20));
				int n = Integer.parseInt(tf.getText());
				int lim = Integer.parseInt(tf1.getText());
				int x = 0, y = 20;
				for(int i =1;i<=10;i++,y+=20)
				{
					gc.fillText(n+" * "+i+" = "+(n*i), x,y);
				}

			}
		});
		grid.addRow(0, l1,l2,tf,tf1);
		grid.addRow(1,b1);
		grid.add(canvas,1,2);
		Scene s = new Scene(grid, 500, 500);
		mainStage.setScene(s);
		mainStage.setTitle("Multiplication Table");
		mainStage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}