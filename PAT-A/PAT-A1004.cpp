// 树根节点 01，数树的每一层有多少个叶结点。
// 用邻接表存储这个树。
// 层次遍历树， 每一层对叶节点累加计数，并输出结果。
// 从根结点开始，遍历每一个结点时，如果其没有孩子，记录该层人数，否则将其所有孩子加入队列。然后每次从队列中取出下一个结点进行判断。用一个计数值判断该层是否结束。
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  vector<int> adj[100], ans;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    int id1, id2, k;
    scanf("%d %d", &id1, &k);
    while(k--){
      scanf("%d", &id2);
      adj[id1].push_back(id2);
    }
  }
  queue<int> q;
  q.push(01);
  int cnt = 1, d = 0;
  while(!q.empty()){
    int t = q.front();
    q.pop();
    cnt--;
    if(adj[t].size() == 0) d++;
    else{
      for(int i = 0; i < adj[t].size(); i++) q.push(adj[t][i]);
    }
    if(cnt == 0){
      ans.push_back(d);
      cnt = q.size();
      d = 0;
    }
  }
  for(int i = 0; i < ans.size(); i++){
    if(i != 0) printf(" ");
    printf("%d", ans[i]);
  }
  return 0;
}
// DFS
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <vector>
// using namespace std;
// //A1004 Counting Leaves
// int n, m, id, num, k, layer[100] = {0};
// int maxdepth = 0;
// vector<int> tree[110];
// void dfs(int index, int depth){
//   if(tree[index].size() == 0){
//     if(depth > maxdepth) maxdepth = depth;
//     layer[depth]++;
//     return;
//   }else{
//     for(int i = 0; i < tree[index].size(); i++){
//       dfs(tree[index][i], depth + 1);
//     }
//   }
// }
// int main() {
//   scanf("%d%d", &n, &m);
//   for(int i = 0; i < m; i++){
//     scanf("%d%d", &id, &num);
//     for(int j = 0; j < num; j++){
//       scanf("%d", &k);
//       tree[id].push_back(k);
//     }
//   }
//   dfs(1, 0);
//   for(int i = 0; i <= maxdepth; i++){
//     if(i!=0) printf(" ");
//     printf("%d", layer[i]);
//   }
//   return 0;
// }
