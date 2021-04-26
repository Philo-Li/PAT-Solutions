#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
//A1131 Subway Map
vector<vector<int>> v(10000);
int line[10000][10000], visit[10000];
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
  int cnt = -1, preLine = 0;
  for (int i = 1; i < a.size(); i++) {
      if (line[a[i-1]][a[i]] != preLine) cnt++;
      preLine = line[a[i-1]][a[i]];
  }
  return cnt;
}
void dfs(int node, int end, int cnt, int &minCnt, int &minTransfer) {
  if (node == end && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
      minCnt = cnt;
      minTransfer = transferCnt(tempPath);
      path = tempPath;
  }
  if (node == end) return;
  for (int i = 0; i < v[node].size(); i++) {
      if (visit[v[node][i]] == 0) {
          visit[v[node][i]] = 1;
          tempPath.push_back(v[node][i]);
          dfs(v[node][i], end, cnt + 1, minCnt, minTransfer);
          visit[v[node][i]] = 0;
          tempPath.pop_back();
      }
  }
}
int main() {
  int n, m, k, pre, temp, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
      scanf("%d%d", &m, &pre);
      for (int j = 1; j < m; j++) {
          scanf("%d", &temp);
          v[pre].push_back(temp);
          v[temp].push_back(pre);
          line[pre][temp] = line[temp][pre] = i + 1;
          pre = temp;
      }
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
      scanf("%d%d", &a, &b);
      int minCnt = 99999, minTransfer = 99999;
      tempPath.clear();
      tempPath.push_back(a);
      visit[a] = 1;
      dfs(a, b, 0, minCnt, minTransfer);
      visit[a] = 0;
      printf("%d\n", minCnt);
      int preLine = 0, preTransfer = a;
      for (int j = 1; j < path.size(); j++) {
          if (line[path[j-1]][path[j]] != preLine) {
              if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
              preLine = line[path[j-1]][path[j]];
              preTransfer = path[j-1];
          }
      }
      printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, b);
  }
  return 0;
}

// 老老实实写的，超时，还有一个错误
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// //A1131 Subway Map
// const int maxn = 10010, INF = 0x3FFFFFFF;
// int n, m, st, ed, path[maxn];
// vector<int> G[maxn];
// int dis[maxn], trans[maxn], line[10000][10000];
// bool sameline(int a, int b){
//   if(line[a][b] != line[a][path[a]]) return false;
//   else return true;
// }
// void Dijkstra(int s){
//   bool vis[maxn] = {false};
//   fill(dis, dis + maxn, INF);
//   fill(trans, trans + maxn, INF);
//   fill(path, path + maxn, INF);
//   path[s] = s;
//   dis[s] = 0;
//   trans[s] = 0;
//   for(int i = 1; i <= 9999; i++){
//     int u = -1, Min = INF;
//     for(int j = 1; j <= 9999; j++){
//       if(vis[j] == false && dis[j] < Min){
//         u = j;
//         Min = dis[j];
//       }
//     }
//     if(u == -1) return;
//     vis[u] = true;
//     for(int j = 0; j < G[u].size(); j++){
//       int v = G[u][j];
//       if(vis[v] == false && dis[v] > dis[u] + 1){
//         dis[v] = dis[u] + 1;
//         path[v] = u;
//         trans[v] = sameline(u, v)? trans[u]:trans[u] + 1;
//       }else if(vis[v] == false && dis[v] == dis[u] + 1){
//         if(sameline(u, v) || trans[v] < trans[u] + 1){
//           trans[v] = sameline(u, v) ? trans[u] : trans[u] + 1;
//           path[v] = u;
//         }
//       }
//     }
//   }
// }
// int main() {
//   scanf("%d", &n);
//   for(int i = 1; i <= n; i++){
//     int k, pre, now;
//     scanf("%d%d", &k, &pre);
//     for(int j = 1; j < k; j++){
//       scanf("%d", &now);
//       G[pre].push_back(now);
//       G[now].push_back(pre);
//       line[pre][now] = line[now][pre] = i;
//       pre = now;
//     }
//   }
//   scanf("%d", &m);
//   for(int i = 0; i < m; i++){
//     vector<int> anspath, ansline;
//     scanf("%d%d", &st, &ed);
//     int temp = ed;
//     Dijkstra(st);
//     printf("%d\n", dis[ed]);
//     while(temp != st){
//       anspath.push_back(temp);
//       temp = path[temp];
//     }
//     anspath.push_back(st);
//     reverse(anspath.begin(), anspath.end());
//     int pred = st, preline = line[anspath[0]][anspath[1]], nextline;
//     for(int i = 1; i < anspath.size(); i++){
//       if(i + 1 < anspath.size()) nextline = line[anspath[i]][anspath[i+1]];
//       if(preline != nextline || anspath[i] == ed){
//         printf("Take Line#%d from %04d to %04d.\n", preline, pred, anspath[i]);
//         preline = nextline; pred = anspath[i];
//       }
//     }
//   }
//   return 0;
// }
