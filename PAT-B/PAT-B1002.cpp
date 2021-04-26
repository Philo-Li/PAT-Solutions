#include <iostream>
#include <string>
using namespace std;
int main(){
  string str[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  int n = 0, num[101] = {0}, i = 0;
  string s;
  getline(cin, s); // 输入字符串类型变量
  for(int i = 0; i < s.length(); i++){
    n += (int)(s[i] - '0'); //字符转换为数字
  }
  while(n > 0){
    num[i++] = n % 10;
    n /= 10;
  }
  for(int j = i - 1; j >= 0; j--){ //倒序输出
    cout << str[num[j]];  // 序号存放在num数组中
    if(j != 0) printf(" "); // 注意末尾没有空格
  }
  return 0;
}
