#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//A1060 Are They Equal
const int maxn = 101;
int n;
string a, b;
string deal(string s, int &e){
  int k = 0;
  while(s.length() > 0 && s[0] == '0') s.erase(s.begin());//去掉s的前导零
  if(s[0] == '.'){//遇到'.' 说明是小于1的数
    s.erase(s.begin());
    while(s.length() > 0 && s[0] == '0'){
      s.erase(s.begin()); e--;
    }
    if(s.empty())e = 0;//去掉前导零没了，说明是零
  }
  else{//去掉前导零还是没遇到'.' 找到小数点，并累加指数
    k = s.find('.');
    if(k != -1) {
      e = k;//找到小数点
      s.erase(s.find('.'), 1);
    }
    else e = s.length(); //没找到小数点，有可能是零，也有可能是非零整数
    // cout << s << '\n';
  }
  int cnt = 0;
  string result;
  while(cnt < n){
    if(s.length() > 0){
      result += s[0];
      s.erase(s.begin());
    }
    else result += '0';
    cnt++;
  }
  return result;
}
int main(){
  scanf("%d", &n);
  cin >> a >> b;
  int ea = 0, eb = 0;
  bool flag = false;
  string ansa = deal(a, ea);
  string ansb = deal(b, eb);
  if(ansa == ansb && ea == eb) flag = true;
  printf("%s ", flag ? "YES":"NO");
  cout << "0." << ansa << "*10^" << ea;
  if(!flag) {
    cout << " 0." << ansb << "*10^" << eb;
  }
  return 0;
}
