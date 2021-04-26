#include <string>
#include <iostream>
using namespace std;
int main(){
  string num;
  cin >> num;
  while(num.length() < 3) num = '0' + num; //字符串补上前导零，统一长度
  for(int i = 0; i < num.length(); i++){
    int j = (int)(num[i] - '0'); //类型转换成数字
    for(int k = 1; k <= j; k++){
      if(i == 2) cout << k;
      else cout << (i == 0 ? 'B' : 'S');// if(i == 0) cout << 'B'; if(i == 1) cout << 'S';
    }
  }
  return 0;
}
// 字符串拼接
// num = '0' + num;
