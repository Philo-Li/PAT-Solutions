#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
//A1013 Battle Over Cities
int n, m, k, a, b, cnt = 0, ans = 0;
bool visit[1011];
vector<int> adj[1011];
void dfs(int j){
  if(j == a) return;
  visit[j] = true;
  for(int i = 0; i < adj[j].size(); i++){
    if(!visit[adj[j][i]]) dfs(adj[j][i]);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 0; i < k; i++){
    scanf("%d", &a);
    ans = 0;
    memset(visit, false, sizeof(visit));
    for(int j = 1; j <= n; j++){
      if(!visit[j] && j != a){
        dfs(j);
        ans++;
      }
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}
