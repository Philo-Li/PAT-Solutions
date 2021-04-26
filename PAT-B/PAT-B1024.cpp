#include <iostream>
#include <string>
using namespace std;
int main(){
  string s, v_num, ans, temp;
  int exp, i = 0;
  cin >> s;
  if(s[0] == '-') cout << s[0];
  v_num += s[1];
  s.erase(s.begin(), s.begin() + 3);
  while(s[0] != 'E'){
    v_num += s[0];
    s.erase(s.begin());
  }
  s.erase(s.begin());
  exp = stoi(s);
  if(exp < 0){//指数小于零
    while(i++ < -exp) temp += '0';
    ans = temp + v_num;
    ans.insert(ans.begin() + 1, '.');
  }else{//指数大于零
    if(exp >= v_num.length() - 1){//指数比小数的有效数字位数大
      while(i++ < exp - v_num.length() + 1) temp += '0';
      ans = v_num + temp;
    }else{//指数比小数部分的有效数字小
      ans = v_num;
      ans.insert(ans.begin() + exp + 1, '.');
    }
  }
  cout << ans << endl;
  return 0;
}
