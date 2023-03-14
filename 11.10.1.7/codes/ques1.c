#include <stdio.h>
#include <math.h>

void line_gen(double x[], double A[], double B[], int len) {
    double lambda;
    int i;
    double temp[2];

    for(i=0; i<len; i++) {
        lambda = (double)i / (double)(len-1);
        temp[0] = A[0] + lambda * (B[0]-A[0]);
        temp[1] = A[1] + lambda * (B[1]-A[1]);
        x[i*2] = temp[0];
        x[i*2+1] = temp[1];
    }
}

int main() {
    double x[200];
    double A[2] = {0,0};
    double theta1 = M_PI * 2 / 3;
    double slope = tan(theta1);
    double d1 = 4;
    double B[2], C[2];

    B[0] = d1 * cos(theta1);
    B[1] = d1 * sin(theta1);
    C[0] = -d1 * cos(theta1);
    C[1] = -d1 * sin(theta1);

    line_gen(x, A, B, 100);
    // Plotting x[0:99] and x[100:199] as two sets of coordinates

    line_gen(x+200, A, C, 100);
    // Plotting x[200:299] and x[300:399] as two sets of coordinates

    // Printing the coordinates of C
    printf("(%f, %f)\n", C[0], C[1]);

    return 0;
}
