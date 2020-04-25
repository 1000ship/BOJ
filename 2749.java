import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);

		int p = 1500000;
		int arr[] = new int[p];
		arr[ 0 ] = 0; arr[ 1 ] = 1;
		for (int i=2; i< p; i++)
		{
	        arr[ i ] = arr[ i - 1 ] + arr[ i - 2 ];
	        arr[ i ] %= 1000000;
	    }
		
		BigInteger value = new BigInteger( sc.next() );
		value = value.mod( BigInteger.valueOf( p ) );
		System.out.println( arr[ value.intValue() ] );
	}
}