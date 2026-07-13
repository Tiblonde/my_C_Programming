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

