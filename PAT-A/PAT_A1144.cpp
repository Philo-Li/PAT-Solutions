#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
//A1144 The Missing Number
int main() {
  int n, temp, maxnum = 1, ans = -1;
  map<int, bool> d;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    d[temp] = true;
    maxnum = max(maxnum, temp);
  }
  for(int i = 1; i <= maxnum; i++ ){
    if(d.find(i) == d.end()){
      ans = i; break;
    }
  }
  printf("%d\n", ans == -1 ? maxnum + 1 : ans);
  return 0;
}
