import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		long k = sc.nextLong(), n = sc.nextLong(), max = 0;
		long arr[] = new long[ (int)k ];
		for( int i = 0; i < k; ++ i )
		{
			arr[ i ] = sc.nextLong();
			if( arr[ i ] > max ) max = arr[ i ];
		}
		
		long left = 1, right = max, mid = (left+right)/2;
		long value, result = 0;
		while( left <= right )
		{
			value = 0;
			for ( int i = 0; i < k; ++ i )
			{
				value += arr[ i ] / mid;
				if( value > n ) break;
			}
			if( value < n )
			{
				right = mid - 1;
				mid = (left+right)/2;
			}
			else if( value > n )
			{
				left = mid + 1;
				mid = (left+right)/2;
			}
			else
			{
				left = mid + 1;
				mid = (left+right)/2;
			}
			result = mid;
		}
		
		System.out.println( result );
	}
}
