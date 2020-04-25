import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;



class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int setPrice = -1;
		int price = -1;
		
		for ( int i = 0; i < M; ++ i )
		{
			int a = sc.nextInt(), b = sc.nextInt();
			if( setPrice == -1 || setPrice > a ) setPrice = a;
			if( price == -1 || price > b ) price = b;
		}
		if( price * 6 < setPrice ) setPrice = price * 6;
		
		int result = 0;
		result += (N/6) * setPrice;
		if( (N%6) * price > setPrice  ) result += setPrice;
		else result += (N%6) * price;
		
		System.out.println( result );
	}
}