#include <cstdio>
int main(){
  int team[1005] = {0}, N, max_score = -1, max_id;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int id, x, score;
    scanf("%d-%d %d", &id, &x, &score);
    team[id] += score;
    if(team[id] > max_score){
      max_score = team[id];
      max_id = id;
    }
  }
  printf("%d %d\n", max_id, max_score);
  return 0;
}
