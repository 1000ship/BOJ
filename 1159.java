import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		char arr[] = new char[ 26 ], tmp;
		String str, result = "";
		
		for ( int i = 0; i < n; ++ i )
		{
			str = sc.next();
			tmp = str.charAt( 0 );
			arr[ tmp - 'a' ] ++;
		}
		
		for( int i = 0; i < 26; ++ i )
			if( arr[ i ] >= 5 )
				result += String.valueOf( (char)( 'a' + i ) );
		if( result.length() == 0 )
			result = "PREDAJA";
		
		System.out.println( result );
	}
}