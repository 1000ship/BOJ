import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		for( int i = 0; i < n; ++ i )
		{
			double f = sc.nextDouble() * 0.8;
			System.out.printf( "$%.2f\n", f );
		}
	}
}