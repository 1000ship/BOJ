import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		String str = "";
		while( sc.hasNextLine() )
			str += sc.nextLine();
		
		String arr[] = str.split( "," );
		BigInteger value = BigInteger.ZERO;
		for( int i = 0; i < arr.length; ++ i )
			value = value.add( new BigInteger( arr[ i ] ) );
		
		System.out.println( value );
	}
}