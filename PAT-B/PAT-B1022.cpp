#include <iostream>
using namespace std;
int main(){
  int A, B, D, ans[50] = {0}, cnt = 0;
  cin >> A >> B >> D;
  A = A + B;
  while(A > 0){
    ans[cnt++] = A % D;
    A = A / D;
  }
  if(cnt == 0) cout << ans[0];
  else{
    for(int i = cnt - 1; i >= 0; i--){
      cout << ans[i];
    }
  }
  return 0;
}
