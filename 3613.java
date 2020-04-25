import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		String str = sc.next();
		boolean justError = str.indexOf( "__" ) != -1;
		if( str.charAt( str.length() - 1 ) == '_' ) justError = true;
		if( str.charAt( 0 ) == '_' ) justError = true;
		
		boolean hasUnderbar = str.indexOf('_') != -1;
		boolean hasUpper = false;
		for( int i = 0; i < str.length(); ++ i )
			if( str.charAt( i ) >= 'A' && str.charAt( i ) <= 'Z' )
			{
				hasUpper = true;
				if( i == 0 ) justError = true;
				break;
			}
		
		if( justError || (hasUnderbar && hasUpper) )
			System.out.println( "Error!" );
		else if( !hasUnderbar && !hasUpper )
			System.out.println( str );
		else
		{
			if( hasUnderbar )
			{
				boolean check = false;
				for( int i = 0; i < str.length(); ++ i )
				{
					if( str.charAt( i ) == '_' )
						check = true;
					else
					{
						System.out.print( (char)(str.charAt( i ) - ((check)?'a'-'A':0)) );
						check = false;
					}
				}
			}
			else
			{
				for( int i = 0; i < str.length(); ++ i )
				{
					if( str.charAt( i ) >= 'A' && str.charAt( i ) <= 'Z' )
						System.out.print( "_" + (char)(str.charAt( i ) + ('a'-'A')) );
					else
						System.out.print( str.charAt( i ) );
				}
			}
		}
	}
}
