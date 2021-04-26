#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
//A1025 PAT Ranking
struct Student{ // student
  char id[14];
  int score;
  int final_rank;
  int location_num;
  int local_rank;
  Student(){}
  Student(int _score, int _location_num){
    int score = _score;
    int location_num = _location_num;
  }
};
bool cmp(Student a, Student b){
  if(a.score != b.score)    return a.score > b.score;
  else return strcmp(a.id, b.id) < 0;
}
int main(){
  int num_locations, num_stu = 0, K, location = 1;
  Student stu[30001];
  int cnt = 0;
  int loc_begin = 0, loc_end = 0; //for sort
  scanf("%d", &num_locations);
  for(int i = 0; i < num_locations; i++){
    scanf("%d", &K);
    num_stu += K;
    loc_begin = cnt;
    for(int j = 0; j < K; j++){ //record every student's info
      char id[14];
      int score;
      scanf("%s %d", id, &score);
      stu[cnt].score = score;
      stu[cnt].location_num = location;
      strcpy(stu[cnt].id, id);
      cnt++;
    }
    loc_end = cnt;
    sort(stu + loc_begin, stu + loc_end, cmp);
    int local_rank = 1;
    stu[loc_begin].local_rank = 1;
    for(int j = 1; j < K; j++){
      if(stu[loc_begin + j - 1].score == stu[loc_begin + j].score){
        stu[loc_begin + j].local_rank = stu[loc_begin + j - 1].local_rank;
      }
      else stu[loc_begin + j].local_rank = j + 1;
    }
    location++;
  }
  printf("%d\n", cnt);
  sort(stu, stu + cnt, cmp);
  int final_rank = 1;
  stu[0].final_rank = 1;
  for(int i = 1; i < cnt; i++){
    if(stu[i - 1].score == stu[i].score){
      stu[i].final_rank = stu[i - 1].final_rank;
    }
    else stu[i].final_rank = i + 1;
  }

  for(int i = 0; i < cnt; i++){
    printf("%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_num, stu[i].local_rank);
  }
  return 0;
}
