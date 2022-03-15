# Decoder

## Task

Please write code for the `Decode` class to extend the abstract class `DecoderInterface`. The task of the `Decode` class is to decode the data that will be passed to it over a certain one serial communication protocol (a similar protocol is used for infrared communication between the remote control and e.g. a TV set). They are only three methods to be implemented.

The idea behind the protocol is as follows:

* X0 - encodes 0
* XX0 - codes for 1
* XXX0 - encodes 2
* XXXX0 - encodes 3

X's are ones and it's not specified how many ones define X.

Note that the successive repetitions of 0 or 1 themselves do not code anything. The moment of ending ones is important and zero appears at the input.

Input data is passed using integers. The output is a string.

Examples:

```plain
000010000110010111010 -> 01020 (X is 1)
```

```plain
11011110000000011011111100110 -> 01020 (X is 11)
```
---

## Solution

Please deliver the class code named `Decode` extending the `DecoderInterface` class.
