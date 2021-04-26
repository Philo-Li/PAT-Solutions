#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int main(){
  int N, S[100010], Left_max[100010], Right_min[100010];
  set <int> ans;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){ // 获得左边最大数的序列
    scanf("%d", &S[i]);
    if(i == 0) Left_max[0] = S[0];
    else Left_max[i] = max(Left_max[i - 1], S[i - 1]);
  }
  for(int i = N - 1; i >= 0; i--){ //获得右边最小数的序列
    if(i == N - 1) Right_min[i] = S[i];
    else Right_min[i] = min(Right_min[i + 1], S[i + 1]);
  }
  for(int i = 0; i < N; i++){ // 判断是否可能为主元
    if(S[i] >= Left_max[i] && S[i] <= Right_min[i]) ans.insert(S[i]);
  }
  printf("%d\n", ans.size());
  for(auto it = ans.begin(); it != ans.end(); it++){
    if(it != ans.begin()) printf(" ");
    printf("%d", *it);
  }
  printf("\n"); // 不能少，否则会有格式错误
  return 0;
}
