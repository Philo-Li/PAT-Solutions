#include <cstdio>
#include <cstring>
struct student{
  int num;
  char id[15];
}S[1010];
int main(){
  int N, k, no1, no2;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    char id[15];
    scanf("%s %d %d", id, &no1, &no2);
    S[no1].num = no2;
    strcpy(S[no1].id, id);
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    scanf("%d", &no1);
    printf("%s %d\n", S[no1].id, S[no1].num);
  }
  return 0;
}
