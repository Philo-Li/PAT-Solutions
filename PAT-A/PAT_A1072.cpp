#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//A1072 Gas Station
const int maxn = 1020, INF = 0x7FFFFFFF;
int n, m, k, d, minDis = -1;
int dis[maxn], G[maxn][maxn], ans = -1;
bool vis[maxn] = {false};
void Dijkstra(int v){
  fill(dis, dis + maxn, INF);
  dis[v] = 0;
  for(int i = 1; i <= n + m; i++){
    int u = -1, MIN = INF;
    for(int j = 1; j <= n + m; j++){
      if(vis[j] == false && MIN > dis[j]){
        u = j;
        MIN = dis[j];
      }
    }
    if(u == -1) return;
    vis[u] = true;
    for(int v = 1; v <= n + m; v++){
      if(vis[v] == false && G[u][v] != INF){
        if(dis[v] > dis[u] + G[u][v]){
          dis[v] = dis[u] + G[u][v];
        }
      }
    }
  }
}
int change(string a){
  int id;
  if(a[0] == 'G'){
    a.erase(a.begin());
    id = n + stoi(a);
  }else{
    id = stoi(a);
  }
  return id;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &d);
  fill(G[0], G[0] + maxn * maxn, INF);
  for(int i = 0; i < k; i++){
    string p1, p2;
    int s1, s2, dis;
    cin >> p1 >> p2 >> dis;
    s1 = change(p1);
    s2 = change(p2);
    G[s1][s2] = G[s2][s1] = dis;
  }
  double sum = 0.0, minsum = INF;
  for(int i = 1; i <= m; i++){
    fill(vis, vis + maxn, false);
    sum = 0.0;
    Dijkstra(i + n);
    int MIN = INF;
    for(int j = 1; j <= n; j++){
      sum += dis[j];
      if(dis[j] > d){//忘记了
        MIN = -1;
        break;
      }
      if(dis[j] < MIN) MIN = dis[j];
    }
    if(MIN == -1) continue;
    if(MIN > minDis){
      minDis = MIN;
      minsum = sum;//忘记了
      ans = i;
    } else if(MIN == minDis && sum < minsum){
      minsum = sum;
      ans = i;
    }
  }
  if(ans == -1) printf("No Solution\n");
  else{
    printf("G%d\n%.1f %.1f\n", ans, 1.0 * minDis, minsum / n);
  }
  return 0;
}
