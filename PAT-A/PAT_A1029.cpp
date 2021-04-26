#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//A1029 Median
const int maxn = 1000010;
const int INF = 0x7fffffff;
long int n1, n2, temp;
queue<int> s1, s2;
int main() {
    scanf("%ld", &n1);
    for(int i = 0; i < n1; i++){
      scanf("%ld", &temp);
      s1.push(temp);
    }
    s1.push(INF);
    scanf("%ld", &n2);
    long int mid = (n1 + n2 - 1) / 2, cnt = 0;
    for(int i = 0; i < n2; i++){
      scanf("%ld", &temp);
      s2.push(temp);
      if(cnt == mid){
        printf("%d\n", min(s1.front(), s2.front()));
        return 0;
      }
      if(s1.front() < s2.front()){
        s1.pop();
      }else s2.pop();
      cnt++;
    }
    s2.push(INF);
    while(cnt++ < mid){
      if(s1.front() < s2.front()) s1.pop();
      else s2.pop();
    }
    long int ans = 0;
    ans = min(s1.front(), s2.front());
    printf("%ld\n", ans);
    return 0;
}
