#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
  string list[3][20], s;
  int N, len[3] = {0};
  for(int i = 0, j = 0, cnt = 0; i < 3; i++, j = 0, cnt = 0){
    getline(cin, s);
    while(j < s.length()){
      if(s[j++] == '['){
        while(j < s.length() && s[j] != ']') list[i][cnt] += s[j++];
        cnt++;
      }
    }
    len[i] = cnt;
  }
  cin >> N;
  for(int i = 0; i < N; i++){
    int valid = 0, x1, x2, x3, x4, x5;
    scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5);
    if(x1 >= 1 && x2 >= 1 && x3 >= 1 && x4 >= 1 && x5 >= 1){
      if(x1 <= len[0] && x2 <= len[1] && x3 <= len[2] && x4 <= len[1] && x5 <= len[0]) valid = 1;
    }
    if(valid) cout << list[0][x1-1] << '(' << list[1][x2-1] << list[2][x3-1] << list[1][x4-1] << ')' << list[0][x5-1] << endl;
    else cout << "Are you kidding me? @\\/@" << endl;
  }
  return 0;
}
