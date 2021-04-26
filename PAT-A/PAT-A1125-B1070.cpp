#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int N, r[10010];
  scanf("%d", &N);
  for(int i = 0; i < N; i++){ scanf("%d", &r[i]); }
  sort(r, r + N);
  double ans = r[0];
  for(int i = 1; i < N; i++) ans = (ans + r[i]) / 2;
  printf("%d\n", (int)ans);
  return 0;
}
