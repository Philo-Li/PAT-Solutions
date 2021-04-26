#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
//A1071 Speech Patterns
string s, temp, ans;
map <string, int> mm;
int main(){
  char n;
  int maxn = 0;
  scanf("%c", &n);
  while(n != '\n'){
    temp.clear();
    while(isdigit(n) || isupper(n) || islower(n)){
      if(isupper(n)) n = tolower(n);
      temp += n;
      scanf("%c", &n);
    }
    if(!temp.empty()){
      mm[temp]++;
      if(maxn < mm[temp]){
        ans = temp;
        maxn = mm[temp];
      }
    }
    scanf("%c", &n);
  }
  cout << ans << ' ' << maxn <<endl;
  return 0;
}
