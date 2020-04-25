import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		while( true )
		{
			String str = sc.nextLine();
			if( str.equals( "0" ) ) break;
			while( str.length() > 1 )
			{
				int value = 0;
				for( int i = 0; i < str.length(); ++ i )
				{
					value += Integer.valueOf( String.valueOf( str.charAt( i ) ) );
				}
				str = String.valueOf( value );
			}
			System.out.println( str );
		}
	}
}