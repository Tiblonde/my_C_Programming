#include <stdio.h>

int time_to_min(void);

int main(void) {
	int min, i;
	int takeoff[] = {8*60, 9*60+43, 11*60+19, 12*60+47,
					14*60, 15*60+45, 19*60, 21*60+45};
	int arrival[] = {10*60+16, 11*60+52, 13*60+31, 15*60,
					16*60+8, 17*60+55, 21*60+20, 23*60+58};
	int advice;
	printf("Enter a 24-hour time: "); // 13:15
	min = time_to_min();

	advice = 0;
	for (i = 0; i < sizeof(takeoff) / sizeof(takeoff[0]); i++) {
		if (takeoff[i] > min){
			advice = i - 1;
			break;
		}
	}

	printf("min: %d, advice: %d\n", min, advice);
	
	if (takeoff[advice] < 12*60)
		printf("Closest departure time is %d:%d a.m.,", 
			takeoff[advice]/60, takeoff[advice]%60);
	else
		printf("Closest departure time is %d:%d p.m.,", 
			takeoff[advice]/60 - 12, takeoff[advice]%60);

	if (arrival[advice] < 12*60)
		printf(" arriving at %d:%d a.m.\n", 
			arrival[advice]/60, arrival[advice]%60);
	else
		printf(" arriving at %d:%d p.m.\n", 
			arrival[advice]/60 - 12, arrival[advice]%60);
	

	return 0;		
}

int time_to_min(void) {
	int hour, min;
	scanf("%d:%d", &hour, &min);

	min += hour * 60;
	
	return min;
}
