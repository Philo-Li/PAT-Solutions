#include <cstdio>
bool isprime(int x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) return false;
  }
  return true;
}
int main(){
  int N, K, R[10010], check[10010] = {0}, id;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    scanf("%d", &id);
    R[id] = i;
  }
  scanf("%d", &K);
  for(int i = 0; i < K; i++){
    scanf("%d", &id);
    printf("%04d: ", id);
    if(check[id] == 0){
      if(R[id] >= 1 && R[id] <= N){
        if(R[id] == 1) printf("Mystery Award\n");
        else if(isprime(R[id])) printf("Minion\n");
        else printf("Chocolate\n");
        check[id] = 1;
      }else printf("Are you kidding?\n");
    }else printf("Checked\n");
  }
  return 0;
}
