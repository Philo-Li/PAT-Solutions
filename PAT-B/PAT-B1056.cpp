#include <cstdio>
int main(){
  int N, x, ans = 0;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &x);
    ans = ans + x * (N - 1) + x * 10 * (N - 1);
  }
  printf("%d\n", ans);
  return 0;
}
