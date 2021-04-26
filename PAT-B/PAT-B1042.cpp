#include <cstdio>
#include <cctype>
int main(){
  int max_cnt = -1, count[256] = {0};
  char temp, ans;
  while(scanf("%c", &temp) != EOF){
    if(isupper(temp)) temp = tolower(temp);
    if(isalpha(temp)) count[(int)temp]++;
  }
  for(int i = 0; i < 256; i++){
    if(max_cnt < count[i]){
      max_cnt = count[i];
      ans = (char)i;
    }
  }
  printf("%c %d\n", ans, max_cnt);
  return 0;
}
