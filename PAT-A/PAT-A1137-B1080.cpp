#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
struct Student{
  string name;
  int gp = 0, gm = -1, gf = 0, g = 0;
}newstu;
vector<Student> stu, ans;
map<string, int> nametoi;
bool cmp(Student a, Student b){
  if(a.g == b.g) return a.name < b.name;
  else return a.g > b.g;
}
int main() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  string id;
  int score, i, cnt = 0;
  for(i = 0; i < n1 + n2 + n3; i++){
    cin >> id >> score;
    if(nametoi.find(id) == nametoi.end()){ // 获取序号，并记录分数
      newstu.name = id;
      stu.push_back(newstu);
      nametoi[id] = cnt++;
    }
    if(i < n1) stu[nametoi[id]].gp += score;
    else if(i < n1 + n2) stu[nametoi[id]].gm = score;
    else stu[nametoi[id]].gf = score;
  }
  for(int i = 0; i < cnt; i++){
    if(stu[i].gp >= 200){ // 计算最终成绩，并保存合格的学生
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
