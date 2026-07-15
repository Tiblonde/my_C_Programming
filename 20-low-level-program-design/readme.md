# 20 low level program design

bit-wise operation is useful in compiler, operation system, encrept, graphic, and other high-speed program.

## 20.1 bit operator

C provides 6 bit operators:

### 20.1.1 shift operator

shift operator can change the binary integer by bit-wise left shift and right shift. << and >> are compatible with any integer type of operand (even char type), it will integer conversion operand and return loperand type value.

i << j add 0 at the right and overflow at left. i >> j overflow at right, but add 0/1 at left (depend on the type of i and implement)

```c
	unsigned short i, j;
	i = 13;			/* i is 00000000_00001101 */
	j = i << 2; 	/* j is 00000000_00110100 */
	j = i >> 2;	 	/* j is 00000000_00000011 */

	// compand assign operator <<= and >>= will change operand
	i <<= 2;  		/* i is 00000000_00110100 */
	i >>= 2;  		/* i is 00000000_00001101 */
```

### 20.1.2 bit-wise not, and, xor, or

`~, &, ^, |` operator will operate bit-wisely on operand.

Notice `& and |` are different from `&& and ||` 

```c
unsigned shor i, j, k;

i = 21;
j = 56;
k = ~i;
k = i & j;
k = i ^ j;
k = i | j;
```

### 20.1.3 access bit by bit operator

bit operator provides bit control:
```c
	/* Suppose i is a unsigned short */
	/* to set its 4th bit is to bit-wise or with mask of 4th bit*/
	i = 0x0000;
	i |= 0x0010;
	i |= 1 << j; // a common usage

	/* to eliminate its 4th bit is to bit-wise and with inverted mask of 4th bit */
	i = 0x00ff;
	i &= ~0x0010;
	i &= ~(1 << j); // a common usage

	/* We can name the bits to make bit control more comprehesive */
	#define BLUE 1
	#define GREEN 2
	#define RED 4

	i |= BLUE;
	i &= ~GREEN;
```

### 20.1.4 access bit domain by bit operator

**bit domain** is a successive sery of bit, but can still be controlled by bit operator:
```c
	/* To modify bit domain, first is to bit-wise and to eliminate the domain and then bit-wise or to set the domain */
	i = i & ~0x0070 | 0x0050;	// store 101 in bits 4-6  01110000 -> 01010000
	i = i & ~0x0070 | j << 4;

	/* To access bit domain, first is to right shift and then bit-wise and to access */
	i = (i >> 4) & 0x0007; // right shift 4 to get bits 4-6
```

```
	xor.c
```

## 20.2 bit domain in struct

Although directly manipulate bit domain is available, some chaos may be introduced. So C provides alternative method: declare one struct whose members represent bit domain!

For example, DOS store the date (like the time of creating file or modifying file) in a subtle way. Since day, month, year are relatively small number, storing in int type causes waste of space. So DOS allocate 16 bits for date, 5 bits of it store day, 4 bits of it store month, and 7 bits of it store year:
```
	|	  year  	| month |  day	|
	15				8		4		0
```
we can create C struct:
```c
	struct file_date {
		unsigned int day: 5;
		unsigned int month: 4;
		unsigned int year: 7;
	};
	// each member has nember defining the length of bit domain.
```
Notice: bit domain type must be int, unsigned int, or signed int.
```c
	struct file_date fd;
	fd.day = 28;
	fd.month = 12;
	fd.year = 8; /* represent 1988 */
```
now variable fd stores date data and is more comprehensive.

Notice: bit domain doesn't have address, so we can't scanf() into that:
```c
	scanf("%d", &fd.day); /***WRONG***/
```

## 20.3 other low level technique

### 20.3.1 define machine-dependent type

We know that char type takes one byte, so we view char as byte sometimes and use it to store some non-character data. When we do this, it is practical to def BYTE type:
```c
	typedef unsigned char BYTE;
```
Moreover, in X86 architecture we also use 16-bit WORD:
```c
	typedef unsigned short WORD;
```

### 20.3.2 multiple perspectives about poviding data by union

In section 16.4 we have introduced the usage of union. But C uses it to archieve a different destination: view memory block from two or more perspectives.

Since struct file_date can be stored in just two byte, we can view any two byte as a struct file_date. For example, unsigned short is a struct file_date:
```c
	union int_date {
		unsigned short i;
		struct file_date fd;
	}
```
throught this union, we can access date in two-byte form and access day, month, year. Conversely, we can create a struct file_date and store it as two bytes into memory.
```c
	void print_date(unsigned short n) {
		union int_date u;

		u.i = n;
		printf("%d/%d/%d\n", u.fd.month, u.fd.day, u.fd.year + 1980);
	}
```

### 20.3.3 use pointer as address

in chapter 11.1 we have introduced the notion: pointer is address. In low level program, the notion is much important.

the bit number of address is equal to the bit number of integer. To create a pointer is so convenient that we can even convertion integer into address:
```c
	BYTE *p;
	p = (BYTE *) 0x1000;
```

```
	viewmemory.c
```

### 20.3.4 volatile type specifier

In some computer, some memory space are "volatile", the value stored in such space may change during the program, even the program not tend to store new value. For example, some memory space may be used to store the data directly from input device.

**volatile** type specifier tells compiler that some variable tend to store in such space:
```c
	volatile BYTE *p; 
```
