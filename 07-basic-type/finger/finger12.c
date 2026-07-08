#include <stdio.h>

int main(void) {
	float sum = 0, value;
	char ch;
	printf("Enter an expression: ");
	scanf("%f", &sum);
	for (;;) {
		if ((ch = getchar()) == '\n') break;
		if (scanf("%f", &value) == 1)
			switch (ch) {
			case '+': sum = sum + value; break;
			case '*': sum = sum * value; break;
			case '/': sum = sum / value; break;
			case '-': sum = sum - value; break;
			}
	}
	printf("Value of expression: %f\n", sum);
	return 0;
}
