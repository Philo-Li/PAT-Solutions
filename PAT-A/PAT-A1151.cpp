
// 最后两个测试点超时，DFS搜索效率太低
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int N, M, pre[10010], in[10010];
vector<int> temppath, pathu, pathv;
void getpath(int u, int v, int preL, int preR, int inL, int inR){
  if(preL > preR || (!pathu.empty() && !pathv.empty())) return;
  temppath.push_back(pre[preL]);
  if(pre[preL] == u) pathu = temppath;
  if(pre[preL] == v) pathv = temppath;
  int k = inL;
  while(k < inR && pre[preL] != in[k]) k++;
  int numleft = k - inL;
  getpath(u, v, preL + 1, preL + numleft, inL, k - 1);
  getpath(u, v, preL + numleft + 1, preR, k + 1, inR);
  temppath.pop_back();
  return;
}
int main(){
  map<int, int> vis;
  scanf("%d %d", &M, &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &in[i]);
    vis[in[i]] = 1;
  }
  for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
  for(int i = 0; i < M; i++){
    int U, V, A, k = 0;
    scanf("%d %d", &U, &V);
    if(!vis[U] && !vis[V]) printf("ERROR: %d and %d are not found.\n", U, V);
    else if(!vis[U] || !vis[V]) printf("ERROR: %d is not found.\n", (vis[U]!= 1) ? U:V);
    else{
      pathu.clear(); pathv.clear(); temppath.clear();
      getpath(U, V, 0, N - 1, 0, N - 1);
      while(k < pathu.size() && pathu[k] == pathv[k]) A = pathu[k++];
      if(A != U && A != V) printf("LCA of %d and %d is %d.\n", U, V, A);
      else printf("%d is an ancestor of %d.\n", A, (A == U)? V : U);
    }
  }
  return 0;
}

//
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;
// map<int, int> pos;
// vector<int> in, pre;
// void lca(int inl, int inr, int preRoot, int a, int b) {
//     if (inl > inr) return;
//     int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];
//     if (aIn < inRoot && bIn < inRoot)
//         lca(inl, inRoot-1, preRoot+1, a, b);
//     else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))
//         printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
//     else if (aIn > inRoot && bIn > inRoot)
//         lca(inRoot+1, inr, preRoot+1+(inRoot-inl), a, b);
//     else if (aIn == inRoot)
//             printf("%d is an ancestor of %d.\n", a, b);
//     else if (bIn == inRoot)
//             printf("%d is an ancestor of %d.\n", b, a);
// }
// int main() {
//     int m, n, a, b;
//     scanf("%d %d", &m, &n);
//     in.resize(n + 1), pre.resize(n + 1);
//     for (int i = 1; i <= n; i++) {
//         scanf("%d", &in[i]);
//         pos[in[i]] = i;
//     }
//     for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
//     for (int i = 0; i < m; i++) {
//         scanf("%d %d", &a, &b);
//         if (pos[a] == 0 && pos[b] == 0)
//             printf("ERROR: %d and %d are not found.\n", a, b);
//         else if (pos[a] == 0 || pos[b] == 0)
//             printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
//         else
//             lca(1, n, 1, a, b);
//     }
//     return 0;
// }
