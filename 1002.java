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
			long x1, y1, r1, x2, y2, r2, max, min;
			x1 = sc.nextInt();
			y1 = sc.nextInt();
			r1 = sc.nextInt();
			x2 = sc.nextInt();
			y2 = sc.nextInt();
			r2 = sc.nextInt();
			max = (r1>r2)?r1:r2;
			min = (r1>r2)?r2:r1;
			double dist = Math.sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
			
			if( x1 == x2 && y1 == y2 )
				if( r1 == r2 ) System.out.println( -1 );
				else System.out.println( 0 );
			else if( (double)max > (double)min + dist )
				System.out.println( 0 );
			else if( (double)max == (double)min + dist )
				System.out.println( 1 );
			else if( (double)(max + min) > dist )
				System.out.println( 2 );
			else if( (double)(max+min) == dist )
				System.out.println( 1 );
			else
				System.out.println( 0 );
		}
	}
}

