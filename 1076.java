import java.io.FileInputStream;
import java.util.Scanner;

/*
 * 색	값	곱
black	0	1
brown	1	10
red	2	100
orange	3	1000
yellow	4	10000
green	5	100000
blue	6	1000000
violet	7	10000000
grey	8	100000000
white	9	1000000000
 */

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		String str = "black brown red orange yellow green blue violet grey white";
		String[] arr = str.split( " " );
		
		long a, b, c;
		a = indexOf( arr, sc.next() );
		b = indexOf( arr, sc.next() );
		c = indexOf( arr, sc.next() );
		
		long result = a * 10 + b;
		result *= Math.pow( 10, c );
		System.out.println( result );
	}
	
	public static int indexOf( String[] arr, String str )
	{
		for ( int i = 0; i < arr.length; ++ i )
			if( str.equals( arr[ i ] ) )
				return i;
		return -1;
	}
}