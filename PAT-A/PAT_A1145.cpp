#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//A1145 Hashing - Average Search Time
bool isprime(int x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) return false;
  }
  return true;
}
int main() {
  int Msize, n, m;
  scanf("%d%d%d", &Msize, &n, &m);
  while(!isprime(Msize)) Msize++;
  vector<int> hashtable(Msize), notinsert;
  vector<bool> vis(Msize);
  fill(vis.begin(), vis.end(), false);
  for(int i = 0; i < n; i++){
    int temp, pos, flag = 0;
    scanf("%d", &temp);
    //平方探查的时候，用while循环就是会出问题，for就能过
    for(int j = 0; j < Msize; j++){
      pos = (temp + j * j) % Msize;
      if(vis[pos] == false){
        hashtable[pos] = temp;
        vis[pos] = true;
        flag = 1;
        break;
      }
    }
    if(flag == 0) printf("%d cannot be inserted.\n", temp);;
  }
  int step = 0;
  for(int i = 0; i < m; i++){
    int temp, pos, cnt = 0;
    scanf("%d", &temp);
    for(int j = 0; j <= Msize; j++){
      pos = (temp + j * j) % Msize;
      cnt++;
      if(vis[pos] == false || hashtable[pos] == temp) { break; }
    }
    step += cnt;
    // printf("hashtable[i]:%d cnt:%d step:%d\n", hashtable[i], cnt, step);
  }
  printf("%.1lf\n", 1.0 * step / m);
  return 0;
}
