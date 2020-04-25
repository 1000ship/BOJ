import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		Scanner sc = new Scanner(System.in);
		
		boolean check = false;
		String str;
		for ( int i = 0; i < 5; ++ i )
		{
			str = sc.next();
			if( str.indexOf( "FBI" ) != -1 )
			{
				System.out.println( i + 1 );
				check = true;
			}
		}
		if( !check )
			System.out.println( "HE GOT AWAY!" );
	}
}
