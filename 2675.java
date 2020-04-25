import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), howmany;
		String str;
		
		for( int i = 0; i < n; ++ i )
		{
			howmany = sc.nextInt();
			str = sc.next();
			for( int j = 0; j < str.length(); ++ j )
				for( int k = 0; k < howmany; ++ k )
					System.out.print( str.charAt( j ) );
			System.out.println();
		}
	}		
}