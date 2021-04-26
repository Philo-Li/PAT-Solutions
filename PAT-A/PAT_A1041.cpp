#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
//A1041 Be Unique

int main(){
    int n, bets[10010] = {0}, bet[100010];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &bet[i]);
      bets[bet[i]]++;
    }
    bool flag = false;
    for(int i = 0; i < n; i++){
      if(bets[bet[i]] == 1){
        printf("%d\n", bet[i]);
        flag = true;
        break;
      }
    }
    if(!flag) printf("None\n");
    return 0;
}
