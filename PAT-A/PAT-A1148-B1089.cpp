#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main() {
  int n, s[105];
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for(int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      vector<int> ans, id(n + 1, 1);// id 用于记录当前状态下所有人的身份
      id[i] = id[j] = -1;
      for (int k = 1; k <= n; k++) // 记录说谎的人
        if (s[k] * id[abs(s[k])] < 0) ans.push_back(k);
      if (ans.size() == 2 && id[ans[0]] + id[ans[1]] == 0){
        printf("%d %d\n", i, j);//只有两个人说谎且一个是狼人一个是好人
        return 0;
      }
    }
  }
  printf("No Solution\n");
  return 0;
}
