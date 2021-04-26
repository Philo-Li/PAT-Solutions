#include <cstdio>
int main(){
  char temp, list[] = {'P', 'A', 'T', 'e', 's', 't'};
  int cnt[6] = {0}, n = 0;
  while(scanf("%c", &temp) != EOF){
    for(int i = 0; i < 6; i++){
      if(list[i] == temp){
        cnt[i]++;
        n++;
      }
    }
  }
  while(n > 0){
    for(int i = 0; i < 6; i++){
      if(cnt[i] > 0){
        cnt[i]--;
        n--;
        printf("%c", list[i]);
      }
    }
  }
  return 0;
}
