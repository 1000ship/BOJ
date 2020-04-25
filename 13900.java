import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		long arr[] = new long[ n ];
		long tmp = 0;
		
		BigInteger sum = BigInteger.ZERO;
		
		for( int i = 0; i < n; ++ i )
		{
			arr[ i ] = sc.nextLong();
			tmp += arr[ i ];
		}
		
		for( int i = 0; i < n - 1; ++ i )
		{
			tmp -= arr[ i ];
			sum = sum.add( BigInteger.valueOf( arr[ i ] * tmp ) );
		}
		
		System.out.println( sum.toString() );
	}
}

