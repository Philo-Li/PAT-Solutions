#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){ return a > b; }
int main(){
  int N, D[100010] = {0}, cnt;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &D[i]);
  }
  sort(D, D + N, cmp);
  while(cnt < N && D[cnt] > cnt + 1) cnt++;
  printf("%d\n", cnt);
  return 0;
}
