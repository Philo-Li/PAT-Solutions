#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//1109 Group Photo B1055 集体照
struct Student{
  char name[10];
  int h;
}stu[10010];
bool cmp(Student a, Student b){
  if(a.h == b.h) return strcmp(a.name, b.name) < 0;
  else return a.h > b.h;
}
void putinline(int num, int pop){
  string ans[10010];//数组开小了
  int p, mid = num / 2, l, r, cnt = 0, idx;
  p = l = r = idx = mid;
  while(cnt < num){
    ans[p] = stu[cnt++ + pop].name;
    if(p == r){
      p = --l;
    }else{
      idx = p;
      p = ++r;
    }
  }
  for(int i = idx; i < idx + num; i++){
    if(i != idx) cout << " ";
    cout << ans[i];
    if(i == idx + num - 1) cout << '\n';
  }
}
int main() {
  int n, k, last, m;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%s %d", stu[i].name, &stu[i].h);
  }
  sort(stu, stu + n, cmp);
  m = n / k;
  last = min(n, m + n % m);
  int num = last, p = 0;
  do{
    putinline(num, p);
    p += num;
    num = m;
  }while(p < n);
  return 0;
}

#include <vector>
//另一种解法
int main1() {
  int n, k, m;
  string ans[110];
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%s %d", stu[i].name, &stu[i].h);
  }
  sort(stu, stu + n, cmp);
  int row = k, t = 0;
  while(row) {
      if(row == k) {
          m = n - n / k * (k - 1);
      } else {
          m = n / k;
      }
      vector<string> stemp(m);
      stemp[m / 2] = stu[t].name;
      // 左边一列
      int j = m / 2 - 1;
      for(int i = t + 1; i < t + m; i = i + 2)
          stemp[j--] = stu[i].name;
      // 右边一列
      j = m / 2 + 1;
      for(int i = t + 2; i < t + m; i = i + 2)
          stemp[j++] = stu[i].name;
      // 输出当前排
      cout << stemp[0];
      for(int i = 1; i < m; i++)
          cout << " " << stemp[i];
      cout << endl;
      t = t + m;
      row--;
  }
  return 0;
}
