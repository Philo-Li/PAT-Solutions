#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//A1138 Postorder Traversal
int n, pre[50010], in[50010];
vector<int> ans;
void getans(int preL, int preR, int inL, int inR){
  if(preL > preR) return;
  if(preL == preR){
    ans.push_back(pre[preL]);
    return;
  }
  int k;
  for(k = inL; k <= inR; k++){
    if(pre[preL] == in[k]) break;
  }
  int numleft = k - inL;
  getans(preL + 1, preL + numleft, inL, inL + numleft);
  getans(preL + numleft + 1, preR, k + 1, inR);
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
  for(int i = 0; i < n; i++) scanf("%d", &in[i]);
  getans(0, n - 1, 0, n - 1);
  printf("%d\n", ans[0]);
  return 0;
}
