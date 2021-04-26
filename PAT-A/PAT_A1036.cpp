#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//A1036 Boys vs Girls -2ed
struct Stu{
  string name, id;
  int grade;
};
bool cmp1(Stu a, Stu b){ return a.grade > b.grade; }
bool cmp2(Stu a, Stu b){ return a.grade < b.grade; }
int main() {
  int n, score;
  string gender, name, id;
  vector<Stu> Male, Female;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    cin >> name >> gender >> id >> score;
    if(gender == "M") Male.push_back(Stu{name, id, score});
    else if(gender == "F") Female.push_back(Stu{name, id, score});
  }
  sort(Male.begin(), Male.end(), cmp2);
  sort(Female.begin(), Female.end(), cmp1);
  if(Female.size() == 0) printf("Absent\n");
  else cout << Female[0].name << " " << Female[0].id << endl;
  if(Male.size() == 0) printf("Absent\n");
  else cout << Male[0].name << " " << Male[0].id << endl;
  if(Female.size() == 0 || Male.size() == 0) printf("NA\n");
  else printf("%d\n", Female[0].grade - Male[0].grade);
  return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// struct student{
//     char name[11];
//     char sexual;
//     char id[11];
//     int score;
// }Stu[10001];
//
// int main(){
//     int N ,Male_lowest[2], Female_highest[2]; //Male_lowest:{id_in_Stu, Lowest_score}
//     scanf("%d", &N);
//     bool flag_male = false, flag_female = false;
//     for(int i = 0; i < N; i++){
//         scanf("%s %c %s %d", Stu[i].name, &Stu[i].sexual, Stu[i].id, &Stu[i].score);
//         if(flag_male == false && Stu[i].sexual == 'M'){
//             Male_lowest[0] = i;
//             Male_lowest[1] = Stu[i].score;
//             flag_male = true;
//         }
//         if(flag_female == false && Stu[i].sexual == 'F'){
//             Female_highest[0] = i;
//             Female_highest[1] = Stu[i].score;
//             flag_female = true;
//         }
//         if(flag_male && Stu[i].sexual == 'M'){
//             if(Male_lowest[1] > Stu[i].score){
//                 Male_lowest[0] = i;
//                 Male_lowest[1] = Stu[i].score;
//             }
//         }
//         if(flag_female && Stu[i].sexual == 'F'){
//             if(Female_highest[1] < Stu[i].score){
//                 Female_highest[0] = i;
//                 Female_highest[1] = Stu[i].score;
//             }
//         }
//
//     }
//     bool flag = 0;
//     if(flag_female == false){
//         printf("Absent\n");
//         flag = 1;
//     }
//     else printf("%s %s\n", Stu[Female_highest[0]].name, Stu[Female_highest[0]].id);
//     if(flag_male == false ){
//         if(flag == 0){
//             printf("Absent\n");
//         }
//     }
//     else printf("%s %s\n", Stu[Male_lowest[0]].name, Stu[Male_lowest[0]].id);
//     if(flag_female && flag_male) printf("%d\n", Female_highest[1] - Male_lowest[1]);
//     else printf("NA\n");
//
//     system("pause");
//     return 0;
// }
