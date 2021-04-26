#include <iostream>
#include <string>
using namespace std;
int main(){
  int N;
  string str, ans;
  cin >> N;
  for(int i = 0; i < 4 * N; i++){
    cin >> str;
    if(str[2] == 'T') ans = ans + (char)(str[0] - 'A' + 1 + '0');
  }
  cout << ans << endl;
  return 0;
}
