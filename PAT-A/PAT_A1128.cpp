#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//A1128 N Queens Puzzle
int main() {
  int n, m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int temp[1010];
    bool row[1010] = {false}, col[1010] = {false}, flag = true;
    scanf("%d", &m);
    for(int j = 1; j <= m; j++){
      scanf("%d", &temp[j]);
      if(row[temp[j]] == false) row[temp[j]] = true;
      else flag = false;
      if(col[j] == false) col[j] = true;
      else flag = false;
      for(int k = 1; k < j && flag == true; k++){
        if(abs(temp[k] - temp[j]) == abs(k - j)) flag = false;
      }
    }
    printf("%s\n", flag == true ? "YES":"NO");
  }
  return 0;
}
