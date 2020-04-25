import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		String[] arr = new String[]{
			sc.next(), sc.next()
		};
		BigInteger value = new BigInteger( arr[ 0 ] );
		value = value.add( new BigInteger( arr[ 1 ] ) );
		System.out.println( value.toString() );
	}
}