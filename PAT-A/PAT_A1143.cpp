#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
//A1143 Lowest Common Ancestor 
int n, m, pre[10010], t;
map<int, bool> vis;
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &pre[i]);
    vis[pre[i]] = true;
  }
  for(int i = 0; i < n; i++){
    int u, v, father;
    scanf("%d %d", &u, &v);
    for(int j = 0; j < m; j++){
      father = pre[j];
      if((father >= u && father <= v) || (father >= v && father <= u)) break;
    }
    if(vis[u] == false && vis[v] == false)
      printf("ERROR: %d and %d are not found.\n", u, v);
    else if(vis[u] == false || vis[v] == false)
      printf("ERROR: %d is not found.\n", vis[u] == false ? u : v);
    else if(father == u || father == v)
      printf("%d is an ancestor of %d.\n", father, father == u ? v : u);
    else
      printf("LCA of %d and %d is %d.\n", u, v, father);
  }
  return 0;
}

// 建树超时
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// //A1143 Lowest Common Ancestor
// struct Node{
//   int v;
//   Node* lchild, *rchild;
// };
// int n, m, A[10010], t;
// vector< Node* > pathu, pathv, temp;
// void insert(Node* &node, int x){
//   if(node == NULL){
//     node = new Node;
//     node->v = x;
//     node->lchild = node->rchild = NULL;
//     return;
//   }
//   if(x < node->v) insert(node->lchild, x);
//   else insert(node->rchild, x);
// }
// void dfs(Node* node, int u, int v, int &findu, int &findv){
//   if(node == NULL) return;
//   temp.push_back(node);
//   if(findu == 0 && node->v == u){
//     findu = 1;
//     pathu = temp;
//   }
//   if(findv == 0 && node->v == v){
//     findv = 1;
//     pathv = temp;
//   }
//   if(findv == 1 && findu == 1) return;
//   dfs(node->lchild, u, v, findu, findv);
//   dfs(node->rchild, u, v, findu, findv);
//   temp.pop_back();
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   Node* root = NULL;
//   for(int i = 0; i < m; i++){
//     scanf("%d", &A[i]);
//     insert(root, A[i]);
//   }
//   for(int i = 0; i < n; i++){
//     int u, v, findu = 0, findv = 0, father = -1;
//     scanf("%d %d", &u, &v);
//     dfs(root, u, v, findu, findv);
//     if(findu == 0 && findv == 0) printf("ERROR: %d and %d are not found.\n", u, v);
//     else if(findu == 0) printf("ERROR: %d is not found.\n", u);
//     else if(findv == 0) printf("ERROR: %d is not found.\n", v);
//     else{
//       for(int j = 0; j < min(pathu.size(), pathv.size()); j++){
//         if(pathu[j]->v == pathv[j]->v) father = pathu[j]->v;
//       }
//       if(father == u) printf("%d is an ancestor of %d.\n", u, v);
//       else if(father == v) printf("%d is an ancestor of %d.\n", v, u);
//       else printf("LCA of %d and %d is %d.\n", u, v, father);
//     }
//     pathu.clear(); pathv.clear(); temp.clear();
//   }
//   return 0;
// }
