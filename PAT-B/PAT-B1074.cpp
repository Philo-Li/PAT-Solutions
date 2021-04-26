#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  string D[3], ans;
  cin >> D[0] >> D[1] >> D[2];
  int len = 0, r = 0;
  for(int i = 0; i < 3; i++) len = max(len, (int)(D[i].length()));
  for(int i = 0; i < 3; i++){
    reverse(D[i].begin(), D[i].end());
    while(D[i].length() < len) D[i] += "0";
  }
  for(int i = 0; i < len; i++){
    int a = (int)(D[1][i] - '0'), b = (int)(D[2][i] - '0'), c = (int)(D[0][i] - '0');
    int d = (c == 0) ? 10 : c;
    int t = (r + a + b) % d;
    r =  (r + a + b) / d;
    ans += to_string(t);
  }
  ans += to_string(r);
  reverse(ans.begin(), ans.end());
  while(ans.length() > 1 && ans[0] == '0') ans.erase(ans.begin());
  cout << ans;
  return 0;
}
