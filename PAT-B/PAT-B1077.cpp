#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int G1, G2 = 0;
    int max_score = 0, min_score = M, temp, cnt = 0;
    cin >> G1;
    for(int j = 0; j < N - 1; j++){
      cin >> temp;
      if(temp >= 0 && temp <= M){
        G2 += temp;
        cnt++;
        max_score = max(max_score, temp);
        min_score = min(min_score, temp);
      }
    }
    G2 = (G2 - max_score - min_score);
    cout << (int)(1.0 * G1 + G2 / (cnt - 2) + 1) / 2 << endl;
  }
  return 0;
}
