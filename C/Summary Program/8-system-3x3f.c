double det3(double a[0][3]) {
    return (a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1]) -
           (a[2][0] * a[1][1] * a[0][2] + a[2][1] * a[1][2] * a[0][0] + a[2][2] * a[1][0] * a[0][1]);
}

int sol3(double a[][3], const double b[], double x[]) {
    double w = det3(a);
    double temp[3][3];
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 3; i++)
        temp[i][0] = b[i];

    double wx = det3(temp);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 3; i++)
        temp[i][1] = b[i];

    double wy = det3(temp);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 3; i++)
        temp[i][2] = b[i];

    double wz = det3(temp);

    if (w != 0.0) {
        x[0] = wx / w;
        x[1] = wy / w;
        x[2] = wz / w;
        return 1;
    }

    if (wx == 0.0 && wy == 0.0)
        return 999;

    return 0;
}

void checking3(double a[][3], double b[], double x[], double r[]) {
    r[0] = a[0][0] * x[0] + a[0][1] * x[1] + a[0][2] * x[2] - b[0];
    r[1] = a[1][0] * x[0] + a[1][1] * x[1] + a[1][2] * x[2] - b[1];
    r[2] = a[2][0] * x[0] + a[2][1] * x[1] + a[2][2] * x[2] - b[2];
}
