#include <stdio.h>

int main(void) {
	int hour, min;
	char day;

	printf("Enter a 12-hour time: ");
	scanf("%2d:%2d %c", &hour, &min, &day);

	if ((day == 'A') || (day == 'P' && hour == 12))
		min += hour * 60;
	else
		min += (hour + 12) * 60;

	printf("equivalent 24-hour time: %.2d:%.2d\n", min / 60, min % 60);

	return 0;
}
