#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int N, M, num[110];
  cin >> N >> M;
  M = M % N;
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
  reverse(num, num + N - M);
  reverse(num + N - M, num + N);
  reverse(num, num + N);
  for(int i = 0; i < N; i++){
    cout << num[i];
    if(i != N - 1) cout << ' ';
  }
  return 0;
}

//易错
//当 M 大于 N 时，只要对 M 取余结果是一样的
//M = M % N;

// 数组原地平移，可以用分别逆转不同区域的数组，最后全部逆转
