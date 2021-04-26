#include <cstdio>
int main(){
  int A_lose = 0, B_lose = 0, N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int A1, A2, B1, B2;
    int A_win = 0, B_win = 0;
    scanf("%d %d %d %d", &A1, &A2, &B1, &B2);
    if(A2 == A1 + B1) A_win = 1;
    if(B2 == A1 + B1) B_win = 1;
    if(A_win == 1 && B_win == 0) B_lose++;
    if(A_win == 0 && B_win == 1) A_lose++;
  }
  printf("%d %d\n", A_lose, B_lose);
  return 0;
}
