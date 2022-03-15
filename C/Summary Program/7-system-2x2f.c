double det2(double a[0][2]) {
    return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}

int sol2(double a[][2], double b[], double x[]) {
    double w = det2(a);
    double temp[2][2];
    int i, j;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 2; i++)
        temp[i][0] = b[i];

    double wx = det2(temp);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 2; i++)
        temp[i][1] = b[i];

    double wy = det2(temp);

    if (w != 0.0) {
        x[0] = wx / w;
        x[1] = wy / w;
        return 1;
    }

    if (wx == 0.0 && wy == 0.0)
        return 999;

    return 0;
}

void checking2(double a[][2], const double b[], const double x[], double r[]) {
    r[0] = a[0][0] * x[0] + a[0][1] * x[1] - b[0];
    r[1] = a[1][0] * x[0] + a[1][1] * x[1] - b[1];
}
