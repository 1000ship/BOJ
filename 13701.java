import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static char arr[] = new char[ 4194304 ];
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int i;
		
		while( sc.hasNextInt() )
		{
			i = sc.nextInt();
			if( !checkAndRegist( i ) )
			{
				System.out.print( String.valueOf( i ) + " " );
			}
		}
	}
	
	public static boolean checkAndRegist ( int x )
	{
		int value = 1, idx = x / 8;
		value <<= x % 8;
		boolean result = ( arr[ idx ] & value ) != 0;
		arr[ idx ] |= value;
		return result;
	}
}

