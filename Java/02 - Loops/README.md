# Loops

## Task instructions

The task is to write a program that will perform an action similar to the work of repeatedly nested for loops. The taste of this activity is that the number of levels of nesting will not be known and can be anything (read: whatever you want).

The program, knowing the number of nesting levels (and it will learn about it only at the time of execution), has to generate a list of states of all counters during the iteration.

The starting and ending states for each loop can be different. Limits are determined by calls to methods belonging to the interface. Note: we treat the values given in the limits "inclusive", i.e. it will correspond to the following loop operation:

```java
for
    for
        [...]
            for (int counter = lowerLimit; counter <= upperLimit; counter++)
                [...]
                    for
                        for
```

---

## Providing solution

Please deliver the class code named `Loops` extending the `GeneralLoops` class.
