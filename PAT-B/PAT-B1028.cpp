#include <cstdio>
#include <cstring>
struct person{
  char name[10];
  int y, m, d;
}old, young, temp;
bool isvalid(person a){
  if(a.y < 1814 || a.y > 2014) return false;
  else if((a.y == 1814 && a.m < 9) || (a.y == 2014 && a.m > 9))return false;
  else if((a.y == 1814 && a.m == 9 && a.d < 6) || (a.y == 2014 && a.m == 9 && a.d > 6)) return false;
  else return true;
}
bool cmp(person a, person b){
  if(a.y != b.y) return a.y < b.y;
  else if(a.m != b.m) return a.m < b.m;
  else return a.d < b.d;
}
int main(){
  int N, cnt = 0;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%s %d/%d/%d", &temp.name, &temp.y, &temp.m, &temp.d);
    if(isvalid(temp) == true){// 过滤不合理的记录
      if(cnt == 0) old = young = temp;
      if(cmp(old, temp) == false) old = temp;// 比较大小
      if(cmp(young, temp) == true) young = temp;
      cnt++;
    }
  }
  if(cnt == 0) printf("0\n");
  else printf("%d %s %s\n", cnt, old.name, young.name);
  return 0;
}

// 用排序会超时，出现段错误
// cnt = 0 时应当正确输出结果
// B1028 人口普查
// https://pintia.cn/problem-sets/994805260223102976/problems/994805293282607104
