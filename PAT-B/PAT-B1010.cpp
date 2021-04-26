#include <cstdio>
using namespace std;
int main(){
  int a, b, S[1010][2], cnt = 0, print = 0;
  while(scanf("%d %d", &a, &b) != EOF){
    S[cnt][0] = a * b;
    S[cnt][1] = b - 1;
    cnt ++;
  }
  for(int i = 0; i < cnt; i++){
    if(S[i][1] >= 0){
      if(i != 0) printf(" ");
      printf("%d %d", S[i][0], S[i][1]);
      print++;
    }
  }
  if(print == 0) printf("0 0");
  return 0;
}

// 易错
// 不要忽略输出为（0，0）的情况
// 结尾没有空格
