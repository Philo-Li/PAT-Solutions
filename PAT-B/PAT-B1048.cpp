#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  string A, B;
  char C[] = {'J', 'Q', 'K'};
  cin >> A >> B;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  while(A.length() < B.length()) A += '0';
  while(B.length() < A.length()) B += '0';
  for(int i = 0, x; i < A.length() && i < B.length(); i++){
    if((i + 1) % 2 == 0){
      x = (int)(B[i] - A[i]);
      if(x < 0) x += 10;
    }else{
      x = (int)(A[i] - '0' + B[i] - '0') % 13;
    }
    if(x < 10) B[i] = (char)(x + '0');
    else B[i] = C[x - 10];
  }
  reverse(B.begin(), B.end());
  cout << B << endl;
  return 0;
}
