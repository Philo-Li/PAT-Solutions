#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
//A1067
int pos[100010], cnt = 0, n, idx = 1, ans = 0;
// idx 存放除了0存放除了0以外不在本位的最小数
//cnt记录剩余的除了零以外的不在本位的个数
// 9 0 2 1 4 3 6 5 8 7
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      int num;
      scanf("%d", &num);
      pos[num] = i; //记录每个数字所处的位置i
      if(num != i && i != 0) cnt++;
    }
    while(cnt > 0){
      if(pos[0] ==  0){ //如果零在本位，则将其与第一个不在本位的数交换
        while(idx < n){
          if(pos[idx] != idx){
            swap(pos[idx], pos[0]);
            // for(int i = 0; i < n; i++) printf("%d ", pos[i]);
            // printf("\n");
            ans++;
            break;
          }
          idx++;
        }
      }
      while(pos[0] != 0){//零不在本位，将零所处位置的对应数字的位置与零号位置交换
        swap(pos[pos[0]], pos[0]);//这样每次都能有一个数归位了
        // for(int i = 0; i < n; i++) printf("%d ", pos[i]);
        // printf("\n");
        ans++;
        cnt--;
      }
    }
    printf("%d", ans);
    return 0;
}
