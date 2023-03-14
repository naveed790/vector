#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void dir_vec(int* A, int* B, int* result) {
  for(int i=0; i<2; i++) {
    result[i] = B[i] - A[i];
  }
}

void norm_vec(int* A, int* B, int* result) {
  int omat[2][2] = {{0, 1}, {-1, 0}};
  int d[2];
  dir_vec(A, B, d);
  for(int i=0; i<2; i++) {
    int sum = 0;
    for(int j=0; j<2; j++) {
      sum += omat[i][j] * d[j];
    }
    result[i] = sum;
  }
}

void line_gen(int* A, int* B, int len, int dim, int* result) {
  double x_AB[dim][len];
  double lam_1[len];
  for(int i=0; i<len; i++) {
    lam_1[i] = (double)i / (double)(len-1);
  }
  for(int i=0; i<len; i++) {
    for(int j=0; j<dim; j++) {
      double temp1 = A[j] + lam_1[i]*(B[j]-A[j]);
      x_AB[j][i] = temp1;
    }
  }
  for(int i=0; i<dim; i++) {
    for(int j=0; j<len; j++) {
      result[i*len+j] = (int)x_AB[i][j];
    }
  }
}

double find_area(int* A, int* B, int* C) {
  int d[2];
  int e[2];
  dir_vec(A, B, d);
  dir_vec(A, C, e);
  double product = d[0]*e[1] - d[1]*e[0];
  double area = fabs(product) / 2.0;
  return area;
}

int main() {
  int dvec[2] = {-1, 1};
  int omat[2][2] = {{0, 1}, {-1, 0}};
  int A[3] = {1, 1, 2};
  int B[3] = {2, 3, 5};
  int C[3] = {1, 5, 5};
  int d[3];
  int e[3];
  double area;
  
  dir_vec(A, B, d);
  dir_vec(A, C, e);
  area = find_area(A, B, C);
  
  printf("d = [%d %d]\n", d[0], d[1]);
  printf("e = [%d %d]\n", e[0], e[1]);
  printf("area = %lf\n", area);
  
  return 0;
}
