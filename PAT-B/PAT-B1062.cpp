#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a, int b){ return b == 0 ? abs(a) : gcd(b, a % b);}
int main(){
  int n1, m1, n2, m2, K, cnt = 0;
  scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &K);
  if(n1 * m2 > n2 * m1){
    swap(n1, n2);
    swap(m1, m2);
  }
  for(int i = ceil(1.0 * n1 / m1 * K); 1.0 * i / K < 1.0 * n2 / m2; i++){
    if(gcd(i, K) == 1){
      if(cnt != 0) printf(" ");
      printf("%d/%d", i, K);
      cnt++;
    }
  }
  return 0;
}
