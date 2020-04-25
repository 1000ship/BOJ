import java.util.Scanner;

class Main {
	
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		// 시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.
		int a = sc.nextInt();
		char b = ' ';
		switch( (int)(a / 10) )
		{
		case 10:
		case 9:
			b = 'A';
			break;
		case 8:
			b = 'B';
			break;
		case 7:
			b = 'C';
			break;
		case 6:
			b = 'D';
			break;
		default:
			b = 'F';
			break;
		}
		System.out.println( b );
	}
}