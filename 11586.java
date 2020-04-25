import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		String arr[] = new String[ n ];
		for( int i = 0; i < n; ++ i )
			arr[ i ] = sc.next();
		int code = sc.nextInt();
		
		switch( code )
		{
		case 1:
			for( int i = 0; i < n; ++ i )
				System.out.println( arr[ i ] );
			break;
		case 2:
			for( int i = 0; i < n; ++ i )
			{
				for( int j = n - 1; j >= 0; -- j )
					System.out.print( arr[ i ].charAt( j ) );
				System.out.println();
			}
			break;
		case 3:
			for( int i = n-1; i >= 0; -- i )
				System.out.println( arr[ i ] );
			break;
		}
	}		
}