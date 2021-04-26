#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
//A1051 Pop Sequence
int m, n, k, temp[1001];
int main(){
  scanf("%d%d%d", &m, &n, &k);
  for(int i = 0; i < k; i++){
    stack<int> ss, print;
    for(int p = 0; p < n; p++) scanf("%d", &temp[p]);
    for(int j = 1, cnt = 0; cnt < n;){
      if(!ss.empty() && temp[cnt] == ss.top()) {
        ss.pop();
        cnt++;
      }
      else {
        ss.push(j);
        j++;
      }
      if(!ss.empty() && j - 1 == n && temp[cnt]!= ss.top()) break;
      if(ss.size() > m) break;
      // printf("\ntemp[%d] = %d\n", cnt, temp[cnt]);
      // print = ss;
      // while(!print.empty()) {
      //   printf("%d*", print.top());
      //   print.pop();
      // }
    }
    if(!ss.empty()) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}
