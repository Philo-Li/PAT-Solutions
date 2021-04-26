#include <cstdio>
int main(){
  int N, id_win, len_win = 10000, id_lose, len_lose = 0;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int id, x, y, len;
    scanf("%d %d %d", &id, &x, &y);
    len = x * x + y * y;
    if(len > len_lose){
      len_lose = len;
      id_lose = id;
    }
    if(len < len_win){
      len_win = len;
      id_win = id;
    }
  }
  printf("%04d %04d\n", id_win, id_lose);
}
