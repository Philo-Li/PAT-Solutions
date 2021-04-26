#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
//A1003 Emergency
const int maxn = 510, INF = 0x3FFFFFFF;
int n, m, c1, c2;
struct node{
  int v, d;
  node(int _v, int _d) : v(_v), d(_d){}
};
vector<node> adj[maxn];
int dis[maxn], weight[maxn];
int w[maxn] = {0}, num[maxn] = {0};
bool vis[maxn] = {false};
void Dijkstra(int s){
  fill(dis, dis + maxn, INF);
  dis[s] = 0;
  w[s] = weight[s];
  num[s] = 1;
  for(int i = 0; i < n; i++){
    int u = -1, MIN = INF;
    for(int j = 0; j < n; j++){
      if(vis[j] == false && dis[j] < MIN){
        u = j;
        MIN = dis[j];
      }
    }
    if(u == -1) return;
    vis[u] = true;
    for(int j = 0; j < adj[u].size(); j++){
      int v = adj[u][j].v;
      if(vis[v] == false && dis[u] + adj[u][j].d < dis[v]){
        dis[v] = dis[u] + adj[u][j].d;
        w[v] = w[u] + weight[v];
        num[v] = num[u];
      }else if(vis[v] == false && dis[u] + adj[u][j].d == dis[v]){
        if(w[u] + weight[v] > w[v]){
          w[v] = w[u] + weight[v];
        }
        num[v] += num[u];
      }
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &c1, &c2);
  for(int i = 0; i < n; i++){
    scanf("%d", &weight[i]);
  }
  for(int i = 0; i < m; i++){
    int v1, v2, d;
    scanf("%d%d%d", &v1, &v2, &d);
    adj[v1].push_back(node(v2, d));
    adj[v2].push_back(node(v1, d));
  }
  Dijkstra(c1);
  printf("%d %d\n", num[c2], w[c2]);
  return 0;
}
