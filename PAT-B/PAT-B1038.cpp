#include <cstdio>
int main(){
  int N, k, x, score[101] = {0};
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &x);
    score[x]++;
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    scanf("%d", &x);
    if(i != 0) printf(" ");
    printf("%d", score[x]);
  }
  return 0;
}
