import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		
		String str = sc.next();
		String[] arr = str.split( "-" );
		String result = "";
		for( int i = 0; i < arr.length; ++ i )
			result += arr[ i ].substring( 0, 1 );
		System.out.println( result );
	}
}