#include <iostream>
#include <string>
using namespace std;
int main(){
  int left_P = 0, right_T = 0;
  long long ans = 0;
  string S;
  getline(cin, S);
  for(int i = 0; i < S.length(); i++){ if(S[i] == 'T') right_T++; }
  for(int i = 0; i < S.length(); i++){
    if(S[i] == 'P') left_P++;
    if(S[i] == 'T') right_T--;
    if(S[i] == 'A') ans = (ans + left_P * right_T) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
