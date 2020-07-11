package application;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class Sample1Controller {

    @FXML
    private Button btnins;

    @FXML
    private TextField txt2;

    @FXML
    private TextField txt3;

    @FXML
    private TextField txt1;

    @FXML
    private Button btnupd;

    @FXML
    private Button btnclr;

    @FXML
    private Button btndel;
    
    static Connection dbConnect()
	{
		Connection con=null;
		
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			con=DriverManager.getConnection("jdbc:oracle:thin:@172.16.57.4:1521:orcl2","b2dbsl27","b2dbsl27");
		}
		
		catch(Exception e)
		{
			System.out.print(e);
		}
		
		return con;
	}

    @FXML
    void insertRec(){
    	
    	try
		{
			Connection con=dbConnect();
			String s1 = txt1.getText().toString();
			String s2 = txt2.getText().toString();
			int b = Integer.parseInt(txt3.getText());
			PreparedStatement ps = con.prepareStatement("insert into Department values(' "+s1+" ',' "+s2+" ', "+b+" ) ");
			ps.execute();
			System.out.println("INSERTED");
			con.close();
		}
		
		catch(Exception e)
		{
			System.out.print(e);
		}

    }

    @FXML
    void deleteRec() 
    {
   
        try 
        {
	        Connection conn = dbConnect();
	        String s1 = txt1.getText().toString();
	        PreparedStatement ps = conn.prepareStatement("delete from department where dept_name = '"+s1+"'");
	        ps.execute();
	        System.out.println("Deleted");
	        conn.close();
        }
        
        catch(Exception e)
        {
        	System.out.print(e);
        }
    }

    @FXML
    void updateRec() {

    }

    @FXML
    void clearTxt() {

    }

}

/* String SQL = "SELECT * from" + tblname + "";
//ResultSet
ResultSet rs = con.createStatement().executeQuery(SQL);
while(rs.next())
{
	txt1.setText(rs.getString(i));
}*/