# Numerical Methods

Computer tasks from classes.

## NUM 1 - Error of approximation of the derivative of a function

Write a program to approximate the derivative from the formulas:

<!-- $$ a) D_h f(x) \equiv \frac{f(x+h) - f(x)}{h} $$ -->
<!-- $$ b) D_h f(x) \equiv \frac{f(x+h) - f(x-h)}{2h} $$ -->
![Math input](/Numerical%20Methods/Math/1.png)

Analyze how the error

<!-- $$ |D_h f(x) - f'(x)| $$ -->
![Math input](/Numerical%20Methods/Math/2.png)

behaves for the function f(x) = cos(x) and the point x = 0.3 at changing the h parameter for various floating point types (float & double). Plot

<!-- $$ |D_h f(x) − f'(x)| $$ -->
![Math input](/Numerical%20Methods/Math/2.png)

as a function of h on a logarithmic scale.

---

## NUM 2 - Matrices

There are matrixes:

<!-- $$
A_1 =
\begin{pmatrix}
2.40827208 & -0.36066254 & 0.80575445 & 0.46309511 & 1.20708553 \\
-0.36066254 & 1.14839502 & 0.02576113 & 0.02672584 & -1.03949556 \\
0.80575445 & 0.02576113 & 2.45964907 & 0.13824088 & 0.0472749 \\
0.46309511 & 0.02672584 & 0.13824088 & 2.05614464 & -0.9434493 \\
1.20708553 & -1.03949556 & 0.0472749 & -0.9434493 & 1.92753926
\end{pmatrix}
$$

and

$$
A_2 =
\begin{pmatrix}
2.61370745 & -0.6334453 & 0.76061329 & 0.24938964 & 0.82783473 \\
-0.6334453 & 1.51060349 & 0.08570081 & 0.31048984 & -0.53591589 \\
0.76061329 & 0.08570081 & 2.46956812 & 0.18519926 & 0.13060923 \\
0.24938964 & 0.31048984 & 0.18519926 & 2.27845311 & -0.54893124 \\
0.82783473 & -0.53591589 & 0.13060923 & -0.54893124 & 2.6276678
\end{pmatrix}
$$ -->
![Math input](/Numerical%20Methods/Math/3.png)

Let's define the vectors

<!-- $$ b \equiv
\begin{pmatrix}
5.40780228 & 3.67008677 & 3.12306266 & -1.11187948 & 0.54437218
\end{pmatrix}
^T
$$ -->
![Math input](/Numerical%20Methods/Math/4.png)

and

<!-- $$ b' \equiv
\begin{pmatrix}
10^{-5} & 0 & 0 & 0 & 0
\end{pmatrix}
^T
$$ -->
![Math input](/Numerical%20Methods/Math/5.png)

Using the computer algebra package or numeric library of your choice, solve the equations

<!-- $$ A_iy_i \equiv b $$ -->
![Math input](/Numerical%20Methods/Math/6.png)

and

<!-- $$ A_iy'_i \equiv b' $$ -->
![Math input](/Numerical%20Methods/Math/7.png)

for i = 1.2.

Find

<!-- $$ \Delta_{i} \equiv || y_i − y′_i ||_2 $$ -->
![Math input](/Numerical%20Methods/Math/8.png)

and interpret the value difference of them.

---

## NUM 3 - Matrices II

Find

<!-- $$ y = A ^{−1}x $$ -->
![Math input](/Numerical%20Methods/Math/9.png)

for

<!-- $$
A =
\begin{pmatrix}
1.2 & \frac{0.1}{1} & \frac{0.4}{1^2} \\
0.2 & 1.2 & \frac{0.1}{2} & \frac{0.4}{2^2} \\
& 0.2 & 1.2 & \frac{0.1}{3} & \frac{0.4}{3^2} \\
... & ... & ... & ... & ... & ... & ... & ... & ... \\
& & & & & 0.2 & 1.2 & \frac{0.1}{N-2} & \frac{0.4}{(N-2)^2} \\
& & & & & & 0.2 & 1.2 & \frac{0.1}{N-1} \\
& & & & & & & 0.2 & 1.2
\end{pmatrix}
$$ -->
![Math input](/Numerical%20Methods/Math/10.png)

and

<!-- $$ x = (1, 2, ..., N)^T $$ -->
![Math input](/Numerical%20Methods/Math/11.png)

We set N = 100. Also calculate the determinant of the matrix A. Problem solve the right method and use the matrix structure. Please program the algorithm yourself - do not use biblical procedures linear algebra or computational algebra packets (unless to check your solutions, which is always welcome).

---

## NUM 4 - Sherman-Morrison formula

Solve the matrix equation

<!-- $$ A_y = b $$ -->
![Math input](/Numerical%20Methods/Math/12.png)

for

<!-- $$
A =
\begin{pmatrix}
10 & 8 & 1 & 1 & ... & 1 & 1 & 1 & 1 \\
1 & 10 & 8 & 1 & ... & 1 & 1 & 1 & 1 \\
1 & 1 & 10 & 8 & ... & 1 & 1 & 1 & 1 \\
... & ... & ... & ... & ... & ... & ... & ... & ... \\
1 & 1 & 1 & 1 & ... & 1 & 10 & 8 & 1 \\
1 & 1 & 1 & 1 & ... & 1 & 1 & 10 & 8 \\
1 & 1 & 1 & 1 & ... & 1 & 1 & 1 & 10 \\
\end{pmatrix}
$$ -->
![Math input](/Numerical%20Methods/Math/13.png)

and

<!-- $$ b ≡ (5,., 5)^T $$ -->
![Math input](/Numerical%20Methods/Math/14.png)

Matrix A has the numbers 10 on the diagonal, 8 in the first position above the diagonal, a the remaining elements are equal to 1. The dimension of the matrix is set to N = 50. The appropriate algorithm, similarly as for the NUM3 task, you should implement it yourself.
