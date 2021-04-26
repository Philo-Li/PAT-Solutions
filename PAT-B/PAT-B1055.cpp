#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Stu{
  char name[20];
  int h;
}S[10010];
bool cmp(Stu a, Stu b){
  if(a.h != b.h) return a.h > b.h;
  else return strcmp(a.name, b.name) < 0;
}
int main(){
  int n, k, cnt = 0;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%s %d", &S[i].name, &S[i].h);
  sort(S, S + n, cmp);
  for(int i = 0, m, l, r; i < k; i++){
    int ans[10010] = {0};
    if(i == 0) m = n - (n / k) * (k - 1); //计算本排人数
    else m = n / k;
    r = m / 2; // 设置左右指针
    l = r - 1;
    while(r < m || l >= 0){ // 一边移动指针一边记录编号
      if(r < m) ans[r++] = cnt++;
      if(l >= 0) ans[l--] = cnt++;
    }
    for(int j = 0; j < m; j++){
      if(j != 0) printf(" ");
      printf("%s", S[ans[j]].name);
      if(j == m - 1) printf("\n");
    }
  }
  return 0;
}
