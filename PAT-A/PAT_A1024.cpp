#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//A1024 Palindromic Number
//一定要用大整数相加，否则会溢出
bool isPalin(string temp){
  int i = 0, j = temp.length() - 1;
  while(i < j){
    if(temp[i] != temp[j]) return false;
    i++; j--;
  }
  return true;
}
string n, rn;
int main(){
  int step = 0, k;
  cin >> n >> k;
  while(isPalin(n) == false && step < k){
    int len = n.length(), r = 0;
    rn = n;
    reverse(n.begin(), n.end());
    // cout << n << "*" << rn << '\n';
    for(int i = 0; i < len; i++){
      int sum = (int)(rn[i]-'0' + n[i]-'0' + r);
      n[i] = '0' + sum % 10;
      r = sum / 10;
    }
    if(r != 0) n+= '1';
    // cout << n << "*" << rn << '\n';
    step++;
  }
  if(!isPalin(n)){ reverse(n.begin(), n.end()); }
  cout << n;
  printf("\n%d\n", step);
  return 0;
}
// int main(){
//   char n[100], rn[100], temp[100];
//   int step = 0, k;
//   cin >> n >> k;
//   while(isPalin(n) == false && step < k){
//     //n = n + rn;
//     int len = strlen(n), cnt = 0, r = 0;
//     for(int i = 0; i < len; i++){
//       rn[i] = n[len - i - 1];
//     }
//     rn[len] = '\0';
//     // printf("n:%s rn:%s len:%d\n", n, rn, len);
//     for(int i = len - 1; i >= 0; i--){
//       int sum = (int)(rn[i]-'0' + n[i]-'0' + r);
//       temp[cnt++] = '0' + sum % 10;
//       r = sum / 10;
//       // printf("n[%d]:%c rn[%d]:%c sum:%d r:%d\n",i,n[i],i,rn[i],sum, r);
//     }
//     if(r != 0) temp[cnt++] = '0' + r;
//     temp[cnt] = '\0';
//     strcpy(n, temp);
//     // printf("n:%s rn:%s\n", n, rn);
//     step++;
//   }
//   if(isPalin(n)) printf("%s", n);
//   else{
//     for(int i = strlen(n) - 1; i >= 0; i--) printf("%c", n[i]);
//   }
//   printf("\n%d\n", step);
//   return 0;
// }
