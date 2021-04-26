#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
//A1139 First Contact
int n, m, k, gender[10000] = {0};
set<int> G[10000];
struct node{
  int a, b;
}temp;
bool cmp(node x, node y){
  if(x.a == y.a) return x.b < y.b;
  else return x.a < y.a;
}
int getid(string a){ return abs(stoi(a)); }
int main() {
  scanf("%d %d", &n, &m);
  string a, b;
  for(int i = 0; i < m; i++){
    getchar();
    cin >> a >> b;
    gender[getid(a)] = a.length() != 5 ? 1 : -1;
    gender[getid(b)] = b.length() != 5 ? 1 : -1;
    G[getid(a)].insert(getid(b));
    G[getid(b)].insert(getid(a));
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    vector<node> ans;
    cin >> a >> b;
    int A = getid(a), B = getid(b);
    for(auto c = G[A].begin(); c != G[A].end(); c++){//C 从A这找个同性C朋友
      if(gender[*c] != gender[A] || (*c) == B) continue;// C不能是B，D不能是A
      for(auto d = G[B].begin(); d != G[B].end(); d++){// D 从B那找个同性D朋友
        if(gender[*d] != gender[B] || (*d) == A || G[*c].find(*d) == G[*c].end()) continue;
        //C 要是不认识 D 不行
        temp.a = *c; temp.b = *d;
        ans.push_back(temp);
      }
    }
    printf("%d\n", ans.size());
    if(ans.size() != 0){
      sort(ans.begin(), ans.end(), cmp);
      for(int j = 0; j < ans.size(); j++){
        printf("%04d %04d\n", ans[j].a, ans[j].b);
      }
    }
  }
  return 0;
}
