import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int row = sc.nextInt(), col = sc.nextInt();
		char color[][] = new char[row][col];
		
		for( int i = 0; i < row; ++ i )
		{
			String str = sc.next();
			for( int j = 0; j < col; ++ j )
				color[ i ][ j ] = str.charAt( j );
		}
		
		int min = row*col, cnt;
		for( int i = 0; i < row - 7; ++ i )
		for( int j = 0; j < col - 7; ++ j )
		{
			cnt = 0;
			for( int x = 0; x < 8; ++ x )
			for( int y = 0; y < 8; ++ y )
				if( color[ i + x ][ j + y ] == (((x+y)%2==0)?'B':'W') )
					cnt += 1;
			if( min > cnt ) min = cnt;
			if( min > 64 - cnt ) min = 64 - cnt;
		}
		
		System.out.println( min );
	}
}