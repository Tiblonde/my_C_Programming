# 16 structure, union and enumeration

structure is the collection of members with (possible) different type. union is similar to structure but shares memory with members. enumeration is integer type with specific name.

## 16.1 structure variable

The only data structure we have introduced is array, whose elements share same data type and use index to access.

structure's elements (or members) share possible different type, each of them has name, so to access specific struct members by its name.

For example, to record parts in the repository, including the part number, the part name and the number of part, we can declare:
```c
	struct {
		int number;
		char name[NAME_LEN + 1]l;
		int on_hand;
	} part1, part2;
```
each struct variable has three members. 

Notice: such declaration follows the basic priciple, like int i, where struct {} is the type, part1 and part2 are variable.

members of struct is stored in order. Assuming that part1 is stored at the memory 2000, integer takes 4 bytes, NAME_LEN = 25, and no interval between each member:
	|2000|  <-|
	|2001|	  | number
	|2002|	  |
	|2003|	<-|
	|2004|	<--|
	|....|	   | name
	|2029|  <--|
	|2030|  <---|
	|....|		| on_hand
	|2033|  <---|

### 16.1.2 initiate struct variable

struct variable can be initiated at the declaration:
```c
	struct {
		int number;
		char name[NAME_LEN + 1]l;
		int on_hand;
	} part1 = {528, "Disk drive", 10},
	  part2 = {914, "Printer cable", 5};
```
one can initiate struct variable by specific initiation:
```c
	{.number = 528, .name = "Disk drive", .on_hand  10}
```
the dot and member name combination is called indicator.

### 16.1.4 operations on struct

Accessing member of struct is through name. Using struct_name.member_name one can access member of struct:
```c
	printf("Part number: %d\n", part1.number);
	printf("Part name: %s\n", part1.name);
	printf("Quantity on hand: %d\n", part1.on_hand);
```
Notice: member of struct is lvalue, so it can occur on the left side of assignment statement:
```c
	part1.number = 258;
	part1.on_hand++;
```

Another operation on struct is assignment, struct can be copied by =:
```c
	part2 = part1;
	/* part2.number = part1.number;
	 * part2.name = part1.name;
	 * part2.on_hand = part2.on_hand;
	 */
```
Recall: array cannot use assign to copy.

## 16.2 struct type

Since part1 and part2 (struct variable) don't have struct type, it is illegal to assign them even they have the same declaration:
```c
	struct {
		int number;
		char name[NAME_LEN + 1]l;
		int on_hand;
	} part2;

	part2 = part1; /***WRONG***/
```
So we may counter problem when we need this same struct later.

### 16.2.1 declartion of struct tag

struct tag is the name to tag one specific struct:
```c
	/* declare a struct tag "part" */
	struct part{
		int number;
		char name[NAME_LEN + 1]l;
		int on_hand;
	};
```
Once struct tag is declared, one can use it to reduce the declaration:
```c
	// Method 1:
	struct part part1, part2;

	// Method 2:
	struct part{
		int number;
		char name[NAME_LEN + 1]l;
		int on_hand;
	} part1 

	// Illegal
	part part1, part2; /***WRONG***/
```

### 16.2.2 definition of struct type

Besides declare struct tag, one can use typedef to define the actual type name:
```c
	typedef struct {
		int number;
		char name[NAME_LEN + 1]l;
		int on_hand;
	} Part;
```
Notice that type name Part is in the end instead of behind struct.

### 16.2.3 struct as argument and return value

functions can have argument and return value with struct type:
```c
	// function with struct type argumnet
	void print_part(struct part p) {
		printf("Part number: %d\n", p.number);
		printf("Part name: %s\n", p.name);
		printf("Quantity on hand: %d\n", p.on_hand);
	}
	...
	print_part(part1);

	// function with struct type return val
	struct part build_part(int number, const char *name, int on_hand) {
		struct part p;
		p.number = number;
		strcpy(p.name, name);
		p.on_hand = on_hand;
		return p;
	}
```
## 16.3 nested array and struct

array can use struct elements and struct can use struct or array members.

```c
	struct person_name {
		char first[FIRST_NAME_LEN+1];
		char middle_initial;
		char last[LAST_NAME_LEN+1];
	};

	struct student {
		struct person_name name;
		int age;
		char sex;
	} student1, student2;

	// use . twice to access the element of struct in struct.
	strcpy(student1.name.first, "Fred");
```
### 16.3.2 struct array

array made of struct can be used as simple dataset:
```c
	// 100-elements array with struct part element
	struct part inventory[100];

	// use index to access the element in array
	print_part(inventory[1]);

	// access member of struct in array
	inventory[1].number = 883;
	inventory[1].name[0] = '\0';
```

### 16.3.3 initiate struct array

the method to intiate struct array is similar to initiate multi-dimesional array:
```c
	struct dialing_code {
		char *country;
		int code;
	};

	const struct dialing_code country_codes[] = {
		{"Argentina",	54}, {"Bangladesh",		880}
	};
```

## 16.4 union

union is also made of members with possible different type member, but compiler will only allocate memory for the maxium member in union. members in union will cover each other.

```c
	union {
		int i;
		double d;
	} u;
```

### 16.4.1 union can save memory

union is often used in struct to save memory. For example, there three type of items in catalog: book, cup, and shift. We will record each item's information, but they are not the same:
```c
	struct catalog_item {
		int stock_number;
		double price;
		int item_type;
		union {
			struct {
				char title[TITLE_LEN+1];
				char author[AUTHOR_LEN+1];
				int num_pages;
			} book;
			struct {
				char design[DESIGN_LEN+1];
			} mug;
			struct {
				char design[DESIGN_LEN+1];
				int colors;
				int sizes;
			} shirt;
		} item;
	};
```
### 16.4.2 union can make mixed data type

union can make data structure consisted of mixed data type. If we need store integer and double in one array, we can create union like:
```c
	typedef union {
		int i; 
		double d;
	} Number;

	// create array that Number type:
	Number number_array[1000];

	//store mixed integer and double in array
	number_array[0].i = 5;
	number_array[1].d = 8.395;
```

### 16.4.3 add tag for union

The main problem to union is: can't determine the last-changed member:
```c
	void print_number(Number n) {
		if (n contains integer)
			printf("%d", n.i);
		else
			printf("%g", n.d);
	} 
```
but there is no way to find wheter n contains integer or float.

To record this information, one can embed union into struct with additional member: tag
```c
	#define INT_KIND 0
	#define DOUBLE_KIND 1

	typedef struct {
		int kind;
		union {
			int i;
			double d;
		} u;
	} Number;

	// now Number has two member: kind and u.
	// every time assign u's member, we should assign kind 
	n.kind = INT_KIND;
	n.u.i = 82;
```

## 16.5 enumeration

sometimes we store less meaningful value into some variable, like boolean (true or false), week (Monday, Tuesday, ...). That's when we need enumeration.
```c
	/* not good enough: one cannot acknowledge that
	 * there are only 4 possible value 
	 */
	int s; /* s will store a suit */
	s = 2; /* 2 represents "hearts" */

	/* improved: but it will be verbose to macro 
	 * a larger mount of value.
	 */
	#define SUIT int
	#define CLUBS 0
	#define DIAMONDS 1
	#define HEARTS 2
	#define SPADES 3

	// enumeration
	enum {CLUES, DIAMONDS, HEARTS, SPADES} s1, s2;
```
declare enum variable is similar to struct and union, but the name of enum variable must be different from other identifier in its domain.

### 16.5.1 enum tag and type name

we can create enum name just like struct and union:
```c
	enum suit {CLUES, DIAMONDS, HEARTS, SPADES};
	typedef enum {CLUES, DIAMONDS, HEARTS, SPADES} Suit;
```

C will view enum variable as int variable. By default, C will assign 0, 1, 2, 3,... to the constant in enum: in suit, CLUES, DIAMONDS, HEARTS, SPADES represents 0, 1, 2, 3 seperately

we can also change the default value:
```c
	enum suit {CLUES = 1, DIAMONDS = 2, HEARTS = 3, SPADES};

	// SPADES will be HEARTS + 1 because it is not assigned any value.
```

### 16.5.3 use enum to declare tag for union

enum is suitable for 16.4, to determine the last-changed member:
```c
	typedef struct {
		enum {INT_KIND, DOUBLE_KIND} kind;
		union {
			int i;
			double d;
		} u;
	} Number;
