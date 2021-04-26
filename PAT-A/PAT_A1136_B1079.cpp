#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//A1136_B1079 A Delayed Palindrome 延迟的回文数
int main() {
  string n, rn;
  cin >> n;
  for(int i = 0; i < 10; i++){
    string sum;
    int r = 0, temp;
    rn = n;
    reverse(rn.begin(), rn.end());
    if(rn == n){
      cout << n << " is a palindromic number." << endl;
      break;
    }
    for(int j = 0; j < n.size(); j++){
      temp = (int)(n[j] + rn[j] - 2 * '0') + r;
      sum += (char)(temp % 10 + '0');
      r = temp / 10;
    }
    if(r != 0) sum += (char)(r + '0');
    string rsum = sum;
    reverse(sum.begin(), sum.end());
    cout << n << " + " << rn << " = " << sum << endl;
    if(rsum == sum){
      cout << sum << " is a palindromic number." << endl;
      break;
    }else if(i + 1 == 10){
      cout << "Not found in 10 iterations." << endl;
    }
    n = sum;
  }
  return 0;
}
