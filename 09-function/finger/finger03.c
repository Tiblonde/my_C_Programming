/* 
 * Original is from Chapter 8 finger09.c,
 * Function version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

/* First call generate_random_walk() to initiate all element to '.'
 * then substitute some of them to alphebet
 * Next call print_array() to show the array
 */

int main(void) {
	char walk[10][10];

	generate_random_walk(walk);	
	print_array(walk);

	return 0;
}

void generate_random_walk(char walk[10][10]){
	/* Initiate the walk array */
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			walk[i][j] = '.';

	/* initial position */
	int x = 0, y = 0;
	walk[x][y] = 'A';	
	
	/* seed random by time */
	srand((unsigned) time(NULL));

	/* some variable useful */
	int dx[] = {0, -1, 0, 1};
	int dy[] = {1, 0, -1, 0};
	char value = 'A';
	int trap = 1, dir;

	while (value != 'Z') {
		/* check if the possible directions are filled */
		for (i = 0; i < 4; i++) 
			if ((x+dx[i]) >= 0 && (y+dy[i]) >=0 &&
				(x+dx[i]) <= 9 && (y+dy[i]) <=9 &&
				walk[x+dx[i]][y+dy[i]] == '.')
				trap = 0;

		if (trap)
			break;
		trap = 1;

		/* ensure the next postion in one loop */
		value++;
		while (1) {
			dir = rand()%4;
			if ((x+dx[dir]) >= 0 && (y+dy[dir]) >=0 &&
				(x+dx[dir]) <= 9 && (y+dy[dir]) <=9 &&
				walk[x+dx[dir]][y+dy[dir]] == '.') {		
				x += dx[dir];
				y += dy[dir];
				walk[x][y] = value;
				break;
			}
		}		
	}		
}

void print_array(char walk[10][10]) {
	int i, j;
	for (i = 0; i < 10 ; i++){
		for (j = 0; j < 10 ; j++)
			printf("%2c", walk[i][j]);
		printf("\n");
	}
}

