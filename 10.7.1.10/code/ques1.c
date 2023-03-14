#include <stdio.h>
#include <math.h>

double find_x(double point1[], double point2[], int n) {
    double proj = 0.0;
    double diff[n];
    
    // Calculate the vector difference between point1 and point2
    for (int i = 0; i < n; i++) {
        diff[i] = point1[i] - point2[i];
    }
    
    // Calculate the projection on the x-axis
    for (int i = 0; i < n; i++) {
        proj += (point1[i] * point1[i] - point2[i] * point2[i]) / (2 * diff[0]);
    }
    
    return proj;
}

int main() {
    double point1[2] = {2, -5};
    double point2[2] = {-2, 9};
    
    double x = find_x(point1, point2, 2);
    printf("Equidistant point on x-axis = %f\n", x);
    
    return 0;
}
