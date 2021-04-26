#include <cstdio>
int main(){
  int N, max_id = 0, max_score = 0, score[100010] = {0};
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int id, s;
    scanf("%d %d", &id, &s);
    score[id] += s;
    if(max_score < score[id]){
      max_score = score[id];
      max_id = id;
    }
  }
  printf("%d %d\n", max_id, max_score);
  return 0;
}
