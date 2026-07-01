#include <stdio.h>

//struct {int x, y;} x;
//struct {int x, y;} y;

int main() {
	struct {int x, y;} x={1, 2};
	struct {int x, y;} y={3, 4};
	
	
	printf("Struct x: %d, %d\n", x.x, x.y);
	printf("Struct y: %d, %d\n", y.x, y.y);

	return 0;
}
