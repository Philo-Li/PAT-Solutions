#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
//A1016 Phone Bills
struct Record{
  char name[25];
  int time[4];//time[] = {mm, dd, hh, mm}
  char online[10];//if online: "on-line" else : "off-line"
  int paired;//if paired: 1, else : 0
}record[1010];
int total_min = 0;
struct Bill{
  char name[25];
  int record_num = 0;
  int R[1000][3];//{first paried record, second paird ...}
  double amount[1000];
  double total_amount = 0.0;
}Person[1010];
bool cmp(Record a, Record b){
  if(strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
  else if(a.time[0] != b.time[0]) return a.time[0] < b.time[0];
  else if(a.time[1] != b.time[1]) return a.time[1] < b.time[1];
  else if(a.time[2] != b.time[2]) return a.time[2] < b.time[2];
  else return a.time[3] < b.time[3];
}
double calculate_amount( Record a, Record b, int Rate[]){
  int dd_a, hh_a, mm_a, dd_b, hh_b, mm_b;
  dd_a = a.time[1]; hh_a = a.time[2]; mm_a = a.time[3];
  dd_b = b.time[1]; hh_b = b.time[2]; mm_b = b.time[3];
  double amount = 0.0;
  total_min = 0;//reset total_min
  while(dd_a < dd_b || hh_a < hh_b || mm_a < mm_b){
    mm_a++;
    total_min++;
    amount = amount + Rate[hh_a];
    if(mm_a >= 60) {
      hh_a ++; mm_a = 0;
    }
    if(hh_a >= 24){ //if become next day
      hh_a = 0; dd_a++;
    }
  }
  return amount/100;
}
int main(){
  int N;
  int Rate[24];
  for(int i = 0; i < 24; i++){
      scanf("%d", &Rate[i]);
  }
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%s %d:%d:%d:%d %s", record[i].name, &record[i].time[0], &record[i].time[1], &record[i].time[2], &record[i].time[3], record[i].online);
  }
  sort(record, record + N, cmp);
  int person_num = -1;
  bool first = true;
  for(int i = 0; i < N-1; i++){
    if(strcmp(record[i].name,record[i+1].name) == 0 && strcmp(record[i].online,"on-line") == 0 && strcmp(record[i+1].online,"off-line") == 0){//find another Record to pair
      if(first) {
        strcpy(Person[0].name, record[i].name);
        first = false;
        person_num++;
        }
      if(strcmp(record[i].name, Person[person_num].name) != 0){//next person
        person_num ++;
        strcpy(Person[person_num].name, record[i].name);
      }
      int temp = Person[person_num].record_num;
      Person[person_num].R[temp][0] = i;//record the Record's number
      Person[person_num].R[temp][1] = i + 1;
      Person[person_num].record_num++; //record_num + 1
      Person[person_num].amount[temp] = calculate_amount(record[i], record[i+1], Rate);
      Person[person_num].total_amount += Person[person_num].amount[temp];
      //calculate the amount for one record
      Person[person_num].R[temp][2] = total_min;
      // printf("%s %s\n", record[i].name, record[i].online);
    }
  }
  for(int i = 0; i < person_num + 1; i++){
    int mm = record[Person[i].R[0][0]].time[0];
    printf("%s %02d\n", Person[i].name, mm);
    for(int j = 0; j < Person[i].record_num; j++){//print all record
      int r1 = Person[i].R[j][0];
      int r2 = Person[i].R[j][1];
      printf("%02d:%02d:%02d ", record[r1].time[1], record[r1].time[2], record[r1].time[3]);
      printf("%02d:%02d:%02d ", record[r2].time[1], record[r2].time[2], record[r2].time[3]);
      printf("%d $%.2lf\n", Person[i].R[j][2], Person[i].amount[j]);
    }
    printf("Total amount: $%.2lf\n", Person[i].total_amount);
  }
  return 0;
}
