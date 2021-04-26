#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
// A 1075 PAT Judge

struct Student{
    int id;
    int score[6];
    bool flag;
    int score_all;
    int solve;
}stu[10010];
int full[6];
bool cmp(Student a, Student b){
    if(a.score_all != b.score_all) return a.score_all > b.score_all;
    else if(a.solve != b.solve) return a.solve > b.solve;
    else return a.id < b.id;
}
int N, K, M;
void init(){
    for(int i = 1; i <= N; i++){
        stu[i].id = i;
        stu[i].score_all = 0;
        stu[i].solve = 0;
        stu[i].flag = false;
        memset(stu[i].score, -1, sizeof(stu[i].score));
    }
}
int main(){
    scanf("%d %d %d", &N, &K, &M);
    init ();
    for(int i = 1; i <= K; i++){
        scanf("%d", &full[i]);
    }
    int id, num, score;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &id, &num, &score);
        if(score != -1) stu[id].flag = true; //if at least 1 program passed
        if(score == -1 && stu[id].score[num] == -1){
            stu[id].score[num] = 0;
        }
        if(score == full[num] && stu[id].score[num] < full[num]){
            stu[id].solve++;//perfect solve
        }
        if(score > stu[id].score[num]) stu[id].score[num] = score;//higher score
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(stu[i].score[j] != -1){//calculate the total score
                stu[i].score_all += stu[i].score[j];
            }
        }
    }
    sort(stu + 1, stu + N + 1, cmp);
    int r = 1;
    for(int i = 1; i <= N && stu[i].flag == true; i++){
        if(i > 1 && stu[i].score_all != stu[i - 1].score_all){
            r = i;
        }
        printf("%d %05d %d", r, stu[i].id, stu[i].score_all);
        for(int j = 1; j <= K; j++){
            if(stu[i].score[j] == -1){
                printf(" -");//not passed 
            }
            else printf(" %d", stu[i].score[j]);//passed
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

