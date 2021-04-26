#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct LNode{
  int data, next;
}L[100010];
int main(){
  int head, A, N, K;
  scanf("%d %d %d", &head, &N, &K);
  for(int i = 0; i < N; i++){
    scanf("%d", &A);
    scanf("%d %d", &L[A].data, &L[A].next);
  }
  vector<int> S;
  while(head != -1){
    S.push_back(head);
    head = L[head].next;
  }
  for(int i = 0; i + K <= S.size(); i+=K){ // 逆转数组，这里不用N，因为可能包含无用节点
    reverse(S.begin() + i, S.begin() + i + K);
  }
  for(int i = 0; i + 1< S.size(); i++){
    printf("%05d %d %05d\n", S[i], L[S[i]].data, S[i+1]);
  }
  printf("%05d %d -1\n", S.back(), L[S.back()].data);
  return 0;
}

// 易错
// 可能包含无用节点
