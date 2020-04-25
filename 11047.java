import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int cnt = 0, n = sc.nextInt();
		long k = sc.nextInt();
		long a[] = new long[ n ];
		for ( int i = 0; i < n; ++ i )
			a[ i ] = sc.nextLong();
		
		for( int i = n - 1; i >= 0; -- i )
		{
			cnt += k / a[ i ];
			k %= a[ i ];
		}
		
		System.out.print( cnt );
		
	}		
}