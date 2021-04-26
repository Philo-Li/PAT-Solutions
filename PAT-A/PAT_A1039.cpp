#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//A1039 Course List for Student
const int m = 26*26*26*10 + 1;
int h(char name[]){
  int id = 0;
  int len = strlen(name);
  for(int i = 0; i < len - 1; i++){
    id = id * 26 + (name[i] - 'A');
  }
  id = id * 10 + (name[len - 1] - '0');
  return id;
}
vector <int> course[m];
int main(){
  int n, k;
  char name[5];
  scanf("%d%d", &n, &k);
  for(int i = 0; i < k; i++){
    int index, num;
    scanf("%d%d",&index, &num);
    for(int j = 0; j < num; j++){
      scanf("%s", name);
      int key = h(name);
      course[key].push_back(index);
    }
  }
  for(int i = 0; i < n; i++){
    scanf("%s", name);
    int q = h(name);
    int num = course[q].size();
    printf("%s %d", name, num);
    sort(course[q].begin(), course[q].end());
    for(int j = 0; j < num; j++){
      printf(" %d", course[q][j]);
    }
    printf("\n");
  }
  return 0;
}
