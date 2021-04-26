#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
int main(){
  int N, x;
  map<int, int> h;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    scanf("%d", &x);
    h[abs(x - i)]++;
  }
  for(auto it = h.rbegin(); it != h.rend(); it++){
    if((it->second) > 1) printf("%d %d\n", it->first, it->second);
  }
  return 0;
}
