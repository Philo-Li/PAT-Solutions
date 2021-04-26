#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
//A1129 Recommendation System
struct node{
  int value, cnt;
  node(int a, int b): value(a), cnt(b){}
  friend bool operator < (node a, node b){
    return (a.cnt != b.cnt) ? a.cnt > b.cnt : a.value < b.value;
  }
};
int main() {
  int n, m, temp, hashtable[50010] = {0};
  set<node> ans;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    if(ans.size() >= 1){
      printf("%d:", temp);
      int cnt = 0;
      for(auto j = ans.begin(); j != ans.end() && cnt < m; j++, cnt++){
        printf(" %d", *j);
      }
      printf("\n");
    }
    auto it = ans.find(node(temp, hashtable[temp]));
    if(it != ans.end()) ans.erase(it);
    hashtable[temp]++;
    ans.insert(node(temp, hashtable[temp]));
  }
  return 0;
}
