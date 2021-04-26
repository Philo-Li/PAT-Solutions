#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//A1146 Topological Order
vector<int> G[1010], ans;
int n, m, k, t;
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    G[b].push_back(a);
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    set<int> temp;
    bool flag = true;
    for(int j = 0; j < n; j++){
      scanf("%d", &t);
      for(int p = 0; p < G[t].size() && flag; p++){
        if(temp.find(G[t][p]) == temp.end()) flag = false;
      }
      temp.insert(t);
    }
    if(flag == false) ans.push_back(i);
  }
  for(int i = 0; i < ans.size(); i++){
    if(i != 0) printf(" ");
    printf("%d", ans[i]);
  }
  return 0;
}
