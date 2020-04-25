import java.math.BigInteger;
import java.util.Scanner;
 
public class Main {
	static public BigInteger t[];
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner( System.in );
		
		t = new BigInteger[37];
		t[ 0 ] = new BigInteger( "1" );
		
		int n = sc.nextInt();
		System.out.println( getT( n ).toString() );
	}
	
	public static BigInteger getT ( int n )
	{
		if( t[ n ] != null ) return t[ n ];
		
		BigInteger tmp = BigInteger.ZERO;
		for( int i = 0; i < n; ++ i )
		{
			tmp = tmp.add( getT( i ).multiply( getT( n - i - 1 ) ) );
		}
		t[ n ] = tmp;
		return t[ n ];
	}
}