#include <iostream>
#include <string>
using namespace std;
int main(){
  int hashtable[256] = {0}, r = 0, l = 0;
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  for(int i = 0; i < s1.length(); i++){
    hashtable[(int)s1[i]]++;
  }
  for(int i = 0; i < s2.length(); i++){
    if(hashtable[(int)s2[i]] > 0) hashtable[(int)s2[i]]--;
    else l++;
  }
  for(int i = 0; i < 256; i++) r += hashtable[i];
  if(l > 0) cout << "No " << l << endl;
  else cout << "Yes " << r << endl;
  return 0;
}
