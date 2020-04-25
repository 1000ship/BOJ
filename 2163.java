import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), m = sc.nextInt();
		int value = n - 1;
		value += n * (m-1);
		System.out.println( value );
	}		
}