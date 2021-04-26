#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//A1023 Have Fun with Numbers
int n, r = 0, ans[25], cnt = 0, flag = 0;
int main(){
  string str;
  cin >> str;
  int len = str.length();
  for(int i = len - 1; i >= 0; i--){
    int temp = str[i] - '0';
    ans[cnt++] = (r + temp * 2) % 10;
    r = (r + temp * 2) / 10;
  }
  if(r != 0) ans[cnt++] = r;
  for(int i = cnt - 1; i >= 0; i--){
    char temp = (char)('0' + ans[i]);
    if(str.find(temp) == std::string::npos) {
      printf("No\n");
      flag = 1;
      break;
    }
    else{
      int pos = str.find(temp);
      str[pos] = '#';
    }
  }
  if(!flag) printf("Yes\n");
  for(int i = cnt - 1; i >= 0; i--){
    printf("%d", ans[i]);
  }
  return 0;
}
