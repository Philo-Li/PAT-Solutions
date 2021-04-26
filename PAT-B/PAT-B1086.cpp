# include <algorithm>
# include <iostream>
# include <string>
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  string c = to_string(a * b);
  reverse(c.begin(), c.end());
  while(c.front() == '0'){
    c.erase(c.begin());
  }
  cout << c;
  return 0;
}
// 注意
// 反转后不输出前导零
