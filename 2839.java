import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static int min = 1000000;
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int result = -1;
		for( int i = 0; i <= n; i += 3 )
		{
			if( ( n - i ) % 5 == 0 )
			{
				result = ( n - i ) / 5 + i / 3;
				break;
			}
		}
		System.out.println( result );
	}
}