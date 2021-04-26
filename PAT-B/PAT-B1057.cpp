#include <cstdio>
#include <cctype>
int main(){
  char x;
  int N = 0, cnt[2] = {0};
  while(scanf("%c", &x) != EOF){
    if(isalpha(x)){
      if(isupper(x)) x = tolower(x);
      N += (int)(x - 'a' + 1);
    }
  }
  while(N != 0){
    cnt[N % 2]++;
    N /= 2;
  }
  printf("%d %d\n", cnt[0], cnt[1]);
  return 0;
}
