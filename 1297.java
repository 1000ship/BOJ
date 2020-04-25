import java.io.FileInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		double len = sc.nextInt(), h = sc.nextInt(), w = sc.nextInt();
		double width = Math.sqrt( len*len / ( 1 + (h*h)/(w*w) ) );
		double height = Math.sqrt( len*len / ( 1 + (w*w)/(h*h) ) );
		
		System.out.println( (int)height + " " + (int)width );
	}
}