#include <stdio.h>

float get_tex(float input);

int main(void) {
	float input, tax;

	printf("Enter your input: ");
	scanf("%g", &input);

	tax = get_tex(input);
	
	printf("Your tax is: %g\n", tax);

	return 0;
}

float get_tex(float input) {
	float tex;
	
	if (input < 750)
		tex = input * 0.01;
	else if (input < 2250)
		tex = 7.5 + (input - 750) * 0.02;
	else if (input < 3750)
		tex = 37.5 + (input - 2250) * 0.03;
	else if (input < 5250)
		tex = 82.5 + (input - 3750) * 0.04;
	else if (input < 7000)
		tex = 142.5 + (input - 5250) * 0.05;
	else
		tex = 230.0 + (input - 7000) * 0.06;

	return tex;
}
