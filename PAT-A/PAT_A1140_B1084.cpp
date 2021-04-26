#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
//A1140_B1084 Look-and-say Sequence 外观数列
int main() {
  int n, k;
  queue<int> q;
  cin >> k >> n;
  q.push(k);
  for(int i = 0; i < n - 1; i++){
    int len = q.size();
    while(len > 0){
      int cnt = 0, front = q.front();
      while(len > 0 && q.front() == front){
        cnt++;
        len--;
        // printf("i:%d q.front:%d cnt:%d len:%d\n", i, q.front(), cnt, len);
        q.pop();
      }
      q.push(front);
      q.push(cnt);
    }
  }
  while(!q.empty()){
    printf("%d", q.front());
    q.pop();
  }
  return 0;
}
