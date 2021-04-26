#include <iostream>
using namespace std;
int main(){
  int num[10] = {0}, min_not_zero = -1;
  for(int i = 0; i < 10; i++){
    cin >> num[i];
    if(min_not_zero == -1 && i > 0 && num[i] > 0){
      min_not_zero = i;
      num[i]--;
    }
  }
  cout << min_not_zero;
  for(int i = 0; i < 10; i++){
    while(num[i]--) cout << i;
  }
  return 0;
}
