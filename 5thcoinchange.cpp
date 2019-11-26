#include <stdio.h>
#define INF 999
#define N 3
#define A 6

void coinChange(int d[N+1], int C[A+1], int S[A+1]) {
  int i, p, min, coin;


  C[0] = 0;
  S[0] = 0;

  for(p = 1; p <= A; p++) {
    min = INF;
    for(i = 1; i <= N; i++) {
      if(d[i] <= p) {
        if(1 + C[p - d[i]] < min) {
          min = 1 + C[p - d[i]];
          coin = i;
        }
      }
    }
    C[p] = min;
    S[p] = coin;
  }
}

void coinSet(int d[N+1], int S[A+1]) {
  int a = A;
  while(a > 0) {
    printf("Use coin of denomination: %d\n", d[S[a]]);
    a = a-d[S[a]];
  }
}
/*
void display(int arr[A+1]) {
  int c;
  for(c = 0; c <= A; c++) {
    printf("%5d", arr[c]);
  }
  printf("\n");
}
*/
int main(void) {

  int d[N+1] = {0, 1, 2, 3};
  int C[A+1];
  int S[A+1];
  coinChange(d, C, S);

  printf("\nMin. no. of coins required to make change for amount %d = %d\n", A, C[A]);

  coinSet(d, S);

  return 0;
}
