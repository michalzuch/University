# Compression

## Task instructions

The data arrives at the program. These are n-bit words. Many of them will repeat. We want to use this information to perform a lossless data compression.

### Compression technique

The idea behind compressing the data:

1. We test how many times a given sequence of bits (word) is repeated
2. Then we try to encode the data so that the most common words are encoded using less than n number of bits, and the rest are encoded using n + 1 bits.

Why do the remaining words need n + 1 bits? Because we have to use one bit to distinguish between sequences encoding frequently repeated words and a rest that does not is coded.

We agree that the coding sequences for repeating words always start at 0, and the rest at 1.

### Examples

```plain
Input:
001 001 001 010 111 011 001 001 110 000 001 001 001 001

Words statistics:
001 x9
000 x1
010 x1
011 x1
110 x1
111 x1

Coding:
Word '001' becomes '0'.
Other words become 4-bit.

Compressed sequence:
[0->001] 0 0 0 1010 1111 1011 0 0 1110 1000 0 0 0 0
```

```plain
Input:
000 001 000 001 000 001 000 001 011 001 000 110 001 000 111 001 001 000 000 000 001

Output:
[00->000 01->001] 00 01 00 01 00 01 00 01 1011 01 00 1110 01 00 1111 01 01 00 00 00 01
```

---

## Providing solution

The task is to optimally compress the transmitted bit sequence. By "optimal compression" I mean your program will check what sequences it is best to encode and select their number so that taking into account the header length and the need to add an additional bit to the uncoded sequence number of bits information needed to save will be as small as possible.

Please provide the code for a class named `Compression` that implements the `CompressonInterface` interface.
