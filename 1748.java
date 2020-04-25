import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		long value = 0;
		
		for( int i = 1; i <= n; i *= 10 )
		{
			if( i * 10 <= n )
				value += Math.log10( i * 10 ) * (i*10 - i);
			else
				value += Math.log10( i * 10 ) * (n - i + 1);
		}
		System.out.println( value );
	}
}
