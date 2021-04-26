#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
// A 1080 Graduate Admission
const int maxn = 40010;
struct Student{
    int id;
    int G_E;
    int G_I;
    int app[5];
    int Rank;
    int admit;
}stu[maxn];
struct School{
    int max;
    int num;
    int s[maxn];
    int last_rank;
}sch[100];
int n, m, k;
void init(){
    for(int i = 0; i < n; i++) {
        stu[i].id = i;
        stu[i].admit = -1;
    }
    for(int i = 0; i < m; i++){
        sch[i].num = 0;
        sch[i].last_rank = -1;
    }
}
bool cmp(Student a, Student b){
    if(a.G_E + a.G_I != b.G_E + b.G_I) return a.G_E + a.G_I > b.G_E + b.G_I;
    else return a.G_E > b.G_E;
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d", &sch[i].max);
    }
    init();
    for(int i = 0; i < n; i++){
        scanf("%d%d", &stu[i].G_E, &stu[i].G_I);
        for(int j = 0; j < k; j++){
            scanf("%d", &stu[i].app[j]);
        }
    }
    sort(stu, stu + n, cmp);
    for(int i = 0; i < n; i++){
        if(i != 0 && stu[i].G_E + stu[i].G_I == stu[i-1].G_E + stu[i-1].G_I && stu[i].G_E == stu[i-1].G_E){
            stu[i].Rank = stu[i-1].Rank;
        }//rank the student
        else stu[i].Rank = i;
        int sch_num;
        for(int j = 0; j < k && stu[i].admit == -1; j++){//check one by one
            sch_num = stu[i].app[j];
            //if school not full or full but same rank with last rank, admit it
            if(sch[sch_num].num < sch[sch_num].max || stu[i].Rank == sch[sch_num].last_rank){
                int num = sch[sch_num].num;
                sch[sch_num].s[num] = stu[i].id;
                sch[sch_num].num++;
                sch[sch_num].last_rank = stu[i].Rank;
                stu[i].admit = sch_num;
            }//else continue
        }
    }
    for(int i = 0; i < m; i++){
        sort(sch[i].s, sch[i].s + sch[i].num);
        for(int j = 0; j < sch[i].num; j++){
            if(j != 0) printf(" ");
            printf("%d", sch[i].s[j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

