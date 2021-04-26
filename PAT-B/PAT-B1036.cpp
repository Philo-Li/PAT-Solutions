#include <cstdio>
int main(){
  int N;
  char c;
  scanf("%d %c", &N, &c);
  int r = (N + 1) / 2;
  for(int i = 0; i < r; i++){
    if(i == 0 || i == r - 1){
      for(int j = 0; j < N; j++) printf("%c", c);
    }else{
      for(int j = 0; j < N; j++){
        if(j == 0 || j == N - 1) printf("%c", c);
        else printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
