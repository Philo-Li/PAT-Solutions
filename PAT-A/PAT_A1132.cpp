#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
//A1132 Cut Integer
int main() {
  int z, a, b, n;
  string temp;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    cin >> temp;
    int k = temp.size() / 2;
    z = stoi(temp);
    a = stoi(temp.substr(0, k));
    b = stoi(temp.substr(k, k));
    if(a * b != 0 && z % (a * b) == 0) printf("Yes\n");
    else printf("No\n");
  }// a * b 不能为0，否则浮点错误
  return 0;
}
