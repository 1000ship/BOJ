import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;



class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		char A[] = new char[N];
		char B[] = new char[N];

		for( int i = 0; i < N; ++ i )
			A[ i ] = (char)sc.nextInt();
		for( int i = 0; i < N; ++ i )
			B[ i ] = (char)sc.nextInt();
		
		sorting( A, false );
		sorting( B, true );
		
		int result = 0;
		for( int i = 0; i < N; ++ i )
			result += A[ i ] * B[ i ];
		System.out.println( result );
	}
	
	public static void sorting ( char arr[], boolean isAsc )
	{
		for ( char i = 0; i < arr.length - 1; ++ i )
		{
			char m = arr[ i ], idx = i;
			for ( char j = (char)(i + 1); j < arr.length; ++ j )
				if( (isAsc) ? m < arr[ j ] : m > arr[ j ] )
					m = arr[ idx = j ];
			if( idx != i )
			{
				arr[ idx ] = arr[ i ];
				arr[ i ] = m;
			}
		}
	}
}