#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//A1085_B1030 Perfect Sequence
const int maxn = 100010;
int seq[maxn];
int n;
long long p;
int main(){
    scanf("%d %lld", &n, &p);
    for(int i = 0; i < n; i++){
      scanf("%d", &seq[i]);
    }
    sort(seq, seq + n);
    int ans = 1;
    for(int i = 0; i < n; i++){
      int j = upper_bound(seq + i + 1, seq + n, (long long)seq[i] * p) - seq;
      ans = max(ans, j - i);
    }
    // another answer
    // int i = 0, j = 0;
    // while(i < n && j < n){
    //   while(j < n && seq[j] <= (long long )seq[i] * p){
    //     ans = max(ans, j - i + 1);
    //     j++;
    //   }
    //   i++;
    // }
    printf("%d\n", ans);
    return 0;
}
