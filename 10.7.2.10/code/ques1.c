#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* create_1d_array(int n) {
    return (double*) calloc(n, sizeof(double));
}

double** create_2d_array(int n, int m) {
    double** array = (double**) malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        array[i] = (double*) calloc(m, sizeof(double));
    }
    return array;
}

double cross_product(double ax, double ay, double az, double bx, double by, double bz) {
    return (ax * by) - (ay * bx);
}

double bd(double* point1, double* point2, double* point3, double* point4) {
    double AD[2] = { point1[0] - point4[0], point1[1] - point4[1] };
    double BA[2] = { point2[0] - point1[0], point2[1] - point1[1] };
    double area = cross_product(AD[0], AD[1], 0.0, BA[0], BA[1], 0.0);
    return area;
}

int main() {
    double* point1 = create_1d_array(2);
    double* point2 = create_1d_array(2);
    double* point3 = create_1d_array(2);
    double* point4 = create_1d_array(2);

    point1[0] = 3.0;
    point1[1] = 0.0;
    point2[0] = 4.0;
    point2[1] = 5.0;
    point3[0] = -1.0;
    point3[1] = 4.0;
    point4[0] = -2.0;
    point4[1] = -1.0;

    double length = bd(point1, point2, point3, point4);

    printf("Area of parallelogram: %lf\n", length);

    free(point1);
    free(point2);
    free(point3);
    free(point4);

    return 0;
}
