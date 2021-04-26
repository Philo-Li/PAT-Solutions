#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//A1038 Recover the Smallest Number
const int maxn = 100010;
string str[maxn];
bool cmp(string a, string b){
  return a + b < b + a;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      cin >> str[i];
    }
    sort(str, str + n, cmp);
    string ans;
    for(int i = 0; i < n; i++){
      ans += str[i];
    }
    while(ans.size() != 0 && ans[0] == '0'){
      ans.erase(ans.begin());  //除去前导零
    }
    if(ans.size() == 0) cout << 0;
    else cout << ans;

    return 0;
}
