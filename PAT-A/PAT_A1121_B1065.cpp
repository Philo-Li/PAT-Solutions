#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
//A1121_B1065 单身狗
int main() {
  int n, m, id1, id2;
  map<int, int> couple;
  set<int> ans;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &id1, &id2);
    couple[id1] = id2;
    couple[id2] = id1;
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &id1);
    id2 = couple[id1];
    if(!ans.empty() && ans.find(id2) != ans.end()) ans.erase(ans.find(id2));
    else ans.insert(id1);
  }
  printf("%d\n", ans.size());
  for(auto it = ans.begin(); it != ans.end(); it++){
    if(it != ans.begin()) printf(" ");
    printf("%05d", *it);
  }
  return 0;
}
