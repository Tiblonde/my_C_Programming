#include <stdio.h>

void find_closet_flight(int desired_time, int *departure_time, 
						int *arrival_time);


int main(void) {
	int hour, min;
	int departure_time, arrival_time;
	int advice;
	printf("Enter a 24-hour time: "); // 13:15
	scanf("%d:%d", &hour, &min);
	find_closet_flight(hour*60+min, &departure_time, &arrival_time);
	
	if (departure_time < 12*60)
		printf("Closest departure time is %d:%d a.m.,", 
			departure_time/60, departure_time%60);
	else
		printf("Closest departure time is %d:%d p.m.,", 
			departure_time/60 - 12, departure_time%60);

	if (arrival_time < 12*60)
		printf(" arriving at %d:%d a.m.\n", 
			arrival_time/60, arrival_time%60);
	else
		printf(" arriving at %d:%d p.m.\n", 
			arrival_time/60 - 12, arrival_time%60);
	

	return 0;		
}

void find_closet_flight(int desired_time, int *departure_time, 
						int *arrival_time) {
	int takeoff[] = {8*60, 9*60+43, 11*60+19, 12*60+47,
					14*60, 15*60+45, 19*60, 21*60+45};
	int arrival[] = {10*60+16, 11*60+52, 13*60+31, 15*60,
					16*60+8, 17*60+55, 21*60+20, 23*60+58};
	int i, idx;
	for (i=0; i < sizeof(takeoff)/sizeof(takeoff[0]); i++)
		if (desired_time < takeoff[i]){
			idx = i-1;
			break;
		}
	*departure_time = takeoff[idx];
	*arrival_time = arrival[idx];
}
