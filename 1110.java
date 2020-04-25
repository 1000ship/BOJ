import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int first, value, count = 0;
		first = value = sc.nextInt();
		
		while( count == 0 || first != value )
		{
			value = (value % 10)*10 + ( (value / 10) + (value % 10) ) % 10;
			count++;
		}
		
		System.out.println( count );
		
	}		
}