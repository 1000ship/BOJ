import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		String str;
		while( sc.hasNextLine() )
		{
			int a, b, c, d;
			char cha;
			str = sc.nextLine();
			a = b = c = d = 0;
			for( int i = 0; i < str.length(); ++ i )
			{
				cha = str.charAt( i );
				if( cha >= 'a' && cha <= 'z' )
					a++;
				else if( cha >= 'A' && cha <= 'Z' )
					b++;
				else if( cha >= '0' && cha <= '9' )
					c++;
				else if( cha == ' ' )
					d++;
			}
			System.out.println( a + " " + b + " " + c + " " + d );
		}
	}
}
