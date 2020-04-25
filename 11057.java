import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		BigInteger value = BigInteger.ONE, modValue = BigInteger.valueOf( 10007 );
		int from = n + 9, to = n;
		for ( int i = from; i > to; -- i )
			value = value.multiply( BigInteger.valueOf( i ) );
		for ( int i = 9; i > 1; -- i )
			value = value.divide( BigInteger.valueOf( i ) );
		value = value.mod( BigInteger.valueOf( 10007 ) );
		
		System.out.print( value );
	}		
}