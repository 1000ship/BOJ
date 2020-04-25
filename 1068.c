#include <stdio.h>

int n, tmp;

typedef struct NODE {
	int parent;
	int valid;
	int isReaf;
} Node;
Node nodes[50];


int isValid ( int idx )
{
	if( nodes[ idx ].parent == -1 ) return nodes[ idx ].valid;
	if( nodes[ idx ].valid == 0 ) return 0;
	return isValid( nodes[ idx ].parent );
}

int main(void) {
	
	scanf( "%d", &n );
	for( int i = 0; i < n; ++ i ){
		scanf("%d", &tmp);
		nodes[ i ].parent = tmp;
		nodes[ i ].valid = 1;
		nodes[ i ].isReaf = 1;
	}
	for( int i = 0; i < n; ++ i ){
		if( nodes[i].parent == -1 ) continue;
		nodes[ nodes[i].parent ].isReaf = 0;
	}
	
	scanf( "%d", &tmp );
	nodes[ tmp ].valid = 0;
	if(nodes[tmp].parent != -1 ){
		nodes[ nodes[tmp].parent ].isReaf = 1;
		for( int i = 0; i < n; ++ i ){
			if( isValid( i ) ){
				if(nodes[ i ].parent == nodes[ tmp ].parent){
					nodes[ nodes[tmp].parent ].isReaf = 0;
					break;
				}
			}
		}
	}
	
	tmp = 0;
	for( int i = 0; i < n; ++ i ){
		if( isValid( i ) && nodes[ i ].isReaf ) tmp++;
	}
	printf( "%d", tmp );
	
	return 0;
}
