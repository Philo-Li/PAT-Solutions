#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//A1047 Course List for Student
const int maxn = 40010;
const int maxc = 2510;
char name[maxn][5];
bool cmp(int a, int b){
  return strcmp(name[a], name[b]) < 0;
}
int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  vector < int > course[k];
  for(int i = 0; i < n; i++){
    int num;
    scanf("%s %d", &name[i], &num);
    // id = getid(name);
    for(int j = 0; j < num; j++){
      int index;
      scanf("%d", &index);
      course[index - 1].push_back(i);
    }
  }
  for(int i = 0; i < k; i++){
    int num = course[i].size();
    printf("%d %d\n", i + 1, num);
    sort(course[i].begin(), course[i].end(), cmp);
    for(int j = 0; j < num; j++){
      printf("%s\n", name[course[i][j]]);
    }
  }
  return 0;
}
