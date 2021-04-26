#include <iostream>
#include <cctype>
#include <map>
#include <string>
using namespace std;
map<char, int> broken;
void count(string s, int tag){
  while(s.length() != 0){
    if(islower(s[0])) s[0] = toupper(s[0]);
    if(tag == 0) broken[s[0]]++;
    else broken[s[0]]--;
    s.erase(s.begin());
  }
}
int main(){
  string s1, s2;
  cin >> s1 >> s2;
  count(s1, 0);
  count(s2, 1);
  for(int i = 0; i < s1.length(); i++){
    if(islower(s1[i])) s1[i] = toupper(s1[i]);
    if(broken[s1[i]] > 0){
      cout << s1[i];
      broken[s1[i]] = 0;
    }
  }
  return 0;
}

// 易错
// 按照发现顺序输出坏掉的键位
// 大小写为同一个键位
