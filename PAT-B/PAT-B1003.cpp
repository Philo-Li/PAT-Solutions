#include <string>
#include <iostream>
using namespace std;
int main(){
  int n;
  string s;
  cin >> n;
  getchar();
  for(int i = 0; i < n; i++){
    bool valid = true;
    int LeftA = 0, InsideA = 0, RightA = 0, P = 0, T = 0;
    getline(cin, s);
    for(int j = 0; j < s.length(); j++){
      if(s[j] != 'P' && s[j] != 'A' && s[j] != 'T'){
        valid = false; break;
      }
      if(s[j] == 'A'){      // 统计三个位置A的个数
        if(P == 0) LeftA++;
        else if(P == 1 && T == 0) InsideA++;
        else if(P == 1 && T == 1) RightA++;
      }else if(s[j] == 'P') P++;
      else if(s[j] == 'T') T++;
    }
    if(P != 1 || T != 1 || InsideA == 0) valid = false;  // 两个条件都满足输出“YES”
    if(RightA != LeftA * InsideA) valid = false;
    if(valid) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
