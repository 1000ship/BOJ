import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;



class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int test_case = sc.nextInt();
		
		for (int idx_case = 0; idx_case < test_case; ++ idx_case )
		{
			int N = sc.nextInt(), M = sc.nextInt();
			
			//(N) C (M)
			BigInteger value = BigInteger.ONE;
			for( int i = 2; i <= M; ++ i )
				value = value.multiply( BigInteger.valueOf( i ) );
			for( int i = 2; i <= N; ++ i )
				value = value.divide( BigInteger.valueOf( i ) );
			for( int i = 2; i <= M - N; ++ i )
				value = value.divide( BigInteger.valueOf( i ) );
			
			System.out.println( value.toString() );
		}
	}
}