#include <cstdio>
int main() {
  int n;
  double x, ans = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%lf", &x);
    ans += x * i * (n - i + 1);
  }
  printf("%.2lf", ans);
  return 0;
}
