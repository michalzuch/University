#include <stdlib.h>
#include <math.h>

double Det(double **a, int n) {
    int i, j, j1, j2;
    double det = 0;
    double **m = NULL;

    if (n < 1) { /* Error */

    } else if (n == 1) { /* Shouldn't get used */
        det = a[0][0];
    } else if (n == 2) {
        det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    } else {
        det = 0;
        for (j1 = 0; j1 < n; j1++) {
            m = (double **) malloc((n - 1) * sizeof(double *));
            for (i = 0; i < n - 1; i++)
                m[i] = (double *) malloc((n - 1) * sizeof(double));
            for (i = 1; i < n; i++) {
                j2 = 0;
                for (j = 0; j < n; j++) {
                    if (j == j1)
                        continue;
                    m[i - 1][j2] = a[i][j];
                    j2++;
                }
            }
            det += pow(-1.0, 1.0 + j1 + 1.0) * a[0][j1] * Det(m, n - 1);
            for (i = 0; i < n - 1; i++)
                free(m[i]);
            free(m);
        }
    }
    return (det);
}

double det4(double a[][4]) {
    double **p = (double **) malloc(4 * sizeof(double *));

    int i, j;

    for (i = 0; i < 4; i++)
        p[i] = (double *) malloc(4 * sizeof(double));

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            p[i][j] = a[i][j];

    return Det(p, 4);
}

int sol4(double a[][4], double b[], double x[], double d[]) {
    double w = det4(a);

    double temp[4][4];

    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 4; i++)
        temp[i][0] = b[i];

    double wx = det4(temp);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 4; i++)
        temp[i][1] = b[i];

    double wy = det4(temp);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 4; i++)
        temp[i][2] = b[i];

    double wz = det4(temp);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 4; i++)
        temp[i][3] = b[i];

    double wu = det4(temp);

    if (w != 0.0) {
        x[0] = wx / w;
        x[1] = wy / w;
        x[2] = wz / w;
        x[3] = wu / w;
        return 1;
    }
    return 0;
}

void checking4(double a[][4], const double b[], const double x[], double d[], double r[]) {
    r[0] = a[0][0] * x[0] + a[0][1] * x[1] + a[0][2] * x[2] + a[0][3] * x[3] - b[0];
    r[1] = a[1][0] * x[0] + a[1][1] * x[1] + a[1][2] * x[2] + a[1][3] * x[3] - b[1];
    r[2] = a[2][0] * x[0] + a[2][1] * x[1] + a[2][2] * x[2] + a[2][3] * x[3] - b[2];
    r[3] = a[3][0] * x[0] + a[3][1] * x[1] + a[3][2] * x[2] + a[3][3] * x[3] - b[3];
}
