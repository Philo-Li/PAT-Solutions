#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//A1017 Queueing at Bank
const int maxn = 10010, open = 8 * 3600, close = 17 * 3600, INF = 0x7FFFFFFF;
int n, k, cnt = 0;
struct costomer{
  int at, pt;
}C[maxn];
bool cmp(costomer a, costomer b){ return a.at < b.at;}
int main(){
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    int hh, mm, ss, at, pt;
    scanf("%d:%d:%d %d", &hh, &mm, &ss, &pt);
    at = hh * 3600 + mm * 60 + ss;
    if(at > close) continue;
    pt = (pt > 60 ? 3600 : pt * 60);
    C[cnt].at = at;
    C[cnt++].pt = pt;
  }
  sort(C, C + cnt, cmp);
  int sum = 0, endTime[k];
  fill(endTime, endTime + k, open);
  for(int i = 0; i < cnt; i++){
    int idx = -1, minEndTime = INF;
    for(int j = 0; j < k; j++){
      if(endTime[j] < minEndTime){
        minEndTime = endTime[j];
        idx = j;
      }
    }
    if(endTime[idx] <= C[i].at){
      endTime[idx] = C[i].at + C[i].pt;
    }else{
      sum = sum + endTime[idx] - C[i].at;
      endTime[idx] += C[i].pt;
    }
  }
  if(cnt == 0) printf("0.0\n");
  else printf("%.1f\n", sum / 60.0 / cnt);
  return 0;
}
