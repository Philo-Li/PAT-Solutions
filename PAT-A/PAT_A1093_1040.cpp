#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//A1093 count PAT
const int maxn = 100010;
const int d = 1000000007;
string s;
int main() {
    int ans = 0, leftP[maxn] = {0}, rightT[maxn]={0};
    getline(cin, s);
    if(s[0] == 'P') leftP[0] = 1;
    for(int i = 1; i < s.length(); i++){
      if(s[i] == 'P') leftP[i] = leftP[i - 1] + 1;
      else leftP[i] = leftP[i-1];
    }
    if(s.back() == 'T') rightT[s.length()-1] = 1;
    for(int i = s.length() - 2; i > 0; i--){
      if(s[i] == 'T') rightT[i] = rightT[i + 1] + 1;
      else rightT[i] = rightT[i + 1];
      if(s[i] == 'A') ans = (ans + leftP[i] * rightT[i])%d;
    }
    printf("%d", ans);
    return 0;
}
