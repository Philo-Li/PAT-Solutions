#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
//A1112 Stucked Keyboard
// 题目没看仔细
// 1. 输出坏掉的字符时，不能重复输出
// 2. 只要出现一个字符有不连续输出的情况，说明这个键位是好的。所以要建立一个map标记所有没坏的键位， 同时遇到这样的就把vis数组对应次数清空为0
// 3. 所以坏掉的就是那个vis[c]大于0的键位。
int main() {
  string str;
  char c;
  map<char, int> vis, print, notbroken;
  vector<char> q;
  int k;
  cin >> k >> str;
  for(int i = 0; i < str.length();i++){
    c = str[i];
    if(notbroken.find(c) == notbroken.end()){
      int j = i;
      while(j < i + k - 1 && j < str.length() && str[j] == str[i]){
        j++;
      }
      if(j == i + k - 1){
        if(vis.find(c) == vis.end()){
          vis[c] = 1;
          q.push_back(c);
        }else vis[c]++;
        i = j;
      }else{
        notbroken[c] = 1;
        vis[c] = 0;
      }
    }
  }
  for(int i = 0; i < q.size(); i++){
    c = q[i];
    if(vis.find(c) != vis.end() && vis[c] >= 1 && print.find(c) == print.end()){
      print[c] = 1;
      printf("%c", c);
    }
  }
  cout << endl;
  for(int i = 0; i < str.length(); i++){
    printf("%c", str[i]);
    if(print.find(str[i]) != print.end()){
      i = i + k - 1;
    }
  }
  return 0;
}
