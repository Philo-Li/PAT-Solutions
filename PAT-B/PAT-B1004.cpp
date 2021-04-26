#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct stu{
  string name, id;
  int score;
  stu(){} //可以直接利用指定参数新建一个结构体变量
  stu(string _name, string _id, int _score):name(_name), id(_id), score(_score){}
}S[1000];
bool cmp(stu a, stu b){
  return a.score > b.score;
}
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int score;
    string name, id;
    cin >> name >> id >> score;
    S[i] = stu(name, id, score);
  }
  sort(S, S + n, cmp);
  cout << S[0].name << ' ' << S[0].id << endl;
  cout << S[n - 1].name << ' ' << S[n - 1].id << endl;
  return 0;
}
// 用结构体存储记录，再用一个排序
// 定义一个结构体
// struct stu{
//   string name, id;
//   int score;
//   stu(){} // 可以直接利用指定参数新建一个结构体变量
//   stu(string _name, string _id, int _score):name(_name), id(_id), score(_score){}
// }S[1000];
// 排序函数
// sort(S, S + n, cmp);
// 比较函数，按关键字 score 对数组从大到小排序
// bool cmp(stu a, stu b){
//   return a.score > b.score;
// }
