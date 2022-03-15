# Paint

## Task instructions

You are probably familiar with some graphics programs. One of their function is to fill the space with one color. The space is usually less than full canvas because of previously painted colors.

Your task is to write a class, which method will fill the space with given color. However the canvas will only have a method to paint the pixel with the appropriate color, but will not have a method to read colors. You need to use exceptions to find out when you crossed the line.

### Moving around the canvas

We assume that being in position [col, row] you can (try to) move only to 4 adjacent positions:

```plain
[ col + 1, row ]
[ col - 1, row ]
[ col, row - 1 ]
[ col, row + 1 ]
```

### Canvas

To simplify - canvas will be rectangular.
The idea of painting over a part of it is shown in the figure below:

![Canvas example](/Java/05%20-%20Paint/Plotno.png)

The area that limits the size of the canvas and other colors is filled. Of course, you should still remember that not every pixel can be reached by moving in the way given in the task.

> NOTE: It is forbidden to scan the entire canvas - it is not allowed to download information about pixels to which, according to rules to move around the board cannot be reached.

If the `setColor` method causes the `BorderColorException` exception, the previous color has been overwritten by the new one - the previous state should be restored.

---

## Providing solution

Please provide the code for a class named `Graphics` that implements the `GraphicsInterfac` interface.
