#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
//A1111 Online Map
const int maxn = 505, INF = 0x3FFFFFFF;
struct Node{
  int v, dis, cost;
}node;
vector<Node> Adj[maxn];
vector<int> pred(maxn), prec(maxn);
int n, m, st, ed, d[maxn], c[maxn], pass[maxn];
void Dijkstra(int st, int tag){
  bool vis[maxn] = {false};
  fill(d, d + maxn, INF);
  fill(c, c + maxn, INF);
  fill(pass, pass + maxn, INF);
  d[st] = 0; c[st] = 0; pass[st] = 0;
  for(int i = 0; i < n; i++){
    int u = -1, MIN = INF;
    for(int j = 0; j < n; j++){
      if(vis[j] == false){
        if(tag == 0 && d[j] < MIN){
          u = j;
          MIN = d[j];
        }else if(tag == 1 && c[j] < MIN){
          u = j;
          MIN = c[j];
        }
      }
    }
    if(u == -1) return;
    vis[u] = true;
    for(int j = 0; j < Adj[u].size(); j++){
      int v = Adj[u][j].v;
      if(vis[v] == false){
        if(tag == 0){
          if(d[v] > d[u] + Adj[u][j].dis){
            d[v] = d[u] + Adj[u][j].dis;
            c[v] = c[u] + Adj[u][j].cost;
            pred[v] = u;
          }else if(d[v] == d[u] + Adj[u][j].dis && c[v] > c[u] + Adj[u][j].cost){
            c[v] = c[u] + Adj[u][j].cost;
            pred[v] = u;
          }
        }else if(tag == 1){
          if(c[v] > c[u] + Adj[u][j].cost){
            c[v] = c[u] + Adj[u][j].cost;
            pass[v] = pass[u] + 1;
            prec[v] = u;
          }else if(c[v] == c[u] + Adj[u][j].cost && pass[v] > pass[u] + 1){
            pass[v] = pass[u] + 1;
            prec[v] = u;
          }
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    int v1, v2, tag, dis, cost;
    scanf("%d%d%d%d%d", &v1, &v2, &tag, &dis, &cost);
    node= {v2, dis, cost};
    Adj[v1].push_back(node);
    if(tag == 0){
      node = {v1, dis, cost};
      Adj[v2].push_back(node);
    }
  }
  scanf("%d%d", &st, &ed);
  Dijkstra(st, 0);
  vector<int> ans1, ans2;
  int v = ed, MinLen = d[ed], MinLenc = c[ed];
  while(v != st){
    ans1.push_back(v);
    v = pred[v];
  }
  Dijkstra(st, 1);
  v = ed;
  int MinCost = c[ed];
  while(v != st){
    ans2.push_back(v);
    v = prec[v];
  }
  if(ans1 == ans2){
    printf("Distance = %d; Time = %d: %d", MinLen, MinLenc, st);
  }else{
    printf("Distance = %d: %d", MinLen, st);
    for(int i = ans1.size() - 1; i >= 0; i--){
      printf(" -> %d", ans1[i]);
    }
    printf("\nTime = %d: %d", MinCost, st);
  }
  for(int i = ans2.size() - 1; i >= 0; i--){
    printf(" -> %d", ans2[i]);
  }
  return 0;
}
