#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// A 1095 Cars on Campus
const int maxn = 10010, maxk = 80010;
map<string, int> getid;
map<int, string> getstr;
struct Record{
  int id, time, status, paired = 0;
}record[maxn];
struct Car{
  int id, intime = -1, totaltime = 0;
}car[maxn];
bool cmp0(Record a, Record b){
  return (a.id == b.id)? a.time < b.time : a.id < b.id;
}
bool cmp1(Record a, Record b){ return a.time < b.time; }
bool cmp2(Car a, Car b){
  return (a.totaltime == b.totaltime) ? getstr[a.id] < getstr[b.id] : a.totaltime > b.totaltime;
}
int main(){
  int n, k, cnt = 1;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++){
    string id, inout;
    int hh, mm, ss;
    cin >> id;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    cin >> inout;
    if(getid.find(id) == getid.end()){
      getid[id] = cnt;
      car[cnt].id = cnt;
      getstr[cnt++] = id;
    }
    record[i].id = getid[id];
    record[i].time = hh * 3600 + mm * 60 + ss;
    record[i].status = inout == "in" ? 1 : -1;
  }
  sort(record, record + n, cmp0);
  for(int i = 0; i + 1 < n; i++){
    if(record[i].id == record[i + 1].id && record[i].status == 1 && record[i + 1].status == -1){
      record[i].paired = record[i+1].paired = 1;
    }
  }
  sort(record, record + n, cmp1);
  int incampus = 0, maxtime = -1;
  int dp[24*3600 + 1] = {0}, j = 0;
  for(int i = 0; i < n; i++){
    if(record[i].paired == 0) continue;
    int temp = record[i].id;
    if(record[i].status == 1){
      fill(dp + j, dp + record[i].time, incampus);
      car[temp].intime = j = record[i].time;
      incampus++;
    }else if(record[i].status == -1 && car[temp].intime != -1){
      car[temp].totaltime += (record[i].time - car[temp].intime);
      maxtime = max(car[temp].totaltime, maxtime);
      car[temp].intime = -1;
      fill(dp + j, dp + record[i].time, incampus);
      j = record[i].time;
      incampus--;
    }
  }
  fill(dp + j, dp + 24*3600, incampus);
  for(int i = 0; i < k; i++){
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    printf("%d\n", dp[hh*3600 + mm * 60 + ss]);
  }
  sort(car + 1, car + cnt, cmp2);
  for(int i = 1; i < cnt && car[i].totaltime >= maxtime; i++){
    if(car[i].totaltime == maxtime) cout << getstr[car[i].id] << " ";
  }
  printf("%02d:%02d:%02d\n", maxtime / 3600, maxtime / 60 % 60, maxtime % 60);
  return 0;
}
