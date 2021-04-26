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
//A1069_B1019  The Black Hole of Numbers

const int maxn = 100010;
int n, s[4];
string str;
void strtoint(int temp){
  s[0] = temp % 10;
  s[1] = ( temp / 10 ) % 10;
  s[2] = (temp / 100) % 10;
  s[3] = temp / 1000;
}
int main() {
  int last = -1 , cnt = 0, a, b, temp;
  scanf("%d", &temp);
  do{
    if(cnt != 0) temp = a - b;
    strtoint(temp);
    sort(s, s+4);
    if(cnt != 0)last = a - b;
    a = s[0] + s[1] * 10 + s[2] * 100 + s[3] * 1000;
    b = s[3] + s[2] * 10 + s[1] * 100 + s[0] * 1000;
    if(last != a - b) printf("%04d - %04d = %04d\n", a, b, a - b);
    cnt++;
  }while(a - b != last);
  return 0;
}
