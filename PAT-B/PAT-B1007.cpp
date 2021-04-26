#include <iostream>
using namespace std;
bool isprime(int x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) return false;
  }
  return true;
}
int main(){
  int N, cnt = 0;
  cin >> N;
  for(int i = 2; i <= N - 2; i++){
    if(isprime(i) && isprime(i + 2)){
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
