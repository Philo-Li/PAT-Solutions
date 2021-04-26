#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  string A, B;
  int S = -1;
  cin >> A;
  while(S != 6174 && S != 0){
    while(A.length() < 4) A += '0';
    sort(A.begin(), A.end());
    B = A;
    reverse(B.begin(), B.end());
    S = stoi(B) - stoi(A);
    printf("%04d - %04d = %04d\n", stoi(B), stoi(A), S);
    A = to_string(S);
  }
  return 0;
}
// 注意，输入的数字不一定是四位数，中间计算得到的也不一定是，所以要转换一下
