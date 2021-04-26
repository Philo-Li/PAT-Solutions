#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n, x, num[110];
  map<int, int> m;
  vector<int> ans;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    num[i] = x;
    while(x > 1){
      if(x % 2 == 0) x /= 2;
      else{ x = (3 * x + 1) / 2; }
      m[x] = 1; //记录运算中遇到过的数字
    }
  }
  for(int i = 0; i < n; i++){
    if(m[num[i]] != 1) ans.push_back(num[i]); //遍历原序列
  }
  sort(ans.begin(), ans.end()); // 不加参数的sort函数默认从小到大排序
  for(int i = ans.size() - 1; i >= 0; i--){ //倒序输出
    cout << ans[i];
    if(i != 0) cout << ' ';
  }
  return 0;
}
