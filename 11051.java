import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static int calculate ( int n, int k )
	{
		BigInteger tmp = new BigInteger( "1" );
		int first = (n-k>k)?n-k:k, second = (n-k>k)?k:n-k;
		for( int i = n; i > first; -- i )
		{
			tmp = tmp.multiply( new BigInteger( "" + i ) );
		}
		for( int i = 2; i <= second; ++ i )
			tmp = tmp.divide( new BigInteger( "" + i ) );
		tmp = tmp.mod( new BigInteger( "10007" ) );
		return tmp.intValue();
	}
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int a, b;
		a = sc.nextInt();
		b = sc.nextInt();
		
		System.out.println( calculate( a, b ) );
	}
}
