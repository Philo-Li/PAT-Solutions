#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
// A 1083 List Grades
struct Student{
    char name[12];
    char id[12];
    int grade;
}stu[100010];
int N;
bool cmp(Student a, Student b){
    return a.grade > b.grade;
}
int main(){
    int grade1, grade2;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    sort(stu, stu + N, cmp);
    scanf("%d %d", &grade1, &grade2);
    int flag = false;
    for(int i = 0; i < N; i++){
        if(stu[i].grade >= grade1 && stu[i].grade <= grade2){
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = true;
        }
    }
    if(!flag) printf("NONE\n");
    system("pause");
    return 0;
}

