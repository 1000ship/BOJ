import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int arr[][] = new int[][]{
				{10},
				{1},
				{2,4,8,6},
				{3,9,7,1},
				{4,6},
				{5},
				{6},
				{7,9,3,1},
				{8,4,2,6},
				{9,1}
			};
		int num[] = new int[]{
				1,1,4,4,2,1,1,4,4,2
		};
		
		for ( int i = 0; i < n; ++ i )
		{
			int a = sc.nextInt() % 10, b = sc.nextInt(), c = 1;
			System.out.println( arr[a][ (b-1) % num[a] ] );
		}
	}
}
