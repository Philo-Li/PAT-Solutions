#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
//A1028 listing sort
struct Student{
  int id;
  char name[10];
  int grade;
}stu[100010];
int C;
bool cmp(Student a, Student b){
  if(C == 1) return a.id < b.id;
  if(C == 2){
    if(strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
    else return a.id < b.id;
  }
  if(C == 3){
    if(a.grade != b.grade) return a.grade < b.grade;
    else return a.id < b.id;
  }
}
int main(){
  int N;
  scanf("%d %d", &N, &C);
  for(int i = 0; i < N; i++){
    scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
  }
  sort(stu, stu + N, cmp);
  for(int i = 0; i < N; i++){
    printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
  }
  return 0;
}
