# Bus intersctions

## Task instructions

There are bus routes on a certain 2-dimensional plane. A single bus route consists of sections. Each segment has a start and end point. The line segment includes all points from the start point to the end point, including the end points. The end point of one section is also the starting point of the next section of the route. The coordinates of the points are integer. We agree that the section may take one of the four permitted directions:

```plain
        *       *         *
***     *        *       *
        *         *     *
```

The task is to find those points (marked "x") where two routes (marked here with A and B) intersect at right angles, that is:

```plain
   A         A   B
   A          A B
BBBXBBB        X
   A          B A
   A         B   A
```

> Note: You should also consider the scenario where at the intersection (or in its vicinity) the bus route is described e.g. with two sections (a and A are two sections of one route, b and B are sections belonging to the other route). E.g. like this:

```plain
   a         a   B
   a          a B
bbBXBBB        X
   A          b A
   A         b   A
```

We agree that the sample pictures presented below do not show the intersections we are interested in:

```plan
   1               1
    1              1
22222?2222      222?222
      1             1
       1             1
```

> NOTE: we assume that the route may have an intersection with itself.

---

## Providing solution

Please deliver the code of the class named `BusLine` that implements the `BusLineInterface` interface.
