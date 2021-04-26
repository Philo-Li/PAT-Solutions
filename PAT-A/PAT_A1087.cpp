#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//A1087 All Roads Lead to Rome
const int maxn = 205, INF = 0x7FFFFFFF;
int n, k, weight[maxn], cost[maxn][maxn];
int st, ed;
int dis[maxn], num[maxn] = {0}, w[maxn] = {0}, pt[maxn] = {0}, pre[maxn];
bool vis[maxn] = {false};
map <string, int> strToInt;
map <int, string> intToStr;
void Dijkstra(int v){
  memset(vis, false, sizeof(vis));
  fill(dis, dis + maxn, INF);
  for(int i = 0; i < n; i++) pre[i] = i;
  dis[v] = 0;
  w[v] = weight[v] = 0;
  num[v] = 1;
  for(int i = 0; i < n; i++){
    int u = -1, MIN = INF;
    for(int j = 0; j < n; j++){//find happiest place
      if(vis[j] == false &&  MIN > dis[j]){
        u = j;
        MIN = dis[j];
      }
    }
    if(u == -1) return;
    vis[u] = true;
    for(int v = 0; v < n; v++){
      if(vis[v] == false && cost[u][v] != INF){
        if(dis[v] > dis[u] + cost[u][v]){
          dis[v] = dis[u] + cost[u][v];
          w[v] = w[u] + weight[v];
          num[v] = num[u];
          pt[v] = pt[u] + 1;
          pre[v] = u;
        }else if(dis[v] == dis[u] + cost[u][v]){
          num[v] += num[u];
          if(w[u] + weight[v] > w[v]){
            w[v] = w[u] + weight[v];
            pt[v] = pt[u] + 1;
            pre[v] = u;
          }else if(w[u] + weight[v] == w[v]){
            double uave = 1.0 * (w[u] + weight[v]) / (pt[u] + 1);
            double vave = 1.0 * w[v] / pt[v];
            if(uave > vave){
              pt[v] = pt[u] + 1;
              pre[v] = u;
            }
          }
        }
      }
    }
  }
}
void printpath(int v){
  if(v == 0){
    cout << intToStr[v];
    return;
  }
  printpath(pre[v]);
  cout << "->" << intToStr[v];
}
int main() {
  string s1, s2;
  int d;
  cin >> n >> k >> s1;
  intToStr[0] = s1;
  strToInt[s1] = 0;
  for(int i = 1; i < n; i++){
    cin >> s1 >> d;
    strToInt[s1] = i;
    intToStr[i] = s1;
    weight[i] = d;
  }
  fill(cost[0], cost[0] + maxn * maxn, INF);
  for(int i = 0; i < k; i++){
    cin >> s1 >> s2 >> d;
    int id1 = strToInt[s1], id2 = strToInt[s2];
    cost[id1][id2] = cost[id2][id1] = d;
  }
  ed = strToInt["ROM"];
  Dijkstra(0);
  printf("%d %d %d %d\n", num[ed], dis[ed], w[ed], w[ed]/pt[ed]);
  printpath(ed);
  return 0;
}
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <map>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// //A1087 All Roads Lead to Rome
// const int maxn = 205, INF = 0x7FFFFFFF;
// int n, k, weight[maxn], cost[maxn][maxn], maxhap = 0, maxave = 0;
// int num = 0,cnt = 1, st, ed;
// int dis[maxn];
// bool vis[maxn] = {false};
// map <string, int> strToInt;
// map <int, string> intToStr;
// vector<int> pre[maxn], ans, temppath;
// void Dijkstra(int v){
//   memset(vis, false, sizeof(vis));
//   fill(dis, dis + maxn, INF);
//   dis[v] = 0;
//   weight[v] = 0;
//   for(int i = 0; i < n; i++){
//     int u = -1, MIN = INF;
//     for(int j = 0; j < n; j++){//find happiest place
//       if(vis[j] == false &&  MIN > dis[j]){
//         u = j;
//         MIN = dis[j];
//       }
//     }
//     if(u == -1) return;
//     vis[u] = true;
//     for(int v = 0; v < n; v++){
//       if(vis[v] == false && cost[u][v] != INF){
//         if(dis[v] > dis[u] + cost[u][v]){
//           dis[v] = dis[u] + cost[u][v];
//           pre[v].clear();
//           pre[v].push_back(u);
//         }else if(dis[v] == dis[u] + cost[u][v]){
//           pre[v].push_back(u);
//         }
//       }
//     }
//   }
// }
// void DFS(int v){
//   if(v == st){
//     num++;
//     int value = 0, ave = 0;
//     temppath.push_back(v);
//     for(int i = temppath.size() - 1; i >= 0; i--){
//       int id = temppath[i];
//       value += weight[id];
//     }
//     ave = value / (temppath.size() - 1);
//     temppath.pop_back();
//     if(value > maxhap){
//       maxhap = value;
//       maxave = ave;
//       ans = temppath;
//     }else if(value == maxhap && maxave < ave){
//       maxave = ave;
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
//   string s1, s2;
//   int w, d;
//   cin >> n >> k >> s1;
//   intToStr[0] = s1;
//   strToInt[s1] = 0;
//   for(int i = 1; i < n; i++){
//     cin >> s1 >> w;
//     strToInt[s1] = i;
//     intToStr[i] = s1;
//     weight[i] = w;
//   }
//   fill(cost[0], cost[0] + maxn * maxn, INF);
//   for(int i = 0; i < k; i++){
//     cin >> s1 >> s2 >> d;
//     int id1 = strToInt[s1], id2 = strToInt[s2];
//     cost[id1][id2] = cost[id2][id1] = d;
//   }
//   ed = strToInt["ROM"];
//   Dijkstra(0);
//   DFS(ed);
//   printf("%d %d %d %d\n", num, dis[ed], maxhap, maxave);
//   cout << intToStr[st];
//   for(int i = ans.size() - 1; i >= 0; i--){
//     cout << "->" << intToStr[ans[i]];
//   }
//   return 0;
// }
