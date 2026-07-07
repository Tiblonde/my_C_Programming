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

}

void generate_random_walk(char walk[10][10]){
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			walk[i][j] = '.';
	walk[0][0] = 'A';	
	
	srand((unsigned) time(NULL));

	for (i = 0; i < 26; i++)
		direction = rand() % 4;
		

	
}

