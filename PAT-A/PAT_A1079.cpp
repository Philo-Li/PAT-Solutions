#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
//A1079 Total Sales of Supply Chain
const int maxn = 100010;
int n, k, id, cnt = 0;
struct tree{
  double t = 0.0;
  vector<int> supply;
};
vector<tree> T;
double p, r, sum = 0.0;
void dfs(int index, int depth){//如果传送的不是index而是一个节点，会发生段错误
  if(T[index].supply.empty()){
    sum = sum + T[index].t * p * pow(1 + 0.01 * r, depth);
    return;
  }
  else{
    for(int i = 0; i < T[index].supply.size(); i++){
      // printf("%.1lf %.1lf %d %d\n", sum, T[index].t, depth, T[index].supply[i]);
      dfs(T[index].supply[i], depth + 1);
    }
  }
}
int main() {
  scanf("%d%lf%lf", &n, &p, &r);
  for(int i = 0; i < n; i++){
    tree temp;
    scanf("%d", &k);
    if(k == 0) {
      scanf("%lf", &temp.t);
    }
    else{
      for(int j = 0; j < k; j++){
        scanf("%d", &id);
        temp.supply.push_back(id);
      }
    }
    T.push_back(temp);
  }
  dfs(0, 0);
  printf("%.1lf\n", sum);
  return 0;
}
