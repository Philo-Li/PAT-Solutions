#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  string A;
  cin >> A;
  int cnt = 0;
  while(cnt < 10){
    string B = A, C;
    reverse(B.begin(), B.end());
    if(B == A){
      cout << A << " is a palindromic number." << endl;
      break;
    }
    int r = 0;
    for(int i = 0; i < A.length(); i++){
      int temp = r + (int)(A[i] + B[i] - 2 * '0');
      C += to_string(temp % 10);
      r = temp / 10;
    }
    if(r != 0) C += to_string(r);
    string RC = C;
    reverse(C.begin(), C.end());
    cout << A + " + " + B + " = " + C << endl;
    if(C == RC){
      cout << C + " is a palindromic number." << endl;
      break;
    }else if(cnt + 1 == 10){
      cout << "Not found in 10 iterations." << endl;
    }
    A = C;
    cnt++;
  }
  return 0;
}
