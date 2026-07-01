#include <stdio.h>

#define NAME_LENGTH 25
#define COUNTRY_NUM 3

struct country {
	char name[NAME_LENGTH];
	int number;
};


int main() {
	struct country country_list[COUNTRY_NUM] = {
		{"China", 10086}, 
		{"American", 20000}, 
		{"Estonia", 30000}
	};
	char name[NAME_LENGTH];
	int i;	

	printf("Enter the country: ");
	scanf("%s", name);

	for (i = 0; i < COUNTRY_NUM; i++) {
		if (country_list[i].name == name)
			printf("Number: %d\n", country_list[i].number);
	}
	printf("There is no the country in the list.\n");
	
	
	return 0;
}
