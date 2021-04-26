#include <cstdio>
#include <cmath>
int main(){
  int N;
  double a, b, max_r, r;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%lf %lf", &a, &b);
    r = a * a + b * b;
    max_r = (max_r < r) ? r : max_r;
  }
  printf("%.2lf\n", sqrt(max_r));
  return 0;
}
