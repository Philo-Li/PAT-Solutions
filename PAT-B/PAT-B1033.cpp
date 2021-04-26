#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
int main(){
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  map<char, int> broken;
  if(s1.length() == 0) cout << s2;
  else{
    for(int i = 0; i < s1.length(); i++) broken[s1[i]] = 1;
    for(int i = 0, valid = true; i < s2.length(); i++, valid = true){
      char temp = s2[i];
      if(broken[temp] > 0) valid = false;
      else if(islower(temp) && broken[toupper(temp)] > 0) valid = false;
      else if(isupper(temp) && broken['+'] > 0) valid = false;
      if(valid) printf("%c", temp);
    }
  }
  printf("\n");
  return 0;
}
