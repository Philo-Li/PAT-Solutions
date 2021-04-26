#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
//A1021 Deepest Root
int n, maxdepth = -1, blocks = 0, ss = 0;
vector<int> G[100010], temp;
set<int> ans;
bool visit[100010] = {false};
void dfs(int node, int depth){
  if(maxdepth < depth){
    maxdepth = depth;
    temp.clear();
    temp.push_back(node);
  }else if(maxdepth == depth){
    temp.push_back(node);
  }
  visit[node] = true;
  for(int i = 0; i < G[node].size(); i++){
    if(!visit[G[node][i]]) dfs(G[node][i], depth + 1);
  }
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    if(!visit[i]){
      dfs(i, 0);
      blocks++;
    }
  }
  if(blocks > 1){
    printf("Error: %d components\n", blocks);
    return 0;
  }
  if(!temp.empty()) ss = temp[0];
  for(int j = 0; j < temp.size(); j++){
    ans.insert(temp[j]);
  }
  temp.clear();
  maxdepth = -1;
  memset(visit, false, sizeof(visit));
  dfs(ss, 0);
  for(int j = 0; j < temp.size(); j++){
    ans.insert(temp[j]);
  }
  for(auto it = ans.begin(); it != ans.end(); it++){
    printf("%d\n", *it);
  }
  return 0;
}
