import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;


class Main {
	
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int test_case = sc.nextInt();
		
		for (int idx_case = 0; idx_case < test_case; ++ idx_case )
		{
			int cnt = 0;
			Point start = new Point( sc.nextInt(), sc.nextInt() );
			Point end = new Point( sc.nextInt(), sc.nextInt() );
			int starNum = sc.nextInt();
			Point star = new Point( 0, 0 );
			int radius;
			
			for( int i = 0; i < starNum; ++ i )
			{
				star.x = sc.nextInt();
				star.y = sc.nextInt();
				radius = sc.nextInt();
				
				boolean a = start.isEnclose( star, radius ), b = end.isEnclose( star, radius ); 
				if( ( a && b ) == false && (a || b) == true )
				{
					cnt++;
				}
			}
			
			System.out.println( cnt );
		}
	}
}

class Point
{
	public int x;
	public int y;
	
	public Point ( int x, int y )
	{
		this.x = x;
		this.y = y;
	}
	
	public boolean isEnclose ( Point p, int radius )
	{
		if( Math.sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) < radius )
			return true;
		return false;
	}
}