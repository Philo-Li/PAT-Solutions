#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
struct Probelm{
  int score, cnt = 0;
  set<char> ans;
}P[105];
int main(){
  int n, m, t1, t2, max_cnt = 0;
  char d;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d %d %d", &P[i].score, &t1, &t2);
    for(int j = 0; j < t2; j++){
      scanf(" %c", &d);
      P[i].ans.insert(d);
    }
  }
  for(int i = 0; i < n; i++){
    int score = 0;
    for(int j = 0; j < m; j++){
      do{ scanf("%c", &d); }while(d != '(');
      scanf("%d", &t1);
      set<char> temp;
      for(int k = 0; k < t1; k++){
        scanf(" %c", &d);
        temp.insert(d);
      }
      if(temp == P[j].ans) score += P[j].score;//累加分数
      else P[j].cnt++; // 对错误选项进行计数
      max_cnt = max(P[j].cnt, max_cnt); //更新最大错误数
    }
    printf("%d\n", score);
  }
  if(max_cnt == 0) printf("Too simple\n");
  else{
    printf("%d", max_cnt);
    for(int i = 0; i < m; i++){
      if(P[i].cnt == max_cnt) printf(" %d", i + 1);
    }
  }
  return 0;
}
