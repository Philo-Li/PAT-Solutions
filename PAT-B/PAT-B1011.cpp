#include <iostream>
using namespace std;
int main(){
  long long int A, B, C, N;
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> A >> B >> C;
    cout << "Case #" << i << (A + B > C ? ": true" : ": false") << endl;
  }
  return 0;
}
