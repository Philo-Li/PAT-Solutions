#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//A1126 Eulerian Path
int n, m, even = 0, odd = 0, cnt = 0;
vector<int> G[510];
bool vis[510] = {false};
void BFS(int idx){
  if(vis[idx] == false){
    vis[idx] = true;
    cnt++;
  }
  for(int i = 0; i < G[idx].size(); i++){
    if(vis[G[idx][i]] == false) BFS(G[idx][i]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    if(i != 1) printf(" ");
    printf("%d", G[i].size());
    if(G[i].size() % 2 == 0) even++;
    else odd++;
  }
  BFS(1);
  if(cnt != n || (odd != 0 && odd != 2)) printf("\nNon-Eulerian\n");
  else if(odd == 0) printf("\nEulerian\n");
  else if(odd == 2) printf("\nSemi-Eulerian\n");
  return 0;
}
