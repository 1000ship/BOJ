import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), k = sc.nextInt();
		int tem[] = new int[ n ];
		int sum[] = new int[ n - k + 1 ];
		for( int i = 0; i < n; ++ i )
			tem[ i ] = sc.nextInt();
		for( int i = 0; i < n - k + 1; ++ i )
			for( int j = 0; j < k; ++ j )
				sum[ i ] += tem[ i + j ];
		
		int max = sum[ 0 ];
		for( int i = 0; i < n - k + 1; ++ i )
			if( max < sum[ i ] )
				max = sum[ i ];
		System.out.println( max );
	}		
}