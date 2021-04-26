#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
//A1114 Family Property
struct Family{
  int numsets = 0, minid = 10000;
  bool flag = true;//是否需要打印
  double area = 0.0, ave = 0.0;
  set<int> id;
}fam;
vector<Family> F;
map<int, int> findfam;
bool cmp(Family a, Family b){
  if(abs(a.ave - b.ave) < 0.0005) return a.minid < b.minid;
  else return a.ave > b.ave;
}
void Merge(int idx1, int idx2){
  F[idx1].numsets += F[idx2].numsets;
  F[idx1].area += F[idx2].area;
  set<int> temp = F[idx2].id;
  for(auto it = temp.begin(); it != temp.end(); it++){
    findfam[*it] = idx1;
    F[idx1].id.insert(*it);
  }
  F[idx1].ave = F[idx1].area / F[idx1].id.size();
  F[idx1].minid = min(F[idx1].minid, F[idx2].minid);
  F[idx2].flag = false;
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int ID, f, m, childnum, childid, setnum;
    double area;
    vector<int> temp;
    set<int> needmerge;
    scanf("%d%d%d%d", &ID, &f, &m, &childnum);
    if(ID != -1) temp.push_back(ID);
    if(f != -1) temp.push_back(f);
    if(m != -1) temp.push_back(m);
    for(int j = 0; j < childnum; j++){
      scanf("%d", &childid);
      temp.push_back(childid);
    }
    scanf("%d%lf", &setnum, &area);
    int idx = -1;
    for(int k = 0; k < temp.size(); k++){
      if(findfam.find(temp[k])!= findfam.end()){
        idx = findfam[temp[k]];
        needmerge.insert(idx);
      }
    }
    if(idx == -1){
      idx = F.size();
      F.push_back(fam);
    }
    for(int k = 0; k < temp.size(); k++){
      findfam[temp[k]] = idx;
      F[idx].id.insert(temp[k]);
      F[idx].minid = min(F[idx].minid, temp[k]);
    }
    F[idx].numsets += setnum;
    F[idx].area += area;
    F[idx].ave = F[idx].area / F[idx].id.size();
    if(needmerge.size() >= 2){
      auto it = needmerge.begin();
      int idx1 = *it, idx2;
      while(++it != needmerge.end()){
        idx2 = *it;
        Merge(idx1, idx2);
      }
    }
  }
  sort(F.begin(), F.end(), cmp);
  map<int, bool> printed;
  int cnt = 0;
  for(int i = 0; i < F.size(); i++){
    if(F[i].flag == true) cnt++;
  }
  printf("%d\n", cnt);
  for(int i = 0; i < F.size(); i++){
    if(F[i].flag == false) continue;
    int num = F[i].id.size();
    printf("%04d %d %.3lf %.3lf\n", F[i].minid, num, 1.0 * F[i].numsets/num, F[i].ave);
  }
  return 0;
}
