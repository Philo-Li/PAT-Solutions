#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//A1018 Public Bike Management
const int maxn = 505, INF = 0x7FFFFFFF;
int cmax, n, sp, m;
int dis[maxn], weight[maxn] = {0};
int G[maxn][maxn], minNeed = INF, minRemain = INF;
vector<int> pre[maxn], ans, temppath;
bool vis[maxn] = {false};
void Dijkstra(int s){
  fill(dis, dis + maxn, INF);
  dis[s] = 0;
  for(int i = 0; i <= n; i++){
    int u = -1, MIN = INF;
    for(int j = 0; j <= n; j++){
      if(vis[j] == false && MIN > dis[j]){
        u = j;
        MIN = dis[j];
      }
    }
    if(u == -1) return;
    vis[u] = true;
    for(int j = 0; j <= n; j++){
      if(vis[j] == false && G[u][j] != INF){
        if(G[u][j] + dis[u] < dis[j]){
          pre[j].clear();
          dis[j] = dis[u] + G[u][j];
          pre[j].push_back(u);
        }else if(G[u][j] + dis[u] == dis[j]){
          pre[j].push_back(u);
        }
      }
    }
  }
}
void DFS(int now){
  if(now == 0){
    int need = 0, remain = 0;
    for(int i = temppath.size() - 1; i >= 0; i--){
      int id = temppath[i];
      if(weight[id] > 0){
        remain += weight[id];
      }else{
        if(remain > abs(weight[id])){
          remain -= abs(weight[id]);
        }else{
          need += (abs(weight[id]) - remain);
          remain = 0;
        }
      }
    }
    if(need < minNeed){
      minNeed = need;
      minRemain = remain;
      ans = temppath;
    }else if(need == minNeed && remain < minRemain){
      minRemain = remain;
      ans = temppath;
    }
    return;
  }
  temppath.push_back(now);
  for(int i = 0; i < pre[now].size(); i++){
    DFS(pre[now][i]);
  }
  temppath.pop_back();
}
int main() {
  scanf("%d%d%d%d", &cmax, &n, &sp, &m);
  fill(G[0], G[0] + maxn * maxn, INF);
  for(int i = 1; i <= n; i++){
    int w;
    scanf("%d", &w);
    weight[i] = w - cmax / 2;
  }
  for(int i = 1; i <= m; i++){
    int s1, s2, d;
    scanf("%d%d%d", &s1, &s2, &d);
    G[s1][s2] = d;
    G[s2][s1] = d;
  }
  Dijkstra(0);
  DFS(sp);
  printf("%d 0", minNeed);
  for(int i = ans.size() - 1; i >= 0; i--){
    printf("->%d", ans[i]);
  }
  printf(" %d\n", minRemain);
  return 0;
}
