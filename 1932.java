import java.io.FileInputStream;
import java.util.Scanner;

class Main {
	
	static public int n;
	static public int score[][];
	
	static public int getMaxValue ( )
	{
		for ( int i = 2; i <= n; ++ i )
		{
			for( int j = 0; j < i; ++ j )
			{
				// 0 ~ i - 1 에서 0, i - 1 을 제외하고는 ...
				if( j == 0 ) score[ i - 1 ][ j ] += score[ i - 2 ][ j ];
				else if( j == i - 1 ) score[ i - 1 ][ j ] += score[ i - 2 ][ j - 1 ];
				else
				{
					// j와 j + 1 둘 중 큰 것을 선택
					score[ i - 1 ][ j ] += (score[ i - 2 ][ j - 1 ] > score[ i - 2 ][ j ] )?score[ i - 2 ][ j - 1 ]:score[ i - 2 ][ j ];
				}
			}
		}
		
		int tmp = score[ n - 1 ][ 0 ];
		for ( int i = 1; i < n; ++ i )
		{
			if( tmp < score[ n - 1 ][ i ] ) tmp = score[ n - 1 ][ i ];
		}
 		return tmp;
	}
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		score = new int[500][500];
		for ( int i = 1; i <= n; ++ i )
		{
			for( int j = 0; j < i; ++ j )
			{
				score[ i-1 ][ j ] = sc.nextInt();
			}
		}
		
		System.out.println( "" + getMaxValue() );
	}
}
