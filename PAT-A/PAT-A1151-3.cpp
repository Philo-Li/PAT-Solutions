// 想尝试并查集查找，失败，1、4、5测试点没过。但是速度上来了！
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, pre[10010], in[10010];
unordered_map<int, int> pos, father;
void findA(int now, int preL, int preR, int inL, int inR){
  if(preL > preR) return;
  father[pre[preL]] = now;
  int k = inL;
  while(k < inR && pre[preL] != in[k]) k++;
  int numleft = k - inL;
  findA(pre[preL], preL + 1, preL + numleft, inL, k - 1);
  findA(pre[preL], preL + numleft + 1, preR, k + 1, inR);
  return;
}
void getpath(int x, vector<int> &path){
  int tempu = x;
  while(tempu != pre[1]){
    path.push_back(tempu);
    tempu = father[tempu];
  }
  path.push_back(father[tempu]);
  reverse(path.begin(), path.end());
}
int read(){                 //fast read-in
    int input;
    scanf("%d", &input);
    return input > 0 ? input : ~(-input)+1;
}
int main(){
  scanf("%d %d", &M, &N);
  for(int i = 1; i <= N; i++){
    int temp = read();
    pos[temp] = i;
    in[i] = temp;
  }
  for(int i = 1; i <= N; i++) pre[i] = pos[read()];
  findA(pre[1], 1, N, 1, N);
  for(int i = 0; i < M; i++){
    int U = read(), V = read(), A, k = 0;
    vector<int> pathu, pathv;
    if(!pos[U] && !pos[V]) printf("ERROR: %d and %d are not found.\n", U, V);
    else if(!pos[U] || !pos[V]) printf("ERROR: %d is not found.\n", (!pos[U]) ? U:V);
    else{
      U = pos[U], V = pos[V];
      getpath(U, pathu); getpath(V, pathv);
      // while(pathu.size() < pathv.size()) pathv.erase(pathu.begin());
      // while(pathv.size() < pathu.size()) pathu.erase(pathv.begin());
      while(k < pathu.size() && k < pathv.size() && pathu[k] == pathv[k]) A = pathu[k++];
      if(A != U && A != V) printf("LCA of %d and %d is %d.\n", in[U], in[V], in[A]);
      else printf("%d is an ancestor of %d.\n", in[A], (A == U)? in[V] : in[U]);
    }
  }
  return 0;
}
