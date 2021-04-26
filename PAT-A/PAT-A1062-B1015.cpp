#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct stu{
  int id, virtue, talent, sum, rank;
  stu(){}
  stu(int _id, int v, int t, int s):id(_id),virtue(v),talent(t),sum(s){}
}S[100010];
bool cmp(stu a, stu b){
  if(a.rank != b.rank) return a.rank < b.rank;
  else if(a.sum != b.sum) return a.sum > b.sum;
  else if(a.virtue != b.virtue) return a.virtue > b.virtue;
  else return a.id < b.id;
}
int main(){
  int N, L, H, M = 0;
  scanf("%d %d %d", &N, &L, &H);
  for(int i = 0; i < N; i++){
    int id, v, t;
    cin >> id >> v >> t;
    if(v >= L && t >= L){
      S[M] = stu(id, v, t, v+t);
      if(v >= H && t >= H) S[M].rank = 1;
      else if(v >= H && t < H) S[M].rank = 2;
      else if(v < H && t < H && v >= t) S[M].rank = 3;
      else S[M].rank = 4;
      M++;
    }
  }
  sort(S, S + M, cmp);
  printf("%d\n", M);
  for(int i = 0; i < M; i++){
    printf("%d %d %d\n", S[i].id, S[i].virtue, S[i].talent);
  }
  return 0;
}

// 数据量很大的时候还是用printf进行输入输出，用cout会超时
