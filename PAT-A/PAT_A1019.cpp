#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//A1019 General Palindromic Number
int main(){
  int N, b, S[10001];
  scanf("%d %d", &N, &b);
  int i = 0, j = 0;
  if(N == 0){
    printf("Yes\n0");
  }
  else{
    do{//不能用字符串，因为进制超过10就会出问题，reverse之后23->32
      S[i++] = N % b;
      N /= b;
    }while(N != 0);
    for(j = 0; j < (i + 1)/2; j++){
      if(S[j] != S[i - j - 1]) break;
    }
    if(j < (i + 1) / 2) printf("No\n");
    else printf("Yes\n");
    for(int k = i - 1; k > 0; k--) {printf("%d ", S[k]); }
    printf("%d\n", S[0]);
  }
  return 0;
}
