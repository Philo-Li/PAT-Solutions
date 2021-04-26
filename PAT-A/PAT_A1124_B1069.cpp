#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;
//A1124_B1069 Raffle for Weibo FollowersB1069 微博转发抽奖
int main() {
  int m, n, s, flag = 0;
  string temp;
  map<string, int> h;
  scanf("%d%d%d", &m, &n, &s);
  int next = s;
  for(int i = 1; i <= m; i++){
    cin >> temp;
    if(i == next){
      if(h.find(temp) == h.end()){
        h[temp] = 1;
        cout << temp << endl;
        next += n;
        flag = 1;
      } else next++;
    }
  }
  if(flag == 0) printf("Keep going...\n");
  return 0;
}
