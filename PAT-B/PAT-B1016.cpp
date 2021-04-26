#include <string>
#include <iostream>
using namespace std;
int getans(string A, string D){
  string ans;
  for(int i = 0; i < A.length(); i++){
    if(A[i] == D[0]) ans += D[0];
  }
  return (ans == "" ? 0 : stoi(ans));
}
int main(){
  string A, B, Da, Db;
  int ans = 0;
  cin >> A >> Da >> B >> Db;
  ans += getans(A, Da);
  ans += getans(B, Db);
  cout << ans << endl;
  return 0;
}
