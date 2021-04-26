#include <cstdio>
int main(){
  int c1, c2, s;
  scanf("%d %d", &c1, &c2);
  s = (c2 - c1 + 50) / 100;
  printf("%02d:%02d:%02d\n", s / 3600, s / 60 % 60, s % 60);
  return 0;
}
// 易错
// 格式化输出，2位
