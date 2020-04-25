import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		long files[] = new long[ n ];
		for( int i = 0; i < n; ++ i )
			files[ i ] = sc.nextLong();
		long unit = sc.nextLong();
		long value = 0;
		
		for( int i = 0; i < n; ++ i )
			value += files[ i ] / unit + ((files[ i ]%unit==0)?0:1);
		System.out.println( value * unit );
	}
}