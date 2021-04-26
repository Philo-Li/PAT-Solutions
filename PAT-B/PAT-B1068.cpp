#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int m, n, tol, pic[1005][1005];
map<int, int> color;
bool check(int i, int j){
  int cnt = 0, dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
  for(int k = 0; k < 8; k++){
    if(abs(pic[i][j] - pic[i + dx[k]][j + dy[k]]) > tol) cnt++;
  }
  return cnt == 8;
}
int main(){
  int ans[2], cnt = 0;
  scanf("%d %d %d", &m, &n, &tol);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      scanf("%d", &pic[i][j]);
      color[pic[i][j]]++;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(check(i, j) && color[pic[i][j]] == 1){ // 颜色唯一的点
        ans[0] = i;
        ans[1] = j;
        cnt++; // 符合条件的计数
      }
    }
  }
  if(cnt == 0) printf("Not Exist\n");
  else if(cnt > 1) printf("Not Unique\n");
  else printf("(%d, %d): %d\n", ans[1], ans[0], pic[ans[0]][ans[1]]);
  return 0;
}
