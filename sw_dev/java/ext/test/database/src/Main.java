
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try
		{
			sqlite.SQLite_Main.run(args);
			//mysql.MySQLMain.run(args);
		}
		catch (ClassNotFoundException e)
		{
    		System.err.println(e);
		}
	}

}
