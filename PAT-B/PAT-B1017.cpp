#include <string>
#include <iostream>
using namespace std;
int main(){
  string A, Q;
  int B, R = 0;
  cin >> A >> B;
  for(int i = 0; i < A.length(); i++){
    R = R * 10 + (int)(A[i] - '0');
    Q = Q + to_string(R / B);
    R = R % B;
  }
  while(Q[0] == '0' && Q.length() > 1) Q.erase(Q.begin());
  cout << Q << ' ' << to_string(R);
  return 0;
}
