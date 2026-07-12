/* Prints a one-month reminder list */
/******************************************************
 * Input: 5 6:00 - Dinner with Marge and Russ
 * 		  date_num | reminder_msg
 ******************************************************/



#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

/*
 * 1. read date and msg, strcmp() to determine the location in array
 * 2. use strcmp to move forward all string behind it.
 * 3. copy it to array and strcat() reminder_msg after date
 */

int read_line(char str[], int n);

int main(void) {
	char reminders[MAX_REMIND][MSG_LEN+3]; // 
	char day_str[3], msg_str[MSG_LEN+1];
	int day, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}
		printf("Enter day and reminder: ");
		// Date handler:
		scanf("%2d", &day);
		if (day < 0 || day > 31) {
			printf("Error: Date not correct.\n");
			continue;
		}
		if (day == 0)
			break;
		sprintf(day_str, "%2d", day); // put string writed in stdout in day_str
		// Time handler:
		scanf("%2d:%2d", &hour, &minute);
		sprintf(time_str, "%2d:%2d", hour, minute)
		// Msg handler:
		read_line(msg_str, MSG_LEN);

		// String
		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
			
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_str);
		strcpy(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n) {

	int ch, i =0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
