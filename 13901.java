import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/*
 * 첫 번째 줄에는 방의 크기 R, C(3 ≤ R, C ≤ 1,000)가 입력된다. 두 번째 줄에는 장애물의 개수 k(0 ≤ k ≤ 1,000)가 입력된다.
 * 다음 k개의 줄에는 각 장애물 위치 br(0 ≤ br ≤ R – 1), bc(0 ≤ bc ≤ C - 1)가 주어진다. 그 다음 순서대로 로봇의 시작 위치
 * sr(0 ≤ sr ≤ R – 1), sc(0 ≤ sc ≤ C - 1)와 이동 방향의 순서(총 4개가 입력되는데 1은 위 방향, 2은 아래 방향, 3은 왼쪽 방향,
 * 4는 오른쪽 방향을 나타낸다)가 한 줄씩 입력된다. 로봇의 시작위치에 장애물이 있는 경우는 없다.
 */

class Main {
	
	public static void visualize ( short arr[][], short R, short C )
	{
		for( int i = 0; i < R; ++ i )
		{
			for( int j = 0; j < C; ++ j )
			{
				System.out.print( arr[i][j] );
			}
			System.out.println();
		}
		System.out.println("----------------------------");
	}
	
	public static void main(String args[]) throws Exception	{
        
		//Scanner sc = new Scanner(new FileInputStream("sample_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		short a, b, R = sc.nextShort(), C = sc.nextShort();
		short arr[][] = new short[ R ][ C ];
		short obsNum = sc.nextShort();
		
		for ( int i = 0; i < obsNum; ++ i )
			arr[ sc.nextInt() ][ sc.nextInt() ] = 2;
		
		Point record = new Point( (short)0, (short)0 );
		Point pos = new Point( sc.nextShort(), sc.nextShort() );
		short rule[] = new short[]{
				sc.nextShort(), sc.nextShort(), sc.nextShort(), sc.nextShort()
		};

		boolean isChange = true;
		while( isChange )
		{
			record.r = pos.r;
			record.c = pos.c;
			for( int i = 0; i < 4; ++ i )
			{
				boolean isPlaying = true;
				while( isPlaying )
				{
					arr[ pos.r ][ pos.c ] = 1;
					switch( rule[ i ] )
					{
					case 1: // up
						if( pos.r == 0 || arr[ pos.r - 1 ][ pos.c ] != 0 )
							isPlaying = false;
						else pos.r -= 1;
						break;
					case 2: // down
						if( pos.r == R - 1 || arr[ pos.r + 1 ][ pos.c ] != 0 )
							isPlaying = false;
						else pos.r += 1;
						break;
					case 3: // left
						if( pos.c == 0 || arr[ pos.r ][ pos.c - 1 ] != 0 )
							isPlaying = false;
						else pos.c -= 1;
						break;
					case 4: // right
						if( pos.c == C - 1 || arr[ pos.r ][ pos.c + 1 ] != 0 )
							isPlaying = false;
						else pos.c += 1;
						break;
					}
				}
			}
			//visualize( arr, R, C );
			if( record.r == pos.r && record.c == pos.c )
				isChange = false;
		}
		
		System.out.println( pos.r + " " + pos.c );
	}
}

class Point {
	public short r;
	public short c;
	
	public Point ( short i, short j )
	{
		this.r = i;
		this.c = j;
	}

}

