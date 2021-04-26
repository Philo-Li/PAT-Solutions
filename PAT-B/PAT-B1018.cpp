#include <cstdio>
#include <map>
using namespace std;
char getans(int t[]){
  if(t[0] >= t[1]){
    if(t[0] >= t[2]) return 'B';
    else return 'J';
  }else return 'C';
}
int main(){
  int A_win = 0, A_lose = 0, Tie = 0, N, cnt_a[3] = {0}, cnt_b[3] ={0};
  char a, b;
  map<char, int> m;
  m['B'] = 0; m['C'] = 1; m['J'] = 2;
  scanf("%d\n", &N);
  for(int i = 0; i < N; i++){
    scanf("%c %c\n", &a, &b);
    if(a == b) Tie ++;
    else if((m[a] - m[b] + 3) % 3 == 2){
      A_win++;
      cnt_a[m[a]]++;
    }else{
      A_lose++;
      cnt_b[m[b]]++;
    }
  }
  printf("%d %d %d\n%d %d %d\n", A_win, Tie, A_lose, A_lose, Tie, A_win);
  printf("%c %c\n", getans(cnt_a), getans(cnt_b));
  return 0;
}
