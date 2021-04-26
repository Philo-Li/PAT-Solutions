// 能被 5 整除的数字中所有偶数的和；
// 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计
// 被 5 除后余 2 的数字的个数；
// 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
// 被 5 除后余 4 的数字中最大数字。
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main(){
  int N, x, A[5] = {0}, cnt[5] = {0}, fac = 1;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> x;
    if(x % 5 == 0 && x % 2 == 0){
      A[0] += x;
      cnt[0]++;
    }
    if(x % 5 != 0){
      cnt[x % 5]++;
      if(x % 5 == 1){
        A[1] = A[1] + fac * x;
        fac = -fac;
      }
      else if(x % 5 == 2){
        A[2]++;
      }
      else if(x % 5 == 3){
        A[3] += x;
      }
      else if(x % 5 == 4){
        A[4] = (A[4] < x ? x : A[4]);
      }
    }
  }
  for(int i = 0; i < 5; i++){
    if(i != 0) printf(" ");
    if(cnt[i] == 0) printf("N");
    else{
      if(i == 3) printf("%.1f", 1.0 * A[3] / cnt[3]);
      else printf("%d", A[i]);
    }
  }
  return 0;
}
