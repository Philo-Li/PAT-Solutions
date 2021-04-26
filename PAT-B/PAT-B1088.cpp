#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int M, X, Y;
  double A[3];
  cin >> M >> X >> Y;
  for(int i = 9; i > 0; i--){
    for(int j = 9; j >= 0; j--){
      A[0] = i * 10 + j;
      A[1] = i + j * 10;
      A[2] = 1.0 * abs(A[0] - A[1]) / X;
      if(A[1] == A[2] * Y){
        cout << A[0];
        for(int k = 0; k < 3; k++){
          if(A[k] > M) cout << " Cong";
          else if(A[k] == M) cout << " Ping";
          else cout << " Gai";
        }
        return 0;
      }
    }
  }
  cout << "No Solution" << endl;
  return 0;
}
