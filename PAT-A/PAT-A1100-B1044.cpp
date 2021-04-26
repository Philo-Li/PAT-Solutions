#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main(){
  int N;
  string s, l1[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
  string l2[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
  cin >> N;
  getchar();
  for(int i = 0; i < N; i++){
    getline(cin, s);
    if(isdigit(s[0])){ // 为地球数字
      int num = stoi(s);
      int a = num / 13, b = num % 13;
      if(a == 0) cout << l1[b] << endl; //小于 13
      else if(b == 0) cout << l2[a] << endl; // 为 13 的倍数
      else cout << l2[a] + ' ' + l1[b] << endl; // 其他
    }else{   // 为火星数字
      string s1, s2;
      int i = 0, j = 0, ans;
      s1 = s.substr(0, 3);
      if(s.length() == 4) ans = 0; // 为 0
      else if(s.length() <= 3){ // 小于 13 或为 13 的倍数
        while(j < 13 && l1[j] != s1) j++;
        while(i < 13 && l2[i] != s1) i++;
        ans = (i == 13) ? j : i * 13;
      }else{ // 其他
        s2 = s.substr(4, 3);
        while(i < 13 && l2[i] != s1) i++;
        while(j < 13 && l1[j] != s2) j++;
        ans = i * 13 + j;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
