import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		String str[] = sc.nextLine().split(" ");
		int count = 0;
		for( int i = 0; i < str.length; ++ i )
			if( str[ i ].length() != 0 ) count ++;
		System.out.println( count );
	}
}