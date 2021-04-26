#include <cstdio>
#include <vector>
using namespace std;
int main(){
  int N, M, K, G[202][202] = {{0}};
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++){
    int c1, c2, d;
    scanf("%d %d %d", &c1, &c2, &d);
    G[c1][c2] = d;
    G[c2][c1] = d;
  }
  scanf("%d", &K);
  int min_id = -1, min_dis = -1;
  for(int i = 1; i <= K; i++){
    int p, vis[202] = {0}, total = 0, flag = 1;
    scanf("%d", &p);
    vector<int> path(p);
    for(int j = 0; j < p; j++){
      scanf("%d", &path[j]);
      vis[path[j]]++;
      if(j != 0) {
        if(G[path[j]][path[j-1]] == 0) flag = -1;// not a cycle
        else total += G[path[j]][path[j-1]];
      }
      if(j == p-1 && flag > 0){
        if(path[j] != path[0]) flag = -2;// not a cycle
        else vis[path[j]]--;
      }
    }
    for(int j = 1; flag > 0 && j <= N; j++){
      if(vis[j] == 0) flag = -2;// not TS cycle
      if(vis[j] > 1) flag = 2; // TS cycle
    }
    printf("Path %d: ", i);
    if(flag == 1) printf("%d (TS simple cycle)\n", total);
    else if(flag == 2) printf("%d (TS cycle)\n", total);
    else if(flag == -2) printf("%d (Not a TS cycle)\n", total);
    else if(flag == -1) printf("NA (Not a TS cycle)\n");
    if(min_dis == -1 || (flag > 0 && min_dis > total)){
      min_dis = total;
      min_id = i;
    }
  }
  printf("Shortest Dist(%d) = %d\n", min_id, min_dis);
  return 0;
}
