#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;
//A1141_B1085 PAT Ranking of Institutions PAT单位排行
struct Sch{
  int stunum = 0, a = 0, b = 0, t = 0, sum;
  string id;
}sch;
map<string, int> maps;
vector<Sch> ans;
bool cmp(Sch a, Sch b){
  if(a.sum == b.sum){
    if(a.stunum == b.stunum) return a.id < b.id;
    else return a.stunum < b.stunum;
  }else return a.sum > b.sum;
}
int main() {
  int n, cnt = -1;
  cin >> n;
  for(int i = 0; i < n; i++){
    string stuid, schid;
    int score;
    cin >> stuid >> score >> schid;
    for(int j = 0; j < schid.length(); j++){
      if(isupper(schid[j])) schid[j] = tolower(schid[j]);
    }
    if(maps.find(schid) == maps.end()){
      maps[schid] = ++ cnt;
      sch.id = schid;
      ans.push_back(sch);
    }
    ans[maps[schid]].stunum++;
    if(stuid[0] == 'T') ans[maps[schid]].t += score;
    else if(stuid[0] == 'A') ans[maps[schid]].a += score;
    else if(stuid[0] == 'B') ans[maps[schid]].b += score;
  }
  for(int i = 0; i < ans.size(); i++){
    ans[i].sum = (int)(1.0 * ans[i].b / 1.5 + ans[i].a + 1.5 * ans[i].t);
  }
  sort(ans.begin(), ans.end(), cmp);
  printf("%d\n", ans.size());
  for(int i = 0, rank = 0; i < ans.size(); i++){
    if(i > 0 && ans[i].sum != ans[i - 1].sum) rank = i;
    cout << rank + 1 << " " << ans[i].id;
    printf(" %d %d\n", ans[i].sum, ans[i].stunum);
  }
  return 0;
}
