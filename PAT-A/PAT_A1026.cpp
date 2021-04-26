#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
//A1026 Table Tennis
const int OPEN = 8 * 3600, CLOSE = 21 * 3600;
int n, m, k, vip_table[110] = {0};
struct costomer{
  int arrive_time, serve_time, play_time, is_vip, has_served;
};
struct table{
  int id, end_time, serve_num, is_vip;
  friend bool operator < (table a, table b){
    if(a.end_time == b.end_time) return a.id < b.id;
    else return a.end_time < b.end_time;
  }
};
set<table> Table;
vector<costomer> A;
bool cmp1(costomer a, costomer b){
  return a.arrive_time < b.arrive_time;
}
bool cmp2(costomer a, costomer b){
  return a.serve_time < b.serve_time;
}
table Serve(int j, table t, int flag){
  // printf("table:%d serve:%d vip:%d A[j].at:%d:%d ", t.id, j, A[j].is_vip, A[j].arrive_time/3600, A[j].arrive_time/60%60);
  A[j].has_served = 1;
  A[j].serve_time = max(A[j].arrive_time, t.end_time);
  // printf("serve_time:%d:%d play:%dmin\n", A[j].serve_time/3600, A[j].serve_time/60%60, A[j].play_time);
  table temp = table{t.id, A[j].serve_time + A[j].play_time * 60, t.serve_num + 1, t.is_vip};
  if(flag == 0){
    Table.erase(Table.begin());
    Table.insert(temp);
  }
  return temp;
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int hh, mm, ss, t, tag;
    scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &t, &tag);
    int at = hh * 3600 + mm * 60 + ss;
    t = t > 120 ? 120 : t;
    if(at < CLOSE) A.push_back(costomer{at, 0, t, tag, 0});
  }
  sort(A.begin(), A.end(), cmp1);
  scanf("%d %d", &m, &k);
  for(int i = 0; i < k; i++){
    int id;
    scanf("%d", &id);
    vip_table[id] = 1;
  }
  for(int i = 1; i <= m; i++){
    Table.insert(table{i, OPEN, 0, vip_table[i] == 1 ? 1 : 0});
  }
  for(int i = 0, j = 0; i < A.size();){
    auto it = Table.begin();
    int flag = 0;
    while(i < A.size() && A[i].has_served == 1) i++;
    if((*it).end_time >= CLOSE || i >= A.size()) break;
    if(A[i].is_vip == 1){
      if((*it).is_vip == 1){
        Serve(i++, *it, 0);
      }else{
        for(auto p = Table.begin(); p != Table.end(); p++){
          if((*p).end_time <= A[i].arrive_time && (*p).is_vip == 1){
            flag = 1;
            table temp = Serve(i++, *p, 1);
            j = i;
            Table.erase(p);
            Table.insert(temp);
            break;
          }
        }
        if(flag == 0) Serve(i++, *it, 0);
      }
    }else {
      if((*it).is_vip == 1){
        while(j < A.size() && A[j].is_vip == 0 || j <= i){ j++; }
        if(j < A.size() && A[j].has_served == 0 && A[j].is_vip == 1 && A[j].arrive_time <= (*it).end_time){
          Serve(j++, *it, 0);
        }else Serve(i++, *it, 0);
      }else Serve(i++, *it, 0);
    }
  }
  int ansnum[110] = {0};
  for(auto it = Table.begin(); it != Table.end(); it++){
    ansnum[(*it).id] = (*it).serve_num;
  }
  sort(A.begin(), A.end(), cmp2);
  for(int i = 0; i < A.size(); i++){
    if(A[i].has_served == 0) continue;
    int t1 = A[i].arrive_time, t2 = A[i].serve_time;
    int hh1 = t1 / 3600, mm1 = t1 / 60 % 60, ss1 = t1 % 60;
    int hh2 = t2 / 3600, mm2 = t2 / 60 % 60, ss2 = t2 % 60;
    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", hh1, mm1, ss1, hh2, mm2, ss2, (t2 - t1 + 30)/60);
  }
  for(int i = 1; i <= m; i++){
    if(i != 1) printf(" ");
    printf("%d", ansnum[i]);
  }
  return 0;
}
