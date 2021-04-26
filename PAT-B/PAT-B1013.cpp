#include <iostream>
using namespace std;
bool isprime(int x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) return false;
  }
  return true;
}
int main(){
  int M, N;
  cin >> M >> N;
  for(int i = 2, cnt = 0;  cnt < N; i++){
    if(isprime(i) == true){
      cnt++;
      if(cnt >= M && cnt <= N){
        if((cnt - M) % 10 != 0) cout << ' ';
        else if(cnt > M) cout << '\n';
        cout << i;
      }
    }
  }
  return 0;
}

// 注意输出的格式
