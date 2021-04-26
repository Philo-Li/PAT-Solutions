#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//A1030 Travel Plan
//Dijkstra
const int maxn = 505, INF = 0x7FFFFFFF;
int n, m, s, d;
int G[maxn][maxn], cost[maxn][maxn], dis[maxn], c[maxn];
bool vis[maxn] = {false};
vector<int> pre;
void Dijkstra(int st){
  fill(dis, dis + maxn, INF);
  fill(c, c + maxn, INF);
  dis[st] = 0; c[st] = 0;
  for(int i = 0; i < n; i++){
    int u = -1, MIN = INF;
    for(int j = 0; j < n; j++){
      if(vis[j] == false && MIN > dis[j]){
        u = j;
        MIN = dis[j];
      }
    }
    if(u == -1) return;
    vis[u] = true;
    for(int v = 0; v < n; v++){
      if(vis[v] == false && G[u][v] != INF){
        if(dis[v] > dis[u] + G[u][v]){
          dis[v] = dis[u] + G[u][v];
          c[v] = c[u] + cost[u][v];
          pre[v] = u;
        }else if(dis[v] == dis[u] + G[u][v] && c[v] > c[u] + cost[u][v]){
          c[v] = c[u] + cost[u][v];
          pre[v] = u;
        }
      }
    }
  }
}
void DFS(int v){
  if(v == s){
    printf("%d", v);
    return;
  }
  DFS(pre[v]);
  printf("%d ", v);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &d);
  fill(G[0], G[0] + maxn * maxn, INF);
  for(int i = 0; i < m; i++){
    int c1, c2, d, m;
    scanf("%d%d%d%d", &c1, &c2, &d, &m);
    G[c1][c2] = G[c2][c1] = d;
    cost[c1][c2] = cost[c2][c1] = m;
  }
  Dijkstra(s);
  DFS(d);
  printf("%d %d\n", dis[d], c[d]);
  return 0;
}
//Dijkstra + DFS
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cmath>
// #include <vector>
// #include <algorithm>
// using namespace std;
// //A1030 Travel Plan
// const int maxn = 505, INF = 0x7FFFFFFF;
// int n, m, s, d, mincost = INF;
// int G[maxn][maxn], cost[maxn][maxn], dis[maxn];
// bool vis[maxn] = {false};
// vector<int> pre[maxn], ans, temppath;
// void Dijkstra(int st){
//   fill(dis, dis + maxn, INF);
//   dis[st] = 0;
//   for(int i = 0; i < n; i++){
//     int u = -1, MIN = INF;
//     for(int j = 0; j < n; j++){
//       if(vis[j] == false && MIN > dis[j]){
//         u = j;
//         MIN = dis[j];
//       }
//     }
//     if(u == -1) return;
//     vis[u] = true;
//     for(int v = 0; v < n; v++){
//       if(vis[v] == false && G[u][v] != INF){
//         if(dis[v] > dis[u] + G[u][v]){
//           dis[v] = dis[u] + G[u][v];
//           pre[v].clear();
//           pre[v].push_back(u);
//         }else if(dis[v] == dis[u] + G[u][v]){
//           pre[v].push_back(u);
//         }
//       }
//     }
//   }
// }
// void DFS(int v){
//   if(v == s){
//     temppath.push_back(v);
//     int value = 0;
//     for(int i = temppath.size() - 1; i > 0; i--){
//       int id1 = temppath[i], id2 = temppath[i-1];
//       value = value + cost[id1][id2];
//     }
//     temppath.pop_back();
//     if(value < mincost){
//       mincost = value;
//       ans = temppath;
//     }
//     return;
//   }
//   temppath.push_back(v);
//   for(int i = 0; i < pre[v].size(); i++){
//     DFS(pre[v][i]);
//   }
//   temppath.pop_back();
// }
// int main() {
//   scanf("%d%d%d%d", &n, &m, &s, &d);
//   fill(G[0], G[0] + maxn * maxn, INF);
//   for(int i = 0; i < m; i++){
//     int c1, c2, d, m;
//     scanf("%d%d%d%d", &c1, &c2, &d, &m);
//     G[c1][c2] = G[c2][c1] = d;
//     cost[c1][c2] = cost[c2][c1] = m;
//   }
//   Dijkstra(s);
//   DFS(d);
//   printf("%d", s);
//   for(int i = ans.size() - 1; i >= 0; i--){
//     printf(" %d", ans[i]);
//   }
//   printf(" %d %d\n", dis[d], mincost);
//   return 0;
// }
