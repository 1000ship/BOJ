import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static int min = 10000000;
	
	public static void calculate ( int n, int cnt )
	{
		if( n == 1 )
		{
			if( min > cnt ) min = cnt;
			return;
		}
		if( min <= cnt ) return;
		
		if( n % 3 == 0 ) calculate( n / 3, cnt + 1 );
		if( n % 2 == 0 ) calculate( n / 2, cnt + 1 );
		calculate( n - 1, cnt + 1 );
	}
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		calculate( n, 0 );
		System.out.println( min );
	}
}