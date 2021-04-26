#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1010;
struct Mooncake{
  double total_price, storage, ave_price;
}M[maxn];
bool cmp(Mooncake a, Mooncake b){ return a.ave_price > b.ave_price; }
int main(){
  int N;
  double bonus = 0.0, need, price[maxn], storage[maxn];
  scanf("%d %lf", &N, &need);
  for(int i = 0; i < N; i++) scanf("%lf", &M[i].storage);
  for(int i = 0; i < N; i++) {
    scanf("%lf", &M[i].total_price);
    M[i].ave_price = 1.0 * M[i].total_price / M[i].storage;
  }
  sort(M, M + N, cmp);
  int cnt = 0;
  while(need > 0 && cnt < N){
    int t = need > M[cnt].storage ? M[cnt].storage : need;
    bonus += M[cnt++].ave_price * t;
    need -= t;
  }
  printf("%.2f\n", bonus);
  return 0;
}
// 价格/库存都有可能不是整数；贪心算法，按照单价最高排序；
