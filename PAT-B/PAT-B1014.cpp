#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;
int main(){
  string str[4];
  string DAY[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  for(int i = 0; i < 4; i++){
    getline(cin, str[i]);
  }
  for(int i = 0, cnt = 0; i < str[0].length() && i < str[1].length(); i++){
    if(str[0][i] == str[1][i]){
      char temp = str[0][i];
      if(cnt == 0 && temp >= 'A' && temp <= 'G'){
        cout << DAY[(str[0][i] - 'A')] << ' '; //星期
        cnt++;
      }else if(cnt == 1){ //小时
        if(isdigit(temp)){
          cout << '0' << (int)(temp - '0'); break;
        }else if('A' <= temp && temp <= 'N' ){
          cout << (int)(temp - 'A' + 10); break;
        }
      }
    }
  }
  for(int i = 0; i < str[2].length() && i < str[3].length(); i++){
    if(str[2][i] == str[3][i] && isalpha(str[2][i])){
      printf(":%02d\n", i);//分钟
      break;
    }
  }
  return 0;
}

// 注意范围
// 星期是大写的 A-G；小时是从 0-9，A-N；
// 输出的小时和分钟，不满两位要补前导零
