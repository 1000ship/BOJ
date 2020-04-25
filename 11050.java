import java.io.FileInputStream;
import java.util.Scanner;

class Main {
	
	public static int factorial ( int x )
	{
		if( x <= 1 ) return 1;
		return x * factorial( x - 1 );
	}
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int a, b;
		a = sc.nextInt();
		b = sc.nextInt();
		
		System.out.println( factorial( a ) / factorial( b ) / factorial( a - b ) );
		
	}
}
