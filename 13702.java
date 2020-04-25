import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), k = sc.nextInt();
		long arr[] = new long[ n ];
		long value = -1, step;
		for( int i = 0; i < n; ++ i )
		{
			arr[ i ] = sc.nextInt();
			if( value == -1 || value < arr[ i ] ) value = arr[ i ];
		}
		step = value - 1;
		
		while( true )
		{
			long num = 0;
			for( int i = 0; i < n; ++ i )
			{
				num += arr[ i ] / value;
				if( num > k ) break;
			}
			
			if( num < k )
			{			
				value -= step;
				if( value <= 0 )
				{
					value += step;
					step = step - step / 2;
					value -= step;
					continue;
				}
			}
			else if( num >= k )
			{
				if( step == 1 )
				{
					break;
				}
				else
				{
					value += step;
					step = step - step / 2;
					value -= step;
					continue;
				}
			}
		}
		
		System.out.println( value );
	}
}