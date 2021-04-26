#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
// A1122 Hamiltonian Cycle
int n, m, q, G[300][210] = {0}, Hash[300] = {0};
set<int> num;
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    Hash[a] = 1;
    Hash[b] = 1;
    G[a][b] = G[b][a] = 1;
  }
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    int k, flag = 1, temp[300], vis[300] = {0};
    set<int> t;
    scanf("%d%d", &k, &temp[0]);
    for(int j = 1; j < k; j++){
      scanf("%d", &temp[j]);
      vis[temp[j]] = 1;
      if(G[temp[j]][temp[j - 1]] == 0) flag = 0;
    }
    if(temp[k-1] != temp[0] || k != n + 1) flag = 0;
    for(int i = 1; i <= n && flag == 1; i++){
      if(vis[i] != Hash[i]){
        flag = 0; break;
      }
    }
    printf("%s\n", flag == 1 ? "YES":"NO");
  }
  return 0;
}
