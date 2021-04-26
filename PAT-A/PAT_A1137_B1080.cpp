#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
//A1137_B1080 Final Grading MOOC期终成绩
struct Student{
  string name;
  int gp = 0, gm = -1, gf = 0, g = 0;
}newstu;
vector<Student> stu, ans;
map<string, int> st;
bool cmp(Student a, Student b){
  if(a.g == b.g) return a.name < b.name;
  else return a.g > b.g;
}
int main() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  string id;
  int score, i, cnt = -1;
  for(i = 0; i < n1 + n2 + n3; i++){
    cin >> id >> score;
    if(st.find(id) == st.end()){
      newstu.name = id;
      stu.push_back(newstu);
      st[id] = ++cnt;
    }
    if(i < n1) stu[st[id]].gp += score;
    else if(i < n1 + n2) stu[st[id]].gm = score;
    else stu[st[id]].gf = score;
  }
  for(int i = 0; i <= cnt; i++){
    if(stu[i].gp >= 200){
      stu[i].g = (stu[i].gm > stu[i].gf) ? (int)((stu[i].gm * 4 + stu[i].gf * 6 + 5)/10) : stu[i].gf;
      if(stu[i].g >= 60) ans.push_back(stu[i]);
    }
  }
  sort(ans.begin(), ans.begin() + ans.size(), cmp);
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i].name;
    printf(" %d %d %d %d\n", ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
  }
  return 0;
}
