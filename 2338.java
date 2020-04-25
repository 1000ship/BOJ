import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		BigInteger a = new BigInteger( sc.next() );
		BigInteger b = new BigInteger( sc.next() );

		System.out.println( a.add( b ) );
		System.out.println( a.subtract( b ) );
		System.out.println( a.multiply( b ) );
	}
}
