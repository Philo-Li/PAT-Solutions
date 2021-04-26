#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
struct problem{
  int score, cnt[6] = {0};
  set<char> ans;
}P[110];
int main(){
  int N, M, t, k, maxnum = 0;
  char c;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++){
    scanf("%d %d %d", &P[i].score, &t, &k);
    for(int j = 0; j < k; j++){
      scanf(" %c", &c);
      P[i].ans.insert(c); // 记录正确答案
    }
  }
  for(int i = 0; i < N; i++){
    double score = 0.0;
    for(int j = 0; j < M; j++){
      bool flag = false;
      set<char> ans = P[j].ans;
      do{ scanf(" %c", &c); }while(c != '(');
      scanf("%d", &k);
      for(int p = 0; p < k; p++){
        scanf(" %c", &c);
        if(ans.find(c) == ans.end()){ // 错选
          flag = true;
          ans.insert(c); // 出错的选项
        } else ans.erase(ans.find(c));
      }
      for(auto it = ans.begin(); it != ans.end(); it++){
        int id = (int)(*it - 'a');
        P[j].cnt[id]++;
        maxnum = max(maxnum, P[j].cnt[id]);
      }
      if(flag == false){
        if(!ans.empty())score = score + 1.0 * P[j].score / 2;
        else score = score + 1.0 * P[j].score;
      }
    }
    printf("%.1lf\n", score);
  }
  if(maxnum == 0) printf("Too simple\n");
  else{
    for(int i = 0; i < M; i++){
      for(int j = 0; j < 6; j++){
        if(P[i].cnt[j] == maxnum){
          printf("%d %d-%c\n", maxnum, i+1, (char)(j + 'a'));
        }
      }
    }
  }
  return 0;
}
