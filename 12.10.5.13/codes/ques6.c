#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dot_product(int* a, double* u) {
  double result = 0.0;
  for(int i=0; i<3; i++) {
    result += (double)a[i] * u[i];
  }
  return result;
}

double find_magnitude(int* x) {
  double result = 0.0;
  for(int i=0; i<3; i++) {
    result += pow((double)x[i], 2.0);
  }
  return sqrt(result);
}

void add_vectors(int* b, int* c, int* result) {
  for(int i=0; i<3; i++) {
    result[i] = b[i] + c[i];
  }
}

int main() {
  int a[3] = {1, 1, 1};
  int b[3] = {2, 4, -5};
  int c[3] = {1, 2, 3};
  int x[3];
  double magnitude;
  double u[3];
  double result;
  
  add_vectors(b, c, x);
  magnitude = find_magnitude(x);
  for(int i=0; i<3; i++) {
    u[i] = (double)x[i] / magnitude;
  }
  result = dot_product(a, u);
  
  printf("result = %lf\n", result);
  
  return 0;
}
