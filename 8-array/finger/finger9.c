#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	char maze[10][10];
	int i, j, x, y, flag = 1, dir;
	char letter = 'A';

	int dx[] = { 0, 1, 0, -1};
	int dy[] = {-1, 0, 1,  0};
	
	x = y = 0;
	srand( (unsigned) time(NULL));

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			maze[i][j] = '.';
	maze[x][y] = letter;

	/* TEST PHASE */
	printf("Maze has been initiated!\n");

	while (letter != 'Z') {
		/* TEST PHASE */
		//printf("%c ready for fill!\n", letter);	

		for (i = 0; i < 4; i++){
			if ( (x + dx[i]) >= 0 && (y + dy[i]) >= 0 &&
				 (x + dx[i]) <= 9 && (y + dy[i]) <= 9 &&
				maze[x+dx[i]][y+dy[i]] == '.')
				flag = 0; // means there is empty position
		}
		if (flag){
			printf("Oops there is nowhere to walk\n");
			break;
		}
		flag = 1;
		/* TEST PHASE */
		//printf("Successfully enter loop!\n");
		
		dir = rand() % 4;
		if ((x + dx[dir]) >= 0 && (y + dy[dir]) >=0 &&
		    (x + dx[dir]) <= 9 && (y + dy[dir]) <= 9 &&
			maze[x+dx[dir]][y+dy[dir]] == '.') {
			x += dx[dir];
			y += dy[dir];
			maze[x][y] = ++letter;
		}
		
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
		

	return 0;	
}
