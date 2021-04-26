#include <cstdio>
int main(){
  int N, M, score[110] = {0}, right_ans[110] = {0};
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++) scanf("%d", &score[i]);
  for(int i = 0; i < M; i++) scanf("%d", &right_ans[i]);
  for(int i = 0; i < N; i++){
    int ans = 0, t;
    for(int j = 0; j < M; j++){
      scanf("%d", &t);
      ans = ans + (t == right_ans[j]) * score[j];
    }
    printf("%d\n", ans);
  }
  return 0;
}
