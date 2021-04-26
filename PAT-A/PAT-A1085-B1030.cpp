#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
  int N, p, S[100010];
  scanf("%d %d", &N, &p);
  for(int i = 0; i < N; i++){
    scanf("%d", &S[i]);
  }
  sort(S, S + N);
  int cnt_max = -1;
  for(int i = 0, j = 0; i < N; i++){
    while(j < N && S[j] <= (long long )S[i] * p){
      cnt_max = max(j - i + 1, cnt_max);
      j++;
    }
  }
  printf("%d\n", cnt_max);
  return 0;
}
