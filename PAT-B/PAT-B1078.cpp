#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
  string temp, str, ans;
  char c;
  getline(cin, temp);
  getline(cin, str);
  if(temp == "C"){
    for(int i = 0; i < str.length(); i++){
      int cnt = 0;
      c = str[i];
      while(i < str.length() && str[i] == c){
        cnt++;
        i++;
      }
      if(cnt > 1) ans = ans + to_string(cnt);
      ans = ans + c;
    }
  }else{
    for(int i = 0; i < str.length(); i++){
      string cnt;
      int k = 1;
      while(isdigit(str[i])){
        cnt += str[i++];
      }
      char t = str[i];
      if(!cnt.empty()) k = stoi(cnt);
      for(int j = 0; j < k; j++) ans += t;
    }
  }
  cout << ans << endl;
  return 0;
}
