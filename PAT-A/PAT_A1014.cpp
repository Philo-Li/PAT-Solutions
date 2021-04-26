#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//A1014 Waiting in Line
const int maxn = 10010, open = 8 * 60, close = 17 * 60, INF = 0x7FFFFFFF;
int n, m, k, q, cnt = 0;
int ans[maxn], needTime[maxn];
struct window{
  int endTime = 8 * 60, popTime = 8 * 60;
  queue<int> q;
}W[20];
int main(){
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for(int i = 0; i < k; i++){
    scanf("%d", &needTime[i]);
  }
  for(int i = 0; i < min(n * m, k); i++){
    W[cnt % n].q.push(cnt);
    W[cnt % n].endTime += needTime[cnt];
    if(cnt < n) W[cnt].popTime = needTime[cnt];
    ans[cnt] = W[cnt % n].endTime;
    cnt++;
  }
  for(; cnt < k; cnt++){
    int idx = -1, minPopTime = INF;
    for(int i = 0; i < n; i++){
      if(W[i].popTime < minPopTime){
        idx = i;
        minPopTime = W[i].popTime;
      }
    }
    W[idx].q.pop();
    W[idx].q.push(cnt);
    W[idx].endTime += needTime[cnt];
    W[idx].popTime += needTime[W[idx].q.front()];
    ans[cnt] = W[idx].endTime;
  }
  for(int i = 0; i < q; i++){
    int temp;
    scanf("%d", &temp);
    if(ans[temp - 1] - needTime[temp - 1] >= close){
      printf("Sorry\n");
    }else{
      printf("%02d:%02d\n", ans[temp - 1] / 60, ans[temp - 1] % 60);
    }
  }
  return 0;
}
