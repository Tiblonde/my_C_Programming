#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int roll_dice(void);
bool play_game(void);

int main(void) {
	bool flag;
	char ch;
	int result[2] = {0, 0};

	(flag = play_game()) ? result[0]++ : result[1]++;
	flag ? printf("You win!\n") : printf("You loss!\n");
	printf("Play again? "); 
	while ((ch = getchar()) == 'y' || (ch == 'Y')) {
		getchar();
		printf("\n\n");
	
		(flag = play_game()) ? result[0]++ : result[1]++;
		flag ? printf("You win!\n") : printf("You loss!\n");
		printf("Play again? ");
	}

	printf("Wins: %d Losees: %d\n", result[0], result[1]);
	
	return 0;
}

int roll_dice(void){
	srand((unsigned) time(NULL));

	return (rand()%6 + rand()%6 + 2); 
}

bool play_game(void) {
	int target;
	int result;

	target = roll_dice();
	printf("You rolled: %d \n", target);

	if (target == 7 || target == 11)
		return true;
	else if (target == 2 || target == 3 || target == 12)
		return false;
	else
		printf("Your point is %d\n", target);

	while (result = roll_dice()) {
		printf("You rolled: %d\n", result);
		if (result == 7)
			return false;
		else if (result == target)
			return true;
	}
}
