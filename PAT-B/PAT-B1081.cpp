#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main(){
  int N;
  string str;
  scanf("%d\n", &N);
  for(int i = 0; i < N; i++){
    int len = 0, hasdigit = 0, hasalpha = 0, valid = 1;
    getline(cin, str);
    if(str.length() < 6) cout << "Your password is tai duan le." << endl;
    else {
      while(!str.empty() && valid){
        if(!isalnum(str[0]) && str[0] != '.') valid = 0;
        if(isdigit(str[0])) hasdigit = 1;
        if(isalpha(str[0])) hasalpha = 1;
        str.erase(str.begin());
      }
      if(!valid) cout << "Your password is tai luan le." << endl;
      else if(hasalpha == 1 && hasdigit == 0) cout << "Your password needs shu zi." << endl;
      else if(hasalpha == 0 && hasdigit == 1) cout << "Your password needs zi mu." << endl;
      else cout << "Your password is wan mei." << endl;
    }
  }
  return 0;
}
